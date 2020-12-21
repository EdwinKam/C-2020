#include "io.h"
#include "unistd.h"
#include <errno.h>
#include <string.h>

static uint8_t bytebuf[4096]; // read sym
static int bytebuffindex = 0;

// read byte in the file
int read_bytes(int infile, uint8_t *buf, int to_read) {
  int bytes_read = 2; // anything just not zero to get into the while loop
  int count = to_read;
  int total = 0;
  while ((total != to_read) && (bytes_read != 0)) {
    bytes_read = read(infile, buf + total, count);

    if (bytes_read < 0) {
      printf("ERROR: %s\n", strerror(errno));
      exit(1);
    }
    total += bytes_read;
    count -= bytes_read;
  }
  inbyte += total;
  return total;
}

int write_bytes(int outfile, uint8_t *buf, int to_write) {
  //   printf("in write byte%d symcount: %d\n",to_write,outbyte);
  int bytes_write = 2;
  int count = to_write;
  int total = 0;
  while ((total != to_write && bytes_write != 0)) {
    bytes_write = write(outfile, buf + total, count);
    if (bytes_write < 0) {
      printf("ERROR: %s\n", strerror(errno));
      exit(1);
    }
    total += bytes_write;
    count -= bytes_write;
  }
  outbyte += total;
  return total;
}

void read_header(int infile, FileHeader *header) {
  read_bytes(infile, (uint8_t *)header, sizeof(FileHeader));
}

void write_header(int outfile, FileHeader *header) {
  write_bytes(outfile, (uint8_t *)header, sizeof(FileHeader));
  // write(outfile, header, sizeof(FileHeader));
}

static bool check;
static uint16_t temp = 0;

bool read_sym(int infile, uint8_t *byte) { // called once each time
  if (bytebuffindex == 0) { // load new bloack only if bytebufindex is 0
    int num_read = read_bytes(infile, bytebuf, 4096); // put a block into
                                                      // bytebuf
    // printf("io.c read sym/read_byte:%d",num_read);
    if (num_read == 4096) {
      check = true;
    } else {
      check = false;
      temp = num_read;
    }
  }
  *byte = bytebuf[bytebuffindex];
  bytebuffindex = (bytebuffindex + 1) % 4096; // bytebufindex++
  return (check ||
          bytebuffindex != temp + 1); // return whether it can read everything
}

static uint8_t pairbuf[4096]; // buff pair and read pair
static uint16_t bitcount;

// for encode
void buffer_pair(int outfile, uint16_t code, uint8_t sym,
                 uint8_t bit_len) { // for encode
  // printf("buffer pair sym: %d code: %d\n",sym,code);
  // symcount++;
  for (int i = 0; i < bit_len; i++) {

    if ((code & 1) == 1) {

      pairbuf[bitcount / 8] |= (1 << (bitcount % 8));
      // originally 00000 |= 000001, next time |=000010
    } else {
      pairbuf[bitcount / 8] &= ~(1 << (bitcount % 8));
    }
    code >>= 1;
    //      printf("buffer pair ccode after >>=: %d\n",code);
    ++bitcount;
    if (bitcount == 4096 * 8) {
      write_bytes(outfile, pairbuf, 4096);
      bitcount = 0;
    }
  }

  for (int i = 0; i < 8; i++) {
    if ((sym & 1) == 1) {
      pairbuf[bitcount / 8] |=
          (1 << (bitcount %
                 8)); // originally 00000 |= 000001, next time |=000010
    } else {
      pairbuf[bitcount / 8] &= ~(1 << (bitcount % 8));
    }
    sym >>= 1;
    ++bitcount;
    if (bitcount == 4096 * 8) {
      write_bytes(outfile, pairbuf, 4096);
      bitcount = 0;
    }
  }
}

void flush_pairs(int outfile) {
  if (bitcount != 0) {
    write_bytes(outfile, pairbuf, bit_to_byte(bitcount));
    bitcount = 0;
  }
}

// DECODE
bool read_pair(int infile, uint16_t *code, uint8_t *sym,
               uint8_t bit_len) { // if code == stop code return false
  *code = 0;
  for (int i = 0; i < bit_len; i++) {
    if (bitcount == 0) { // if bitbuf is emtpy, we read in another block
      read_bytes(infile, pairbuf, 4096);
    }
    if ((pairbuf[bitcount / 8] & (1 << bitcount % 8)) !=
        0) { // if this byte is not 0, that means this bit is not 0
      *code |= (1 << i);
      //      printf("yescode: %d\n", *code);
    } else {
      *code &= ~(1 << i);
      //      printf("nocode: %d\n", *code);
    }
    bitcount++;
    if (bitcount == 4096 * 8) {
      bitcount = 0; // reset and will byte_read() next time
    }
  }
  //   printf("read_pair code %d\n",*code);
  *sym = 0;
  for (int i = 0; i < 8; i++) {
    if (bitcount == 0) {
      read_bytes(infile, pairbuf, 4096);
    }
    if ((pairbuf[bitcount / 8] & (1 << bitcount % 8)) !=
        0) { // if this byte is not 0, that means this bit is not 0
      *sym |= (1 << i);
    } else {
      *sym &= ~(1 << i);
    }
    bitcount++;
    if (bitcount == 4096 * 8) {
      bitcount = 0; // reset and will byte_read() next time
    }
  }

  return (*code != STOP_CODE);
}

void buffer_word(int outfile, Word *w) {
  for (uint32_t i = 0; i < w->len; i++) {
    bytebuf[bytebuffindex++] = w->syms[i];
    if (bytebuffindex == 4096) {
      write_bytes(outfile, bytebuf, 4096);
      bytebuffindex = 0;
    }
  }
}

void flush_words(int outfile) {
  //    printf("fflush_word byteindex: %d",bytebuffindex);
  if (bytebuffindex != 0) {
    write_bytes(outfile, bytebuf, bytebuffindex);
    bytebuffindex = 0;
  }
}

int bit_to_byte(int bit) { // helper function to convert bit to byte
  if (bit % 8 == 0) {
    return bit / 8;
  } else {
    return bit / 8 + 1;
  }
}

void print_buffer() {
  for (int i = 0; i < 50; i++) {
    printf("buf[%d]: %d\n", i, pairbuf[i]);
  }
}

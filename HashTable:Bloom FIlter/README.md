# HatterSpeak
- This program takes user's input and determine whether those strins sare oldspeak or hatterspeak. If the user inputs any forbiddon words, they are off to dungoen. Also, if they input any oldspeak that have a hatterspeak translation, the program  print out those word and translations at the end.
## Makefile
- Make clean: clean all object, execuable files, including hatterspeak and test files.
- Make valgrind: run valgrind automically without any additionally input. Also, it will clear all execuable and object files
- Make hstest: create an execuable file for Hashtable test
- Make bftest: Create an execuable file for BloomFilter test
- Make read: Create an execuable file for read file
- Make infer: run make infer. One memory leak error because I did not deallocated memory in bv_create(), but valgrind gives no error.

## hatterspeak
- When executing this program, user would need to enter their desire Bloom Filter and hashtable size but using -f and -h flag.
- They also need to indicate whether they want to move ListNode to the front of the linked list of there is any duplicate words in the txt by using the flag -m(Move to front) or -b (back)
- Users can also look at the stat by using -s flag
- First, the program loads all word from oldspeak.txt and hatterspeak.txt to BloomFilter and Hashtable
- The program wil display the stat if -s flag is set, then the program will end without asking users input.
- If -s flag is not set, user can start entering words. If the word contains special characters like %&$, only the valid part of the word will be accepted.
- User can stop entering new word by ctrl+D.
- If the user did not enter any words that is in the oldspeak.txt or hatterspeak.txt, the program will not print anything.
- Otherwise, the program will create two Linked list and store all the forbidden words and translable words.
- A message will be printed whether the user is off to the dungoen or not.



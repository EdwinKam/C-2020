#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define EPSILON 0.0000000001 // define epilson to 10^-9
#define OPTIONS "sctea"      // define options for switch

static inline double abs(double x) {
  return x < 0 ? -x : x;
} // abs value function
// static inline double sq(double x){ return x*x;}

double Sin(double); // return double value for given input
double Cos(double);
double Tan(double);
double Exp(double);
void test_Sin(); // test, print and calculate the result of math.h and my
                 // approxiamtion
void test_Cos();
void test_Tan();
void test_Exp();

int main(int argc, char **argv) {
  int c = 0;
  bool before = false; // determine whether only one option is chosen
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    if (before) { // if before =true, thats means an option has been processed
                  // previously
      break;
    }
    switch (c) {
    case 's':
      test_Sin();
      before = true;
      break;
    case 'c':
      test_Cos();
      before = true;
      break;
    case 't':
      test_Tan();
      before = true;
      break;
    case 'e':
      test_Exp();
      before = true;
      break;

    case 'a':
      test_Sin(); // call all functions if -a
      test_Cos();
      test_Tan();
      test_Exp();
      before = true;
      break;
    default:
      printf("Invalid input\n"); // error message
      break;
    }
  }
  if (argc == 1) {
    puts("Error: no arguement supplied!"); // if no arguement
    return -1;
  }
  return 0;
}

double Sin(double x) {
  double x2 = x * x; // x2 =x^2
  double nom =
      x * ((x2 * (52785432 - 479249 * x2) - 1640635920) * x2 + 11511339840);
  double denom = ((18361 * x2 + 3177720) * x2 + 277920720) * x2 + 11511339840;
  return nom / denom;
}

double Cos(double x) {
  double x2 = x * x;
  double nom = (x2 * (1075032 - 14615 * x2) - 18471600) * x2 + 39251520;
  double denom = ((127 * x2 + 16632) * x2 + 1154160) * x2 + 39251520;
  return nom / denom;
}

double Tan(double x) {
  double x2 = x * x;
  double nom =
      x * (x2 * (x2 * (x2 * (x2 - 990) + 135135) - 4729725) + 34459425);
  double denom = 45 * (765765 + x2 * (x2 * (x2 * (x2 - 308) + 21021) - 360360));
  return nom / denom;
}
double Exp(double x) {
  double n = 1;
  double result = 1;
  double nom = 1;
  double denom = 1;

  while (abs(nom / denom) >
         EPSILON) { // if the extra term is still > than epsilon, keep looping
    nom = nom * x;  // times x each time
    denom = n * denom;             // times n each time
    result = result + nom / denom; // add new term each time
    n++;                           // inc n unless loop exited
  }

  return result; // after exit loop, return the result
}
void test_Sin() {
  printf("%s\t %2s\t  %14s\t %4s\n", "x", "Sin", "Library",
         "Difference"); // header
  printf("%s\t %2s\t  %14s\t %4s\n", "-", "---", "-------", "----------");
  double i = -2 * M_PI; // i=2pi, which is the first x value we are going to
                        // test
  uint32_t count = 0;   // we will exactly loop this 64 times with step of pi/16
  while (
      count <=
      64) { // I do this because I need to make sure it prints until its x=2pi
    printf("% 6.4lf\t% 10.8lf\t% 10.8lf\t% 12.10lf\n", i, Sin(i), sin(i),
           Sin(i) - sin(i));
    i += M_PI / 16;
    count++;
  }
}
void test_Cos() {
  printf("%s\t %2s\t  %14s\t %4s\n", "x", "Cos", "Library", "Difference");
  printf("%s\t %2s\t  %14s\t %4s\n", "-", "---", "-------", "----------");
  double i = -2 * M_PI;
  uint32_t count = 0;
  while (count <= 64) {
    printf("% 6.4lf\t% 10.8lf\t% 10.8lf\t% 12.10lf\n", i, Cos(i), cos(i),
           Cos(i) - cos(i));
    i += M_PI / 16;
    count++;
  }
}
void test_Tan() {
  printf("%s\t %2s\t  %14s\t %4s\n", "x", "Tan", "Library", "Difference");
  printf("%s\t %2s\t  %14s\t %4s\n", "-", "---", "-------", "----------");
  double i = -M_PI / 3;
  uint32_t count = 0;
  while (i <= M_PI / 3) {
    printf("% 6.4lf\t% 10.8lf\t% 10.8lf\t% 12.10lf\n", i, Tan(i), tan(i),
           Tan(i) - tan(i));
    i += M_PI / 16;
    count++;
  }
}
void test_Exp() {
  printf("%s\t %2s\t  %14s\t %4s\n", "x", "Exp", "Library", "Difference");
  printf("%s\t %2s\t  %14s\t %4s\n", "-", "---", "-------", "----------");
  double i = 0.0;
  while (i <= 9) {
    double fac = pow(10, 8); // round up the numbers to 8 decimal point
    double E = round(Exp(i) * fac) / fac;
    double e = round(exp(i) * fac) / fac;

    printf("% 6.4lf\t% 10.8lf\t% 10.8lf\t% 12.10lf\n", i, Exp(i), exp(i),
           E - e); // difference == the difference of the numbers we just
                   // rounded, so it displays the exact difference of our output
                   // value.
    i += 0.1;
  }
}

/* Pointer to Data.*/

#include <stdio.h>

int swap_ints(int *first_number, int *second_number);
int add(int, int);
int subtract( int, int);
int multiply( int, int);
void doMath( int (*fn)(int, int), int, int);

int swap_ints(int *first_number, int *second_number)
{
  int temp;

  /* temp = "what is pointed to by" first_number; etc... */
  temp = *first_number;
  *first_number = *second_number;
  *second_number = temp;

  return 0;
}


/* Pointer to Function. */

int add( int a, int b ) {
  return a + b;
}

int subtract( int a, int b ) {
  return a - b;
}

int multiply( int a, int b ) {
  return a * b;
}

void doMath( int (*fn)(int a, int b), int a, int b ) {
  int result = fn(a, b);
  printf("result = %d\n", result);
}

int main(void) {

  int a = 2;
  int b = 3;

  doMath(add, a, b);
  doMath(subtract, a, b);
  doMath(multiply, a, b);
  
  int c = 4, d = 7;

  printf("pre-swap values are: c == %d, d == %d\n", c, d);

  swap_ints(&c, &d);

  printf("post-swap values are: c == %d, d == %d\n", c, d);

  return 0;
}

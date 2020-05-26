/* Pointer to Data.*/

#include <stdio.h>

int swap_ints(int *first_number, int *second_number);

int
swap_ints(int *first_number, int *second_number)
{
  int temp;

  /* temp = "what is pointed to by" first_number; etc... */
  temp = *first_number;
  *first_number = *second_number;
  *second_number = temp;

  return 0;
}


Pointer to Function.

#include <stdio.h>

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
  
  int a = 4, b = 7;

  printf("pre-swap values are: a == %d, b == %d\n", a, b)

  swap_ints(&a, &b);

  printf("post-swap values are: a == %d, b == %d\n", a, b)

  return 0;
}

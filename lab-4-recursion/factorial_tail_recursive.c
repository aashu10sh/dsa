#include<stdio.h>

int factorial_tail_recursive(int n, int accumulator) {
  if (n == 0) {
    return accumulator;
  } else {
    return factorial_tail_recursive(n - 1, n * accumulator);
  }
}

int main() {
  int number;
  printf("Enter a non-negative integer: ");
  scanf("%d", &number);

  if (number < 0) {
    printf("Factorial is not defined for negative numbers.\n");
    return 1;
  }
  int result = factorial_tail_recursive(number, 1);
  printf("The factorial of %d is %d\n", number, result);
  return 0;
}



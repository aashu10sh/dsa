#include <stdio.h>

long long fibonacci_tail_recursive(int n, long long a, long long b) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        return fibonacci_tail_recursive(n - 1, b, a + b);
    }
}

int main() {
    
    int n;
    printf("Enter the Nth Term for Recursion : ");
    scanf("%d", &n);
    long long result = fibonacci_tail_recursive(n, 0, 1);
    printf("The %d-th term in the Fibonacci series is: %lld\n", n, result);

    return 0;
}


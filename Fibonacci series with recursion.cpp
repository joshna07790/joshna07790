#include <stdio.h>


int fibonacci(int n) {
    if (n <= 1) {
        return n; 
    }
    return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main() {
    int terms;

    
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &terms);

    
    printf("Fibonacci series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}


#include <stdio.h>

// Function declarations
void inc(int n);
void dec(int n);
void incdec(int n);
int pow(int x, int n);
int fib(int n);



int main() {
    int n = 5;
    inc(n);  // Print increasing numbers
    printf("\n");
    dec(n);  // Print decreasing numbers
    printf("\n");
    incdec(n);  // Print numbers in both increasing and decreasing order
    printf("\n");

    int x = 2;
    int p = 3;
    int result = pow(x, p);
    printf("pow(%d, %d) = %d\n", x, p, result);  // Print power calculation
    printf("\n");
    fib(n);
    
    return 0;

}

// Function to print numbers from 1 to n
void inc(int n) {
    if (n == 0) {
        return;
    } else {
        inc(n - 1);
        printf("%d ", n);
    }
}

// Function to print numbers from n to 1
void dec(int n) {
    if (n == 0) {
        return;
    } else {
        printf("%d ", n);
        dec(n - 1);
    }
}

// Function to print numbers from n to 1 and then back to n
void incdec(int n) {
    if (n == 0) {
        return;
    } else {
        printf("%d ", n);
        incdec(n - 1);
        printf("%d ", n);
    }
}

// Function to calculate power x^n using recursion
int pow(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        int d = pow(x, n - 1);
        return d * x;
    }
}
int fib (int n){
  if (n==0&&n==1){
    return n;
  }
  else{
    return fib(n-1) + fib(n-2);
  }
}

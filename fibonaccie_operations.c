#include <stdio.h>
// the nth Fibonacci number
int find_nth_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return find_nth_fibonacci(n - 1) + find_nth_fibonacci(n - 2);
}
// printing the series using recursion 
void print_fibonacci_helper(int n, int m1, int m2) {
    if (n > 0) {
        int m3 = m1 + m2;
        printf("%d ", m3);
        print_fibonacci_helper(n - 1, m2, m3);
    }
}
// printing the Fibonacci series
void print_fibonacci_series(int n) {
    if (n <= 0) {
        printf("Invalid input. Please enter a positive number of terms.\n");
        return;
    }
    printf("0 ");
    if (n > 1) {
        printf("1 ");
        print_fibonacci_helper(n - 2, 0, 1);
    }
    printf("\n");
}
//find the sum of the Fibonacci series
long long sum_fibonacci_series(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }
    return 1 + sum_fibonacci_series(n - 1) + sum_fibonacci_series(n - 2);
}

int main()
{
    int choice, n;
    do 
    {
        printf("\n--- Fibonacci Menu ---\n");
        printf("1. Find the nth Fibonacci number (0-based index)\n");
        printf("2. Print Fibonacci series up to n terms\n");
        printf("3. Find the sum of the Fibonacci series up to n terms (using specified logic)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value of n (0-based index, e.g., 4 for the fifth term): ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Please enter a non-negative number.\n");
                } else {
                    printf("The %dth Fibonacci number is: %d\n", n, find_nth_fibonacci(n));
                }
                break;
            case 2:
                printf("Enter the number of terms (n): ");
                scanf("%d", &n);
                printf("Fibonacci series: ");
                print_fibonacci_series(n);
                break;
            case 3:
                printf("Enter the number of terms (n) for the sum: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("The sum of the series up to %d terms is: 0\n", n);
                } else {
                    printf("The sum of the series up to %d terms is: %lld\n", n, sum_fibonacci_series(n));
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

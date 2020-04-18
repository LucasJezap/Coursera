#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long r = 10;
    long long cycle_length = 1;
    long long a=1,b=1,c;

    while (a != 0 or b != 1) {
        c = 1LL*(a + b)%r;
        a = b;
        b = c;
        cycle_length++;
    }

    long long rem = (n+1) % cycle_length;
    long long count = 0;
    a=0,b=1;

    /* n+1 fib number last digit */
    while(count++ < rem) {
        c = (a + b)%r;
        a = b;
        b = c;
    }
    long long rem1 = a;

    rem = n % cycle_length;
    count = 0;
    a=0,b=1;

    /* n fib number last digit */
    while(count++ < rem) {
        c = (a + b)%r;
        a = b;
        b = c;
    }

    return (a*b)%r;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}

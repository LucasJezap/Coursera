#include <iostream>

int fibonacci_sum_naive(long long m, long long n) {
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

    long long rem = (n+2) % cycle_length;
    long long count = 0;
    a=0,b=1;

    /* n+2 fib number last digit */
    while(count++ < rem) {
        c = (a + b)%r;
        a = b;
        b = c;
    }
    long long rem1 = a;

    rem = (m+1) % cycle_length;
    count = 0;
    a=0,b=1;

    /* m+1 fib number last digit */
    while(count++ < rem) {
        c = (a + b)%r;
        a = b;
        b = c;
    }

    return (rem1 - a < 0)? 10+rem1-a : rem1 - a;
}

int main() {
    long long m,n = 0;
    std::cin >> m >> n;
    std::cout << fibonacci_sum_naive(m,n);
}

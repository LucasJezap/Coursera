#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long m = 10;
    long long cycle_length = 1;
    long long a=1,b=1,c;

    while (a != 0 or b != 1) {
        c = 1LL*(a + b)%m;
        a = b;
        b = c;
        cycle_length++;
    }

    long long rem = (n+2) % cycle_length;
    long long count = 0;
    a=0,b=1;

    while(count++ < rem) {
        c = (a + b)%m;
        a = b;
        b = c;
    }

    return (a == 0)? 9: a-1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}

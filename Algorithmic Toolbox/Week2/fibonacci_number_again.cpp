#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long cycle_length = 1;
    long long a=1,b=1,c;

    while (a != 0 or b != 1) {
        c = 1LL*(a + b)%m;
        a = b;
        b = c;
        cycle_length++;
    }

    long long rem = n % cycle_length;
    long long count = 0;
    a=0,b=1;

    while(count++ < rem) {
        c = (a + b)%m;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n,m) << '\n';
}

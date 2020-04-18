#include <iostream>

long long lcm_naive(int a, int b) {
    int gcd;
    int tmp1=a,tmp2=b;
    while (a != b) {
        if (a>b)
            a -= b;
        else
            b -= a;
    }
    gcd = a;
    return 1LL*tmp1*tmp2/gcd;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_naive(a, b) << std::endl;
    return 0;
}

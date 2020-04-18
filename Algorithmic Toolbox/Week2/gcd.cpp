#include <iostream>

int gcd_naive(int a, int b) {

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_naive(a, b) << std::endl;
    return 0;
}

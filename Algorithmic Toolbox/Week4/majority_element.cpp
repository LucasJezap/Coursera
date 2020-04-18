#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

/* it's not divide and conquer actually */
int get_majority_element(vector<int> &a) {
    std::sort(a.begin(), a.end());
    int count = 1;

    for (int i=1; i<a.size(); i++) {
        if (a[i] == a[i-1]) {
            count++;
            if (count > a.size()/2)
                return 1;
        }
        else
            count = 1;
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a)) << '\n';
}

#include <iostream>

int get_change(int m) {
    int min_steps[m+1];
    min_steps[0] = 0;
    for (int i=1; i<=m; i++) {
        min_steps[i] = min_steps[i-1] + 1;
        if (i-3 >= 0) min_steps[i] = std::min(min_steps[i-3]+1,min_steps[i]);
        if (i-4 >= 0) min_steps[i] = std::min(min_steps[i-4]+1,min_steps[i]);
    }
    return min_steps[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}

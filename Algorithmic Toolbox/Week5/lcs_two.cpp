#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
    int C[a.size()+1][b.size()+1];

    for (int i=0; i<a.size()+1; i++) {
        for (int j=0; j<b.size()+1; j++) {
            if (i == 0 || j == 0)
                C[i][j] = 0;

            else if (a[i-1] == b[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
            }
            else {
                C[i][j] = std::max(C[i-1][j],C[i][j-1]);
            }
        }
    }
    return C[a.size()][b.size()];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}

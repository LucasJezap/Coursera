#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int C[a.size()+1][b.size()+1][c.size()+1];

    for (int i=0; i<a.size()+1; i++) {
        for (int j=0; j<b.size()+1; j++)
            for (int k=0; k<c.size()+1; k++) {
                if (i == 0 || j == 0 || k == 0)
                    C[i][j][k] = 0;

                else if (a[i-1] == b[j-1] and b[j-1] == c[k-1]) {
                    C[i][j][k] = C[i-1][j-1][k-1] + 1;
                }
                else {
                    C[i][j][k] = std::max(std::max(C[i-1][j][k],C[i][j-1][k]),C[i][j][k-1]);
                }
            }
    }
    return C[a.size()][b.size()][c.size()];
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

    size_t k;
    std::cin >> k;
    vector<int> c(k);
    for (size_t i = 0; i < k; i++) {
        std::cin >> c[i];
    }

    std::cout << lcs3(a, b, c) << std::endl;
}

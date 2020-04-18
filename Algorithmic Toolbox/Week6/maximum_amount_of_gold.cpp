#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
    vector<vector<int>> V(W+1);
    for (int i=0; i<=W; i++)
        V[i] = vector<int>(w.size()+1);

    for (int i = 0; i <= W; i++)
        V[i][0] = 0;

    for (int j = 1; j <= w.size(); j++)
        V[0][j] = 0;

    for (int i = 1; i <= w.size(); i++) {
        for (int j = 1; j <= W; j++) {
            V[j][i] = V[j][i - 1];

            if (w[i-1] <= j)
                V[j][i] = std::max(V[j][i], V[j - w[i-1]][i - 1] + w[i-1]);
        }
    }

    return V[W][w.size()];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}

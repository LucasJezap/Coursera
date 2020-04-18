#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct pair {
    double ratio;
    int weight;

    bool operator<(const pair &x) const {
        return ratio < x.ratio;
    }
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    vector<pair> ratios(values.size());

    for (int i=0; i<values.size(); i++) {
        pair x{};
        x.ratio = 1.0 * values[i] / weights[i];
        x.weight = weights[i];
        ratios[i] = x;
    }

    std::sort(ratios.begin(), ratios.end());

    int i = values.size()-1;
    while (capacity > 0) {
        if (ratios[i].weight <= capacity) {
            value += 1.0 * ratios[i].weight * ratios[i].ratio;
            capacity -= ratios[i].weight;
        }
        else {
            value += 1.0 * ratios[i].ratio * capacity;
            capacity = 0.0;
        }
        i -= 1;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}

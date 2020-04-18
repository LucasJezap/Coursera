#include <iostream>
#include <cassert>
#include <string>
#include <climits>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

long long min5(long long a, long long b, long long c, long long d, long long e) {
    return std::min(std::min(std::min(std::min(a,b),c),d),e);
}

long long max5(long long a, long long b, long long c, long long d, long long e) {
    return std::max(std::max(std::max(std::max(a,b),c),d),e);
}

void min_and_max(int i, int j, vector<char> operations, vector<vector<long long>> &m, vector<vector<long long>> &M) {
    long long min_v = LONG_LONG_MAX;
    long long max_v = LONG_LONG_MIN;

    for (int k=i; k<j; k++) {
        long long a = eval(M[i][k],M[k+1][j],operations[k-1]);
        long long b = eval(M[i][k],m[k+1][j],operations[k-1]);
        long long c = eval(m[i][k],M[k+1][j],operations[k-1]);
        long long d = eval(m[i][k],m[k+1][j],operations[k-1]);

        min_v = min5(a,b,c,d,min_v);
        max_v = max5(a,b,c,d,max_v);
    }
    m[i][j] = min_v;
    M[i][j] = max_v;
}

long long get_maximum_value(const string &exp) {
    vector<long long> numbers;
    vector<char> operations;
    int z = 0;
    while (z < exp.size()) {
        string tmp;
        while (z < exp.size() and exp[z] != '*' and exp[z] != '+' and exp[z] != '-') {
            tmp += exp[z];
            z++;
        }
        if (z < exp.size())
            operations.push_back(exp[z]);
        z++;
        numbers.push_back(std::stoll(tmp));
    }

    long long n = numbers.size();
    vector<vector<long long>> M(n+1);
    vector<vector<long long>> m(n+1);

    for (int i=0; i<=n; i++) {
        M[i] = vector<long long>(n+1);
        m[i] = vector<long long>(n+1);
    }

    for (int i=1; i<=n; i++) {
        m[i][i] = M[i][i] = numbers[i-1];
    }

    for (int s=1; s<n; s++) {
        for (int i=1; i<=n-s; i++) {
            int j = i + s;
            min_and_max(i,j,operations,m,M);
        }
    }

    return M[1][n];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}

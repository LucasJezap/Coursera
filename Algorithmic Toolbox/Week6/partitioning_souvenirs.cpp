#include <iostream>
#include <vector>

using std::vector;

/* NP complete */
int partition_rec3(vector<int> &A, int sum1, int sum2, int sum3, int i) {
    if (i == A.size()) {
        return (sum1 == sum2) && (sum2 == sum3);
    }
    return partition_rec3(A,sum1+A[i],sum2,sum3,i+1) or
           partition_rec3(A,sum1,sum2+A[i],sum3,i+1) or
           partition_rec3(A,sum1,sum2,sum3+A[i],i+1);
}

int partition3(vector<int> &A) {
    return partition_rec3(A,0,0,0,0);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}

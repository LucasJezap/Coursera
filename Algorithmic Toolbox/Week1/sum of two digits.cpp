#include <bits/stdc++.h>
#include "maximumpairwiseproduct.h"

int main()
{
    /* input preparation */
    int n;
    std::cin >> n;
    std::vector <int> arr(n);

    /* providing input */
    for (int i=0; i<n; i++)
        std::cin >> arr[i];

    std::cout << maximumPairwiseProduct(arr) << std::endl;
    //stressTest(200000,200000,5);
}

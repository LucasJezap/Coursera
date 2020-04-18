#include <bits/stdc++.h>

/* naive */
unsigned long long maximumPairwiseEasy(std::vector<int> arr) {
    unsigned long long result = 0;
    for (int i=0; i<arr.size(); i++)
        for(int j=i+1; j<arr.size(); j++)
            if(1ULL*arr[i]*arr[j] > result)
                result = 1ULL * arr[i] * arr[j];

    return result;
}

/* function finding the maximum product of any two numbers in a sequence */
unsigned long long maximumPairwiseProduct(std::vector<int> arr) {
    int biggest = 0, secondBiggest = 0;
    int index = -1;

    for (int i=0; i<arr.size(); i++) {
        if (arr[i] > biggest) {
            index = i;
            biggest = arr[i];
        }
    }

    for (int i=0; i<arr.size(); i++) {
        if (arr[i] > secondBiggest and index != i)
            secondBiggest = arr[i];
    }

    unsigned long long result = 1ULL * biggest * secondBiggest;
    return (unsigned long long) result;
}

/* stress Test */
void stressTest(int N, int M, int num) {
    srand(time(nullptr));
    for (int a = 0; a<num; a++) {
        int n = rand()%(N-1)+2;
        std::vector <int> arr(n);
        for (int i=0; i<arr.size(); i++)
            arr[i] = rand()%(M+1);

        unsigned long long result1 = maximumPairwiseEasy(arr);
        unsigned long long result2 = maximumPairwiseProduct(arr);

        if (result1 == result2)
            std::cout << "OK" << std::endl;
        else
            std::cout << "ERROR" << std::endl;
    }
}
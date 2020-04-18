#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool comparator(const string& a, const string& b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

string largest_number(vector<string> a) {

    std::sort(a.begin(),a.end(),comparator);

    string result = "";
    for(int i=0; i<a.size(); i++)
        result += a[i];

    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}

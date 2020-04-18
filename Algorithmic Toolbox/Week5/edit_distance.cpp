#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
    int D[str1.size()+1][str2.size()+1];

    for (int i=0; i<str1.size()+1; i++)
        D[i][0] = i;
    for (int i=0; i<str2.size()+1; i++)
        D[0][i] = i;
    for (int j=1; j<str2.size()+1; j++) {
        for (int i=1; i<str1.size()+1; i++) {
            int insertion = D[i][j-1] + 1;
            int deletion = D[i-1][j] + 1;
            int match = D[i-1][j-1];
            int mismatch = match + 1;

            if (str1[i-1] == str2[j-1])
                D[i][j] = std::min(std::min(insertion,deletion),match);
            else
                D[i][j] = std::min(std::min(insertion,deletion),mismatch);
        }
    }

    return D[str1.size()][str2.size()];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}

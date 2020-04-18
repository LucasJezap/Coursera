#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    vector <int> better_stops(stops.size()+2);
    better_stops[0] = 0;
    better_stops[stops.size()+1] = dist;
    for (int i=1; i<stops.size()+1; i++)
        better_stops[i] = stops[i-1];
    int refills = 0;
    int curr = 0;

    while(curr < better_stops.size()) {
        int next = curr;
        while (next < better_stops.size() and better_stops[next+1]-better_stops[curr] <= tank)
            next++;

        if (next == curr)
            return -1;

        curr = next;
        if (curr == better_stops.size()-1)
            break;

        if (next < better_stops.size())
            refills++;
    }

    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

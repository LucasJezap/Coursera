#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;

    bool operator<(const Segment &s) {
        return end < s.end;
    }
};

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;

    std::sort(segments.begin(), segments.end());

    int i = 0;
    while (i < segments.size()) {
        int end = segments[i].end;
        points.push_back(end);
        i++;
        while (i < segments.size() and segments[i].start <= end)
            i++;
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct sp_point {
    int x;
    int label; // 0 - LEFT, 1 - RIGHT, 2 - POINT

    bool operator<(const sp_point &a) {
        if (x != a.x)
            return x < a.x;
        else
            return label < a.label;
    }
};

struct unsorted_point {
    int x;
    int index;

    bool operator<(const unsorted_point &p) {
        return x < p.x;
    }
};

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<sp_point> special_points;

    for (int start : starts) {
        sp_point x{};
        x.label = 0;
        x.x = start;
        special_points.push_back(x);
    }

    for (int end : ends) {
        sp_point x{};
        x.label = 2;
        x.x = end;
        special_points.push_back(x);
    }

    for (int point : points) {
        sp_point x{};
        x.label = 1;
        x.x = point;
        special_points.push_back(x);
    }

    std::sort(special_points.begin(), special_points.end());

    vector<unsorted_point> results(points.size());
    for (int i=0; i<results.size(); i++) {
        results[i].x = points[i];
        results[i].index = i;
    }

    std::sort(results.begin(), results.end());

    int cnt = 0;

    int j = 0;
    vector<int> app_result(points.size());

    for(int i=0; i<special_points.size(); i++) {
        if (special_points[i].label == 0)
            cnt++;
        else if (special_points[i].label == 2)
            cnt--;
        else
            app_result[results[j++].index] = cnt;
    }

    return app_result;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
//    while (true) {
//        int n = 2 + rand()%25, m = 2 + rand()%25;
//        vector<int> starts(n), end(n), points(m);
//        for (size_t i = 0; i < starts.size(); i++) {
//            starts[i] = rand()%100-rand()%100;
//            end[i] = starts[i] + rand()%100;
//        }
//        for (size_t i = 0; i < points.size(); i++) {
//            points[i] = rand()%150 - rand()%150;
//        }
//
//        vector<int> cnt = naive_count_segments(starts, end, points);
//        vector<int> cnt2 = fast_count_segments(starts,end,points);
//
//        for (size_t i = 0; i < cnt.size(); i++) {
//            std::cout << cnt[i] << ' ';
//        }
//        std::cout << std::endl;
//        for (size_t i = 0; i < cnt2.size(); i++) {
//            std::cout << cnt2[i] << ' ';
//        }
//        std::cout << std::endl;
//
//        if (cnt.size() != cnt2.size()) break;
//        for (size_t i = 0; i < cnt.size(); i++)
//            if (cnt[i] != cnt2[i]) break;
//    }
    int n, m;
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}

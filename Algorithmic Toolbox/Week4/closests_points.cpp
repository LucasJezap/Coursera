#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct point {
    int x,y;

    friend std::ostream& operator <<(std::ostream &os, const point &p) {
        os << "(" << p.x << "," << p.y << ")" << std::endl;
        return os;
    }
};

double dist(point x, point y) {
    return sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y));
}

bool comparatorX(point &x, point &y) {
    return x.x < y.x;
}

bool comparatorY(point &x, point &y) {
    return x.y < y.y;
}

double brute_force(vector<point> points, int l, int r) {
    double result = 1e10;
    for (int i=l; i<r; i++)
        for (int j=i+1; j<r; j++) {
            double distance = dist(points[i],points[j]);
            if (distance < result)
                result = distance;
        }
    return result;
}

double closest_points(vector<point> points, int l, int r) {
    if (r-l <= 3)
        return brute_force(points,l,r);

    int mid = (l+r)/2;
    double d1 = closest_points(points,l,mid);
    double d2 = closest_points(points,mid,r);
    double d = min(d1,d2);

    double mid_line = (points[mid].x + points[mid+1].x)/2.0;

    vector<point> strip;

    for (int i = 0; i<points.size(); i++) {
        if (std::abs(mid_line - points[i].x) < d)
            strip.push_back(points[i]);
    }

    std::sort(strip.begin(),strip.end(),comparatorY);

    for (int i=0; i<strip.size(); i++) {
        for (int j=i+1; j<std::min((unsigned int) i+8,strip.size()); j++)
            if (dist(strip[i],strip[j]) < d)
                d = dist(strip[i],strip[j]);
    }

    return d;
}

double minimal_distance(vector<int> x, vector<int> y) {
    vector<point> points(x.size());
    for (int i=0; i<points.size(); i++) {
        points[i].x = x[i];
        points[i].y = y[i];
    }
    std::sort(points.begin(),points.end(),comparatorX);

    double result = closest_points(points,0,points.size());

    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}

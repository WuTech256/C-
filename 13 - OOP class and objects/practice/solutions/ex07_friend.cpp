// Solution 7 - friend & this / Lời giải 7
#include <iostream>
#include <cmath>

class Point {
    double x, y;
    friend double distance(const Point &a, const Point &b);
    friend class Debugger;
public:
    Point(double x = 0, double y = 0) : x{x}, y{y} {}
    bool is_same(const Point &other) const { return this == &other; }
};

double distance(const Point &a, const Point &b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class Debugger {
public:
    void dump(const Point &p) const {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
};

int main() {
    Point a {0, 0}, b {3, 4};
    std::cout << distance(a, b) << std::endl;          // 5
    Debugger d; d.dump(b);                              // (3, 4)
    std::cout << std::boolalpha << a.is_same(a) << " " << a.is_same(b) << std::endl; // true false
    // a.x = 5;   // error: 'double Point::x' is private
    return 0;
}

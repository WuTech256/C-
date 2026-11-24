// Exercise 7 - friend & this
// EN: 1) Point has private x, y. Make `double distance(const Point&, const Point&)` a friend.
//     2) Make class Debugger a friend so Debugger::dump(const Point&) prints x, y.
//     3) Write bool Point::is_same(const Point &other) const using `this`.
//     4) Try accessing p.x from main -> should NOT compile.
// VI: 1) Point có x, y private. Cho hàm distance làm friend.
//     2) Cho lớp Debugger làm friend để dump in x, y.
//     3) Viết is_same dùng con trỏ `this`.
//     4) Thử truy cập p.x trong main -> phải báo lỗi.
#include <iostream>
#include <cmath>

class Point {
    double x, y;
    // TODO: friend declarations
public:
    Point(double x = 0, double y = 0) : x{x}, y{y} {}
    // TODO: is_same
};

// TODO: double distance(const Point &a, const Point &b)

class Debugger {
public:
    // TODO: void dump(const Point &p) const
};

int main() {
    // Point a {0, 0}, b {3, 4};
    // std::cout << distance(a, b) << std::endl;          // 5
    // Debugger d; d.dump(b);                              // (3, 4)
    // std::cout << std::boolalpha << a.is_same(a) << " " << a.is_same(b) << std::endl; // true false
    return 0;
}

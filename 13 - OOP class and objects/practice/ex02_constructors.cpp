// Exercise 2 - Constructors
// EN: Class Rectangle { std::string name; double width; double height; }
//     a) Write a 3-arg constructor using an initialization list. Print "3-args".
//     b) Write Rectangle() delegating to Rectangle{"Unnamed", 1, 1}. Print "no-args".
//     c) Write Rectangle(std::string) delegating to {name, 1, 1}. Print "1-arg".
//     d) Write a destructor printing "Destroying <name>".
//     e) Bonus: delete b) and c) and use default parameters instead. Why can't you keep both?
// VI: Lớp Rectangle { name, width, height }
//     a) Constructor 3 tham số dùng danh sách khởi tạo, in "3-args".
//     b) Rectangle() ủy quyền cho Rectangle{"Unnamed",1,1}, in "no-args".
//     c) Rectangle(std::string) ủy quyền cho {name,1,1}, in "1-arg".
//     d) Destructor in "Destroying <name>".
//     e) Bonus: bỏ b), c) và dùng tham số mặc định. Vì sao không giữ cả hai được?
#include <iostream>
#include <string>

class Rectangle {
    std::string name;
    double width;
    double height;
public:
    // TODO
    double area() const { return width * height; }
};

int main() {
    // Rectangle r1;                  // expected: 3-args, no-args
    // Rectangle r2 {"Square"};       // expected: 3-args, 1-arg
    // Rectangle r3 {"Big", 10, 20};  // expected: 3-args
    // std::cout << r3.area() << std::endl; // 200
    return 0;
}   // Predict destructor order! / Đoán thứ tự destructor!

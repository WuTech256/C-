// Solution 2 - Constructors / Lời giải 2
#include <iostream>
#include <string>

class Rectangle {
    std::string name;
    double width;
    double height;
public:
    Rectangle(std::string name, double width, double height)
        : name{name}, width{width}, height{height} {
        std::cout << "3-args" << std::endl;
    }
    Rectangle() : Rectangle{"Unnamed", 1, 1} {
        std::cout << "no-args" << std::endl;
    }
    Rectangle(std::string name) : Rectangle{name, 1, 1} {
        std::cout << "1-arg" << std::endl;
    }
    ~Rectangle() { std::cout << "Destroying " << name << std::endl; }
    double area() const { return width * height; }
};

// Bonus (e): a single constructor replaces all three:
//   Rectangle(std::string name = "Unnamed", double w = 1, double h = 1);
// EN: You cannot keep Rectangle() as well -> `Rectangle r;` would be ambiguous.
// VI: Không giữ được Rectangle() nữa -> `Rectangle r;` sẽ bị mơ hồ.

int main() {
    Rectangle r1;                  // 3-args, no-args
    Rectangle r2 {"Square"};       // 3-args, 1-arg
    Rectangle r3 {"Big", 10, 20};  // 3-args
    std::cout << r3.area() << std::endl; // 200
    return 0;
}   // Destroying Big, Destroying Square, Destroying Unnamed

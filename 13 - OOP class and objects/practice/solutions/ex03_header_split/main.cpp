#include <iostream>
#include "Student.h"
#include "Student.h"   // OK thanks to include guard

int main() {
    Student s {"Toan"};
    s.add_score(8.5); s.add_score(9); s.add_score(7.5);
    std::cout << s.get_name() << " avg = " << s.average() << std::endl;  // Toan avg = 8.33333
    Student none;
    std::cout << none.get_name() << " avg = " << none.average() << std::endl; // None avg = 0
    return 0;
}

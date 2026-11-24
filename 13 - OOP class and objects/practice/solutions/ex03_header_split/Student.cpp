#include "Student.h"

Student::Student(std::string name) : name{name} {}   // no default here / không ghi lại mặc định

void Student::add_score(double s) { scores.push_back(s); }

double Student::average() const {
    if (scores.empty()) return 0;
    double total {0};
    for (double s : scores) total += s;
    return total / scores.size();
}

std::string Student::get_name() const { return name; }

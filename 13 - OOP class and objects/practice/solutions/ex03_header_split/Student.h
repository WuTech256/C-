#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    std::vector<double> scores;
public:
    Student(std::string name = "None");
    void add_score(double s);
    double average() const;
    std::string get_name() const;
};

#endif // _STUDENT_H_

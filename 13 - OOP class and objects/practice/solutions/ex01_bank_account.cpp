// Solution 1 - Bank Account / Lời giải 1
#include <iostream>
#include <string>

class Account {
private:
    std::string name;
    double balance;
public:
    Account(std::string name, double balance) : name{name}, balance{balance} {}

    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        return true;
    }
    bool withdraw(double amount) {
        if (amount <= 0 || balance - amount < 0) return false;
        balance -= amount;
        return true;
    }
    std::string get_name() const { return name; }
    double get_balance() const { return balance; }
};

void print(const Account &a) {
    std::cout << a.get_name() << ": " << a.get_balance() << std::endl;
}

int main() {
    Account frank {"Frank", 1000};
    std::cout << std::boolalpha;
    std::cout << frank.deposit(500) << std::endl;   // true
    std::cout << frank.withdraw(2000) << std::endl; // false
    std::cout << frank.withdraw(300) << std::endl;  // true
    print(frank);                                   // Frank: 1200
    return 0;
}

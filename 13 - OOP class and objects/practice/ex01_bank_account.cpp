// Exercise 1 - Bank Account
// EN: Create class Account with PRIVATE name and balance.
//     - constructor Account(std::string name, double balance) using an initialization list
//     - bool deposit(double amount): reject amount <= 0
//     - bool withdraw(double amount): reject if balance is insufficient
//     - const getters get_name(), get_balance()
// VI: Tạo lớp Account có name và balance là PRIVATE.
//     - constructor dùng danh sách khởi tạo
//     - deposit: từ chối nếu amount <= 0
//     - withdraw: từ chối nếu không đủ tiền
//     - getter const get_name(), get_balance()
#include <iostream>
#include <string>

class Account {
    // TODO: attributes / thuộc tính
public:
    // TODO: constructor, deposit, withdraw, getters
};

void print(const Account &a) {
    // TODO: uncomment when getters are const / bỏ comment khi getter đã const
    // std::cout << a.get_name() << ": " << a.get_balance() << std::endl;
}

int main() {
    // Account frank {"Frank", 1000};
    // std::cout << std::boolalpha;
    // std::cout << frank.deposit(500) << std::endl;   // true
    // std::cout << frank.withdraw(2000) << std::endl; // false
    // std::cout << frank.withdraw(300) << std::endl;  // true
    // print(frank);                                   // Frank: 1200
    return 0;
}

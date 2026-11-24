// Exercise 6 - Static members
// EN: Add `static int alive;` to Enemy, increment in ctor, decrement in dtor,
//     static int get_alive(). Define it outside the class. Fill in the expected numbers.
// VI: Thêm `static int alive;`, tăng trong ctor, giảm trong dtor, static get_alive().
//     Định nghĩa bên ngoài lớp. Điền các số dự đoán.
#include <iostream>
#include <string>

class Enemy {
    std::string name;
    // TODO
public:
    Enemy(std::string name = "Goblin") : name{name} { /* TODO */ }
    Enemy(const Enemy &src) : Enemy{src.name} {}
    ~Enemy() { /* TODO */ }
    // TODO: static int get_alive();
};

// TODO: int Enemy::alive {0};

void fight(Enemy e) {
    // std::cout << "In fight: " << Enemy::get_alive() << std::endl;   // ?
}

int main() {
    // std::cout << Enemy::get_alive() << std::endl;   // ?
    // Enemy e1, e2 {"Orc"};
    // fight(e1);
    // Enemy *boss = new Enemy{"Dragon"};
    // std::cout << Enemy::get_alive() << std::endl;   // ?
    // delete boss;
    // std::cout << Enemy::get_alive() << std::endl;   // ?
    return 0;
}

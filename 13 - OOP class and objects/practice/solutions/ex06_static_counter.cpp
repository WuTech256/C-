// Solution 6 - Static members / Lời giải 6
#include <iostream>
#include <string>

class Enemy {
    std::string name;
    static int alive;
public:
    Enemy(std::string name = "Goblin") : name{name} { ++alive; }
    Enemy(const Enemy &src) : Enemy{src.name} {}   // delegating -> also counts
    ~Enemy() { --alive; }
    static int get_alive() { return alive; }
};

int Enemy::alive {0};

void fight(Enemy e) {
    std::cout << "In fight: " << Enemy::get_alive() << std::endl;   // 3 (copy e)
}

int main() {
    std::cout << Enemy::get_alive() << std::endl;   // 0
    Enemy e1, e2 {"Orc"};
    fight(e1);
    Enemy *boss = new Enemy{"Dragon"};
    std::cout << Enemy::get_alive() << std::endl;   // 3
    delete boss;
    std::cout << Enemy::get_alive() << std::endl;   // 2
    return 0;
}

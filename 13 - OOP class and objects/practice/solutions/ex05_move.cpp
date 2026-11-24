// Solution 5 - Move constructor / Lời giải 5
#include <iostream>
#include <vector>

class IntArray {
    size_t size;
    int *data;
public:
    IntArray(size_t n) : size{n}, data{new int[n]{}} {
        std::cout << "Constructor " << size << std::endl;
    }
    IntArray(const IntArray &src) : size{src.size}, data{new int[src.size]} {
        for (size_t i = 0; i < size; ++i) data[i] = src.data[i];
        std::cout << "Copy " << size << std::endl;
    }
    IntArray(IntArray &&src) noexcept : size{src.size}, data{src.data} {
        src.data = nullptr;   // IMPORTANT / QUAN TRỌNG
        src.size = 0;
        std::cout << "Move " << size << std::endl;
    }
    ~IntArray() {
        if (data == nullptr) std::cout << "Destructor nullptr" << std::endl;
        else std::cout << "Destructor " << size << std::endl;
        delete [] data;   // delete [] nullptr is safe
    }
};

int main() {
    std::vector<IntArray> vec;
    vec.push_back(IntArray{10});   // Constructor 10, Move 10, Destructor nullptr
    vec.push_back(IntArray{20});   // + vector reallocation also uses Move (thanks to noexcept)
    vec.push_back(IntArray{30});
    return 0;
}

// Solution 4 - Deep copy / Lời giải 4
// EN: Without the copy ctor, show(a) copies the pointer; its destructor frees a's array
//     -> a.data dangles, later double delete = undefined behaviour.
// VI: Không có copy ctor, show(a) chép con trỏ; destructor của bản sao giải phóng mảng của a
//     -> a.data bị treo, sau đó delete hai lần = hành vi không xác định.
#include <iostream>

class IntArray {
    size_t size;
    int *data;
public:
    IntArray(size_t n, int value = 0) : size{n}, data{new int[n]} {
        for (size_t i = 0; i < size; ++i) data[i] = value;
        std::cout << "Constructor size " << size << std::endl;
    }
    IntArray(const IntArray &src) : size{src.size}, data{new int[src.size]} {
        for (size_t i = 0; i < size; ++i) data[i] = src.data[i];
        std::cout << "Copy constructor - deep copy" << std::endl;
    }
    ~IntArray() {
        delete [] data;
        std::cout << "Destructor" << std::endl;
    }
    void set(size_t i, int v) { data[i] = v; }
    int get(size_t i) const { return data[i]; }
    size_t get_size() const { return size; }
};

void show(IntArray a) {
    for (size_t i = 0; i < a.get_size(); ++i) std::cout << a.get(i) << " ";
    std::cout << std::endl;
}

int main() {
    IntArray a {3, 7};
    show(a);
    IntArray b {a};
    b.set(0, 99);
    std::cout << "a[0]=" << a.get(0) << " b[0]=" << b.get(0) << std::endl; // a[0]=7 b[0]=99
    return 0;
}

// Exercise 4 - Deep copy
// EN: IntArray owns a heap array (int *data, size_t size).
//     1) Run as-is (shallow copy from compiler) and explain why it crashes / misbehaves.
//     2) Write a DEEP copy constructor: IntArray(const IntArray &src).
//     3) Make sure the destructor uses delete [].
// VI: IntArray sở hữu mảng trên heap.
//     1) Chạy nguyên bản (copy nông do compiler sinh) và giải thích vì sao lỗi.
//     2) Viết copy constructor SÂU.
//     3) Destructor phải dùng delete [].
#include <iostream>

class IntArray {
    size_t size;
    int *data;
public:
    IntArray(size_t n, int value = 0) : size{n}, data{new int[n]} {
        for (size_t i = 0; i < size; ++i) data[i] = value;
        std::cout << "Constructor size " << size << std::endl;
    }
    // TODO: deep copy constructor / copy constructor sâu
    ~IntArray() {
        delete [] data;
        std::cout << "Destructor" << std::endl;
    }
    void set(size_t i, int v) { data[i] = v; }
    int get(size_t i) const { return data[i]; }
    size_t get_size() const { return size; }
};

void show(IntArray a) {      // pass by value -> copy! / truyền theo giá trị -> copy!
    for (size_t i = 0; i < a.get_size(); ++i) std::cout << a.get(i) << " ";
    std::cout << std::endl;
}

int main() {
    IntArray a {3, 7};
    show(a);
    IntArray b {a};
    b.set(0, 99);
    std::cout << "a[0]=" << a.get(0) << " b[0]=" << b.get(0) << std::endl; // expected: a[0]=7 b[0]=99
    return 0;
}

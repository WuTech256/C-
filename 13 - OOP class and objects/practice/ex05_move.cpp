// Exercise 5 - Move constructor
// EN: 1) Run as-is and count how many "Copy" lines appear.
//     2) Add IntArray(IntArray &&src) noexcept that steals src.data and sets src.data = nullptr.
//     3) Update the destructor to handle nullptr. Run again: copies become moves.
// VI: 1) Chạy nguyên bản, đếm số dòng "Copy".
//     2) Thêm move constructor noexcept: lấy src.data rồi gán src.data = nullptr.
//     3) Sửa destructor xử lý nullptr. Chạy lại: copy biến thành move.
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
    // TODO: move constructor
    ~IntArray() {
        // TODO: print "Destructor nullptr" when data == nullptr
        std::cout << "Destructor " << size << std::endl;
        delete [] data;
    }
};

int main() {
    std::vector<IntArray> vec;
    vec.push_back(IntArray{10});
    vec.push_back(IntArray{20});
    vec.push_back(IntArray{30});
    return 0;
}

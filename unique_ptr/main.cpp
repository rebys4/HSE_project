#include <iostream>
#include "unique_ptr.h"


int main() {
    auto ptr = new int;
    const UniquePtr<int> b(ptr);
    if (b.Get() == nullptr) {
        std::cout << "true" << "\n";
    } else {
        std::cout << "false" << "\n";
    }
    return 0;
}

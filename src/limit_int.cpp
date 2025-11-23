#include <iostream>
#include <limits>

bool can_add_one(int x) {
    return !((x + 1) > x);
}

int main() {
    int max_val = std::numeric_limits<int>::max();
    
    if (can_add_one(max_val)) {
        std::cout << "Не UB" << std::endl;
    } else {
        std::cout << "UB" << std::endl;
    }
    
    return 0;
}

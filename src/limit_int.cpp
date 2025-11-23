#include <iostream>
#include <limits>

bool check_overflow(int x) {
    // Если x + 1 переполнится, оно станет маленьким, и условие будет false
    return (x + 1) > x;
}

int main() {
    int max = std::numeric_limits<int>::max(); 
    
    if (check_overflow(max)) {
        std::cout << "UB не сработало: True\n";
    } else {
        std::cout << "UB!!!!\n";
    }
}

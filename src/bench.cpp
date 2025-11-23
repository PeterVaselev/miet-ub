#include <chrono>
#include <iostream>
#include <vector>

constexpr size_t ITERATIONS = 100'000'000;

void bench(size_t size) {
    std::vector<int> data(size, 1);
    
    volatile size_t idx = 0; 

    auto t1 = std::chrono::high_resolution_clock::now();
    long long sum1 = 0;
    for (size_t i = 0; i < ITERATIONS; ++i) {
        sum1 += data[idx]; 
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    
    auto t3 = std::chrono::high_resolution_clock::now();
    long long sum2 = 0;
    for (size_t i = 0; i < ITERATIONS; ++i) {
        sum2 += data.at(idx); 
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    std::cout << "Unsafe []: " << std::chrono::duration<double, std::milli>(t2 - t1).count() << " ms\n";
    std::cout << "Safe .at(): " << std::chrono::duration<double, std::milli>(t4 - t3).count() << " ms\n";
    
    if (sum1 != sum2) std::cout << "Error"; 
}

int main() {
    bench(100'000);
    return 0;
}

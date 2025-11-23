#include <chrono>
#include <iostream>
#include <vector>
#include <random>

constexpr size_t DATA_SIZE = 1024*1024; 
constexpr size_t ACCESS_COUNT = 100'000'000; 

void bench_unsafe(const std::vector<int>& data, const std::vector<size_t>& indices) {
    long long sum = 0;
    
    auto t1 = std::chrono::high_resolution_clock::now();
    
    for (size_t idx : indices) {
        sum += data[idx]; 
    }
    
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
    
    std::cout << "Operator []: " << ms.count() << " ms " 
              << "(Sum: " << sum << ")\n"; 
}

void bench_safe_at(const std::vector<int>& data, const std::vector<size_t>& indices) {
    long long sum = 0;
    
    auto t1 = std::chrono::high_resolution_clock::now();
    
    for (size_t idx : indices) {
        sum += data.at(idx);
    }
    
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
    
    std::cout << "Method .at(): " << ms.count() << " ms " 
              << "(Sum: " << sum << ")\n";
}

        

int main(){
    std::cout << "Preparing data..." << std::endl;
    std::vector<int> data(DATA_SIZE, 1);
    
    std::vector<size_t> indices(ACCESS_COUNT);
    std::mt19937 gen(12345); 
    std::uniform_int_distribution<size_t> dist(0, DATA_SIZE - 1);

    for (auto& idx : indices) {
        idx = dist(gen);
    }

    std::cout << "Starting benchmark (Cache Friendly)..." << std::endl;

    // ПРОГРЕВ (Запускаем, но не замеряем)
    bench_unsafe(data, indices);
    bench_unsafe(data, indices);
    std::cout << "Warmup done.\n\n";

    bench_unsafe(data, indices);  
    bench_safe_at(data, indices); 
    
    return 0;
}

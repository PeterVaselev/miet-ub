#include <iostream> 

int main(){
    int* arr = new int[5];

    for (int i = 0; i <= 15; i++){
        std::cout << i << ": " << arr[i] << std::endl;
    }

    return 0;
}

#include <iostream>

void printArray(int* begin, int* end) {
    for (int* ptr = begin; ptr != end; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(&arr[0], &arr[size]);

    return 0;
}


#include <iostream>

void quick_sort();

int main() {
    int size, *numbers;

    std::cout << "Enter number of elements: ";
    std::cin >> size;

    numbers = new int[size];

    std::cout << "Enter elements seperated by spaces:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    quick_sort(numbers, 0, size);
    std::cout << "Sorted array:\n";
    for (int i = 0 ; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}

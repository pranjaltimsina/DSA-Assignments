#include <iostream>

int partition(int * numbers, int p, int r) {
    int x{numbers[r]}, i{p-1}, temp;

    for (int j = p; j <= r-1; j++) {
        if (numbers[j] <= x) {
            i++;
            temp = numbers[j];
            numbers[j] = numbers[i];
            numbers[i] = temp;
        }
    }
    temp = numbers[i+1];
    numbers[i+1] = numbers[r];
    numbers[r] = temp;
    return i+1;
}


void quick_sort(int *numbers, int left, int right) {
    if (left < right) {
        int q = partition(numbers, left, right);
        quick_sort(numbers, left, q-1);
        quick_sort(numbers, q+1, right);
    }
}

int main() {
    int size, *numbers;

    std::cout << "Enter number of elements: ";
    std::cin >> size;

    numbers = new int[size];

    std::cout << "Enter elements seperated by spaces:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    quick_sort(numbers, 0, size-1);
    std::cout << "Sorted array:\n";
    for (int i = 0 ; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}

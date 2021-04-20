#include <iostream>

void selection_sort(int *numbers, int size) {
    int comparisons{0}, array_access{0};
    for (int i = 0; i < size; i++) {
        int key = i;
        for (int j = i+1; j < size; j++) {
            if (++comparisons&& ++++array_access && numbers[j] < numbers[key]) {
                key = j;
            }
        }
        int temp = numbers[key];
        numbers[key] = numbers[i];
        numbers[i] = temp;
        array_access += 3;
    }
    std::cout << array_access << " array accesses and " << comparisons << " comparisons\n";
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

    selection_sort(numbers, size);
    std::cout << "Sorted array:\n";
    for (int i = 0 ; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}

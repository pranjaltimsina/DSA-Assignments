#include <iostream>

void insertion_sort(int *numbers, int size) {
    int key, comparisons{0}, array_access{0};

    for (int i = 1; i < size; i++) {
        key = numbers[i];
        array_access++;
        int j = i-1;
        while (j >= 0 && ++comparisons && ++array_access && numbers[j] > key) {
            numbers[j+1] = numbers[j];
            array_access +=2;
            j--;
        }
        numbers[j+1] = key;
        array_access+=1;
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

    insertion_sort(numbers, size);
    std::cout << "Sorted array:\n";
    for (int i = 0 ; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}


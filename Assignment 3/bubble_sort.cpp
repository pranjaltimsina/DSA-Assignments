#include <iostream>

void bubble_sort(int *numbers, int size) {
    int temp, comparisons{0}, key, array_access{0};

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size -1; j++) {
            comparisons++;
            array_access +=2;
            if (numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                array_access += 4;
            }
        }
    }
    std::cout << comparisons << " comparisons were made and the array was accessed " << array_access << " times.\n";
}

int main() {
    int size, *numbers;
    std::cout << "Enter number of elements: ";
    std::cin >> size;

    numbers = new int[size];

    std::cout << "Enter numbers seperated by spaces\n";

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    bubble_sort(numbers, size);

    std::cout << "The sorted array is:\n";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}

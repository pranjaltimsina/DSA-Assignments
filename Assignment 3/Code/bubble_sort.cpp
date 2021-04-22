#include <iostream>

// c++ header to calculate time taken
#include <chrono>

// number of comparisons and array accesses
int comparisons{0}, array_access{0};

void bubble_sort(int *numbers, int size) {
    int temp; // variable for swapping data

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            // iterate till size - i as i elements will be
            // sorted in each pass
            array_access +=2;
            // swap if jth element is larget than
            // j+1 th element
            if (++comparisons && numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                array_access += 4;
            }
        }
    }
}

int main() {
    // for calculating time taken
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // initialize and input size of array
    int size, *numbers;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    // initialize arary of req size
    numbers = new int[size];
    // input elements of array
    std::cout << "\nEnter the elements seperated by spaces:\n\n";
    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    // start timing and call bubble sort function
    auto t1 = high_resolution_clock::now();
        bubble_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    // compute the time duration taken
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "\n\nThe sorted array is:\n\n";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }

    // print the time taken, array accesses and comparisons
    std::cout << "\n\nTime taken: " << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access <<
                " | Comparisons: " << comparisons << "\n\n";
}

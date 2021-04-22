// Exp 3E: Selection Sort
// Author: Pranjal Timsina
#include <iostream>

// c++ header for time
#include <chrono>

// initialize number of comparisons and
// number of array accesses
int comparisons{0}, array_access{0};

void selection_sort(int *numbers, int size) {

    for (int i = 0; i < size; i++) {
        // find the smallest element
        // and put it in its appropriate place
        // then move on to the next smallest element
        int key = i;
        for (int j = i+1; j < size; j++) {
            if (++comparisons&& ++++array_access && numbers[j] < numbers[key]) {
                // find the smallest element and set it as key
                key = j;
            }
        }
        // put the smallest element in its appropriate place
        int temp = numbers[key];
        numbers[key] = numbers[i];
        numbers[i] = temp;
        array_access += 3;
    }
}

int main() {
    // headers for calculating time taken by sort
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // initialize the size and the array
    int size, *numbers;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;


    // input the required number of elements
    numbers = new int[size];
    std::cout << "Enter the elements seperated by spaces:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    // start clock, run selection sort
    // and stop the clock
    auto t1 = high_resolution_clock::now();
        selection_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    // compute time taken
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "\nSorted array:\n\n";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }

    // give output statistics
    std::cout << "\n\nTime taken: " << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access << " | Comparisons: " << comparisons << "\n";
}

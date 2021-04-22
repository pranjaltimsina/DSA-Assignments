// Exp 3D: Insertion Sort
// Author: Pranjal Timsina; 20BDS0392
#include <iostream>

// c++ header for time
#include <chrono>

// intialize number of comparisons and
// number of array accesses

int comparisons{0}, array_access{0};

void insertion_sort(int *numbers, int size) {
    int key;

    // start by assuming number[0 to i exclusive]
    // is sorted
    for (int i = 1; i < size; i++) {
        // use ith element as key
        key = numbers[i];
        // increment number of array accesses
        array_access++;
        // insert the key in its proper position
        // left of i (inclusive)
        int j = i-1;
        while (j >= 0 && ++comparisons && ++array_access && numbers[j] > key) {
            // shift elements to right
            // if condition above is met
            numbers[j+1] = numbers[j];
            array_access +=2;
            j--;
        }
        // insert the key at appropriate location
        numbers[j+1] = key;
        array_access+=1;
    }
}

int main() {
    // for calculating time taken by sort
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // initialize and input array
    // and size of array
    int size, *numbers;
    std::cout << "Enter the number elements: ";
    std::cin >> size;

    numbers = new int[size];
    std::cout << "Enter " << size <<
                " elements seperated by spaces: \n";
    // input array elements
    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    // start timer, call insertion sort
    // then end timer
    auto t1 = high_resolution_clock::now();
        insertion_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    // compute time taken
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "\nSorted array:\n\n";
    for (int i = 0 ; i < size; i++) {
        std::cout << numbers[i] << " ";
    }

    // display statistics of the sort
    std::cout << "\n\nTime taken: " << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access <<
                 " | Comparisons: " << comparisons << "\n";
}

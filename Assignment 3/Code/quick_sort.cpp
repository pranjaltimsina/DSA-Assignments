// Exp 3F: Quick Sort
// Author: Pranjal Timsina; 20BDS0392

#include <iostream>

// c++ header for time
#include <chrono>

// intialize number of comparisons and
// number of array accesses
int array_access{0}, comparisons{0};

int partition(int * numbers, int p, int r) {
    // selects the right most element as the pivot
    int x{numbers[r]}, i{p-1}, temp;
    array_access++;

    for (int j = p; j <= r-1; j++) {
        // check and puts the elements in the array to the
        // right or left of the pivot accordingly
        if (++array_access && ++comparisons && numbers[j] <= x) {
            i++;
            // swap jth and ith element
            temp = numbers[j];
            numbers[j] = numbers[i];
            numbers[i] = temp;
            array_access+=4;
        }
    }

    // put the pivot element back in place
    temp = numbers[i+1];
    numbers[i+1] = numbers[r];
    numbers[r] = temp;
    array_access+=4;
    return i+1;
}


void quick_sort(int *numbers, int left, int right) {
    if (left < right) {
        // find the index of pivot element
        int q = partition(numbers, left, right);
        // sort the subarrays recursively
        quick_sort(numbers, left, q-1);
        quick_sort(numbers, q+1, right);
    }
}

int main() {
    // for calculating time taken by sort
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // initialize size and array
    int size, *numbers;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    // input elements of array
    numbers = new int[size];
    std::cout << "Enter the elements:\n\n";
    for (int i = 0; i < size; i++)
        std::cin >> numbers[i];

    // start timer, call quick sort
    // and end timer
    auto t1 = high_resolution_clock::now();
        quick_sort(numbers, 0, size-1);
    auto t2 = high_resolution_clock::now();

    // compute time taken by sort
    duration<double, std::milli> ms_double = t2 - t1;

    // print the sorted array
    std::cout << "The sorted array is:\n\n";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    // print sort statistics
    std::cout << "\n\nTime taken: " <<  ms_double.count() << "ms";
    std::cout << " | Array accesses: " <<  array_access << " | Comparisons: " << comparisons << "\n";
}

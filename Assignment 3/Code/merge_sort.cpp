// Exp 3G: Merge sort
// Author: Pranjal Timsina; 20BDS0392

#include <iostream>
// header for timing functions
#include <chrono>

// number of comparisons and array accesses
int array_access{0}, comparisons{0};

void merge(int * numbers, int l, int mid, int r) {
    // compute the lengths of the right and the left subarray
    int len_1 = mid - l + 1;
    int len_2 = r - mid;
    if (++comparisons && ++++array_access && numbers[mid+1] > numbers[mid]) return;
    // initialize and copy data to the right and left subarray
    // from the main array
    int L[len_1], R[len_2];
    for (int i = 0; i < len_1; i++)
        L[i] = numbers[l + i];
    for (int j = 0; j < len_2; j++)
        R[j] = numbers[mid + 1 + j];

    array_access = array_access + len_1 + len_2;
    /* i is the index for left subarray
     * j is the index for right subarray
     * k is the index of the main array
     */
    int i{0}, j{0}, k{l};

    // copy elements from the right & left
    // sub arrays to the main array
    // in ascending order
    while (i < len_1 && j < len_2) {
        if (++++array_access && ++comparisons && L[i] <= R[j]) {
            numbers[k] = L[i];
            i++;
        } else {
            numbers[k] = R[j];
            j++;
        }
        array_access += 2;
        k++;
    }
    // if any element is left in either of the sub arrays
    // copy them to the main array
    while (i < len_1) {
        numbers[k] = L[i]; i++; k++; array_access+=2;
    }
    while (j < len_2) {
        numbers[k] = R[j]; j++; k++; array_access +=2;
    }
}

void merge_sort(int* numbers, int left, int right) {
    // base case for recursion
    if (left >= right ) return;
    int mid = (right + left) / 2;
    // recursively merge_sort the left and right subarrays
    merge_sort(numbers, left, mid);
    merge_sort(numbers, mid+1, right);
    // merge the sorted subarrays
    merge(numbers, left, mid, right);
}


int main() {
    // used for timing functions
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // initialize size and the array
    int size, *numbers;
    std::cout << "Enter the size: ";
    std::cin >> size;

    numbers = new int[size];
    // input the elements of the array
    std::cout << "Enter the elements:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    // start timer, call merge_sort()
    // and stop the timer
    auto t1 = high_resolution_clock::now();
        merge_sort(numbers, 0, size);
    auto t2 = high_resolution_clock::now();

    // calculate the time taken
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "The sorted array is:\n\n";

    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }

    // display the statistics of the sort
    std::cout << "\n\nTime taken: "<<  ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access << " | Comparisons: " << comparisons << "\n";
}

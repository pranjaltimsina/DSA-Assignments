#include <iostream>
#include <iomanip>
// c++ header to calculate time taken
#include <chrono>

// number of comparisons and array accesses
unsigned long long comparisons{0}, array_access{0};

// functions are truncated because they are the same in the
// question above

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
    // used for timing functions
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    // input the number of elements
    int size, *numbers, temp, *unsorted;
    std::cin >> size;

    // initialize 2 arrays
    numbers = new int[size];
    unsorted = new int[size];

    // input data in array
    for (int i = 0; i < size; i++) {
        std::cin >> temp;
        numbers[i] = temp;
        unsorted[i] = temp;
    }

    //-------------------------------------------------------------------

    // time the function bubble sort
    auto t1 = high_resolution_clock::now();
        bubble_sort(numbers, size);
    auto t2 = high_resolution_clock::now();

    // compute the time taken
    duration<double, std::milli> ms_double = t2 - t1;

    // print the statistics
    std::cout << "Bubble Sort    | Inputs " << std::setw(6) << size << " | Time taken " << std::setw(8) <<  ms_double.count() << "ms";
    std::cout << " | Array accesses: " << std::setw(15) << array_access <<  " | Comparisons: " << comparisons << "\n";

    // -------------------------------------------------------------------

    // reset the array to unsorted state
    for (int i = 0; i < size; i++)
        numbers[i] = unsorted[i];

    // reset comparisons and array accesses
    comparisons = 0; array_access = 0;

    // time the function selection sort
    t1 = high_resolution_clock::now();
        selection_sort(numbers, size);
    t2 = high_resolution_clock::now();

    // compute time taken
     ms_double = t2 - t1;

    // print the statistics
    std::cout << "Selection Sort | Inputs " << std::setw(6) << size << " | Time taken " << std::setw(8) << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << std::setw(15) << array_access << " | Comparisons: " << comparisons << "\n";

    // -------------------------------------------------------------------

    // reset array to unsorted state
    for (int i = 0; i < size; i++)
        numbers[i] = unsorted[i];

    // reset comparisons and array accesses
    comparisons = 0; array_access = 0;

    // time the function insertion sort
    t1 = high_resolution_clock::now();
        insertion_sort(numbers, size);
    t2 = high_resolution_clock::now();

    // compute time taken
    ms_double = t2 - t1;

    // print the statistics
    std::cout << "Insertion Sort | Inputs " << std::setw(6) << size << " | Time taken " << std::setw(8) << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << std::setw(15) << array_access << " | Comparisons: " << comparisons << "\n";

    // -------------------------------------------------------------------

    // reset array to unsorted state
    for (int i = 0; i < size; i++)
        numbers[i] = unsorted[i];

    // reset comparisons and array accesses
    comparisons = 0; array_access = 0;

    // time the function merge sort
    t1 = high_resolution_clock::now();
        merge_sort(numbers, 0 , size);
    t2 = high_resolution_clock::now();

    // compute time taken
    ms_double = t2 - t1;

    // display the statistics
    std::cout << "Merge Sort     | Inputs " << std::setw(6) << size << " | Time taken " << std::setw(8) << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << std::setw(15) << array_access << " | Comparisons: " << comparisons << "\n";

    // -------------------------------------------------------------------

    // reset array to unsorted state
    for (int i = 0; i < size; i++)
        numbers[i] = unsorted[i];

    // reset comparisons and array accesses
    comparisons = 0; array_access = 0;

    // time the function quick sort
     t1 = high_resolution_clock::now();
        quick_sort(numbers, 0, size-1);
    t2 = high_resolution_clock::now();

    // calculate the time taken
    ms_double = t2 - t1;
    // display the statistics of the sort
    std::cout << "Quick Sort     | Inputs " << std::setw(6) << size << " | Time taken " << std::setw(8) << ms_double.count() << "ms";
    std::cout << " | Array accesses: " << std::setw(15) << array_access  << " | Comparisons: " << comparisons << "\n";

    // -------------------------------------------------------------------
}

#include <iostream>
#include <chrono>


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
    while (i < len_1) {
        numbers[k] = L[i]; i++; k++; array_access+=2;
    }
    while (j < len_2) {
        numbers[k] = R[j]; j++; k++; array_access +=2;
    }
}

void merge_sort(int* numbers, int left, int right) {
    if (left >= right ) return;
    int mid = (right + left) / 2;
    merge_sort(numbers, left, mid);
    merge_sort(numbers, mid+1, right);
    merge(numbers, left, mid, right);
}


int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int size, *numbers;

    std::cin >> size;
    numbers = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    auto t1 = high_resolution_clock::now();
        merge_sort(numbers, 0, size);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "Time taken: "<<  ms_double.count() << "ms";
    std::cout << " | Array accesses: " << array_access << " | Comparisons: " << comparisons << "\n";
}

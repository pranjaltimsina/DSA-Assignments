#include <iostream>

void merge(int * numbers, int l, int mid, int r) {
    // compute the lengths o fthe right and the left subarray
    int len_1 = mid - l + 1;
    int len_2 = r - mid;
    if (numbers[mid+1] > numbers[mid]) return;
    // initialize and copy data to the right and left subarray
    // from the main array
    int L[len_1], R[len_2];
    for (int i = 0; i < len_1; i++)
        L[i] = numbers[l + i];
    for (int j = 0; j < len_2; j++)
        R[j] = numbers[mid + 1 + j];

    /* i is the index for left subarray
     * j is the index for right subarray
     * k is the index of the main array
     */
    int i{0}, j{0}, k{l};

    while (i < len_1 && j < len_2) {
        if (L[i] <= R[j]) {
            numbers[k] = L[i];
            i++;
        } else {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < len_1) {
        numbers[k] = L[i]; i++; k++;
    }
    while (j < len_2) {
        numbers[k] = R[j]; j++; k++;
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
    int size, *numbers;

    std::cout << "Enter number of elements: ";
    std::cin >> size;

    numbers = new int[size];

    std::cout << "Enter elements seperated by spaces:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    merge_sort(numbers, 0, size);
    std::cout << "Sorted array:\n";
    for (int i = 0 ; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}

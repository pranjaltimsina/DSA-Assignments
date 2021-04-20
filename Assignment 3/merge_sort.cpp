#include <iostream>

void merge(int * numbers, int l, int mid, int r) {
    int len_1 = mid - l + 1;
    int len_2 = r - mid;

    // Create temp arrays
    int L[len_1], R[len_2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < len_1; i++)
        L[i] = numbers[l + i];
    for (int j = 0; j < len_2; j++)
        R[j] = numbers[mid + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < len_1 && j < len_2) {
        if (L[i] <= R[j]) {
            numbers[k] = L[i];
            i++;
        }
        else {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < len_1) {
        numbers[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < len_2) {
        numbers[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int* numbers, int l, int r) {
    if (l >=r ) return;
    int mid = l + (r-l) /2;
    merge_sort(numbers, l, mid);
    merge_sort(numbers, mid+1, r);
    merge(numbers, l, mid, r);
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

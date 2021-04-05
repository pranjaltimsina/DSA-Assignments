// Assignment 1D; Author: Pranjal Timsina, 20BDS0392
#include <stdio.h>
#include <stdlib.h>

// function to sort array, so repeated elements are grouped together
void sort(int * array, int size) {
    int temp; // temporary variable to swap array elements

    // Logic for insertion sort
    for (int i = 1; i < size; i++){
        for (int j = 0; j < i;j++){
            if (array[i] < array[j]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main() {

    // Declare and input the size of the array
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory to the array based on the given size
    int *array = calloc(size, sizeof(int));

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    sort(array, size); // Calls the function to sort the given array

    int repeated = 1; // Each number exist at least once in the array

    // Variables to check for adjacent elements
    int previous = array[0];
    int current;

    // Since the array is sorted, repeated elements will be grouped together
    // This loop looks at the number of times current and previous are the same,
    // and stores it in the variable repeated

    for (int i = 1; i < size; i++) {
        current = array[i];
        if (previous == current) {
            repeated++;
            continue;
        } else {
            // Control flow reaches here if previous and current elements are different
            if (repeated != 1) {
                // If more than one instance of an elmement exists, then prints the element's count
                printf("%d was repeated %d times\n", previous, repeated);
            }
            // Resets the repeated count and sets the previous value
            repeated = 1;
            previous = current;
        }
    }

    // Edge case handling for the last element in the sorted array
    if (repeated > 1) {
        printf("%d was repeated %d times\n", current, repeated);
    }

    free(array); // Frees the memory allocated to the array
}

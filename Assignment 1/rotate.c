#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Size of array: ");
    scanf("%d", &size);

    // Allocate memory from the heap to the array
    int *arr = calloc(size, sizeof(int));

    // Input elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    //Input the degree to rotate by
    int degree;
    printf("Rotate by: ");
    scanf("%d", &degree);

    // Allocate memory from heap to rotated array
    int *new = calloc(size, sizeof(int));
    int temp; // A temporary variable

    // New index is current_index+degree, but
    // since current_index+degree can go beyond the size of array
    // (current_index + degree) % size is used
    for (int i = 0; i <size; i++){
        temp = (i+degree) % size;
        new[temp] = arr[i];
    }
    // Print the elements of the rotated array
    for (int i = 0; i < size; i++){
        printf("%d ", new[i]);
    }
    // Free the allocated memory from the heap
    free(arr);
    free(new);
}

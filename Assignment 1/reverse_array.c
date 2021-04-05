// Exp 1A; Pranjal Timsina; 20BDS0392

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size){
    // Iterate through the elements of the array and prints it
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void reverse(int *array,int* reversed_array, int size){
    // First element of reversed is the element size-i-0 of the main array
    // Similarly the second element of reversed is the element size-i-1 of the main array
    for (int i = 0; i < size; i++){
        reversed_array[i] = array[size-i-1];
    }
}

int main() {
    int size; // Initialize variable to store size of the array
    printf("Enter the size of the array: "); // Message to user
    scanf("%d", &size); // Read the size from user input

    // Allocate memory for the array from heap
    int *array = calloc(size, sizeof(int));

    // Input elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    //Allocate memory for the reversed array from the heap
    int *reversed_array = calloc(size, sizeof(int));

    // Function call to reverse array
    reverse(array, reversed_array, size);

    // Function call to print the reversed array
    print_array(reversed_array, size);

    // Free the memory used by the array and reversed array
    free(array);
    free(reversed_array);
    return 0;
}

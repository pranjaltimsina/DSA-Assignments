#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int length) {
    // function to iterate through the array and print its content
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int *array, int length){
    // function to implement bubble sort
    int current, next, temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-i-1; j++) {
                if (array[j] > array[j+1]) {
                    temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
        }
    }
}

int main() {
    int size;
    printf("Enter the array size: ");
    scanf("%d", &size);

    // allocating memory for the two arrays
    // list_a is given twice the size so that list_b can be merged later
    int *list_a = calloc(size*2, sizeof(int));
    int *list_b = calloc(size, sizeof(int));

    // input elements
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list_a[i]);
    }
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list_b[i]);
    }

    // merge the two lists
    for (int i = size; i < size*2; i++){
        list_a[i] = list_b[i-size];
    }

    bubble_sort(list_a, size*2); // call function to sort array
    print_array(list_a, size*2); // call function to print array

    // since the size of the merged array is 2*size,
    // the number of items will always be even

    // logic to calculate the median and print it
    double median = ((double) list_a[size-1] + (double) list_a[size]) / 2.0;
    printf("The median is %.2lf.", median);

    // free allocated memory
    free(list_a);
    free(list_b);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size) {
    // function to print array
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int insert(int *array, int *occupied,int size, int position, int data){
    // Start at the position, shift everything cyclically right until a 0 is found
    int found = -1; // initally no empty location is found
    for (int i = position+1;i != position; i = (i+1)%size){
        // loop to check for the first unoccupied location in the array
        if (occupied[i] == 0){
            found = i;
            break;
        }
    }
    if (found == -1){
        // if there are no unoccupied locations return 0 indicating a full array
        return 0;
    } else {
        // start at the empty location and shift all the elements to make space in position
        int current = found;
        int previous;
        while (1) {
            // current index of array takes element from the index left of it
            previous = current - 1;
            // condition to make shifting cyclic
            if (previous < 0) previous = size+previous;
            // swapping elements
            array[current] = array[previous];
            occupied[current] = 1;
            current = previous;
            // if it reaches the required position, breaks
            if (previous == position) break;
        }
    }
    array[position] = data; // inserting data
    return 1; // returning success code
}

int main() {
    // taking user input for size of array
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    // validating input size
    if (size <= 0) {
        printf("Invalid size of array!");
        return -1;
    }

    // allocating memory for the array
    int *array = calloc(size, sizeof(int));
    // allocating memory for array to store whether an index is occupied or not
    int *occupied = calloc(size, sizeof(int));

    // checking for memory allocation failure
    if (array == NULL || occupied == NULL) {
        printf("Could not allocate memory!");
        return -1;
    }

    // variables for index, data
    // temp used for indicating whether to expand array
    int position, data, temp;
    while(1) {
        printf("Enter position (-1 to quit): ");
        scanf("%d", &position);
        // exit condition
        if (position == -1){
            print_array(array, size);
            free(array);
            free(occupied);
            return 0;
        } else if(position >= size || position < -1) {
            // index validation
            printf("Index out of bounds! Try again!\n");
            continue;
        } else {
            printf("Enter data: ");
            scanf("%d", &data);
            if (!occupied[position]) {
                // if unoccupied, directly store data
                array[position] = data;
                occupied[position] = 1;
                printf("Success!\n");
            } else {
                // calls insert function which returns true if success
                // false if array is full
                if (insert(array, occupied,size, position, data)) {
                    printf("Success!\n");
                } else {
                    // asking user to
                    printf("Failed! Array is full! Do you want to resize array? 1 for yes, 0 for no:\n");
                    scanf("%d", &temp);
                    if (temp){
                        // expanding size of array
                        array = realloc(array, size+1);
                        occupied = realloc(occupied, size+1);
                        size++; // incrementing the size of array
                        occupied[size-1] = 0; // changing garbage value to false for new index

                        // validating error in memory allocation
                        if (array == NULL || occupied == NULL) {
                            printf("Could not allocate memory!");
                            free(array);
                            free(occupied);
                            return 0;
                        }
                        // inserting data in array
                        if (insert(array, occupied, size, position, data)){
                            printf("Success!\n");
                        } else {
                            printf("Failure!\n");
                        }
                    } else {
                        // exits if user chooses not to expand full array
                        printf("Exiting the program!");
                        return 0;
                    }
                }
            }
        }
        print_array(array, size);
    }
    // deallocating memory
    free(array);
    free(occupied);
    return 0;
}

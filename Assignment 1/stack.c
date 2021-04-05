// NOTE: I do not know if I have used pointers and memory management "correctly"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *stack;

bool is_empty(int *top_of_stack) {

    if (*top_of_stack == -1 ){
        return true;
    }
    return false;

}

// display_stack(stack, &top_of_stack);
void display_stack(int *stack, int*top_of_stack) {

    if (is_empty(top_of_stack)) {
        printf("Empty Stack\n");
    } else {

        int counter = *top_of_stack -1;

        printf("%d <-- Top of Stack\n", stack[*top_of_stack]);

        while (counter != -1) {
            printf("%d\n", stack[counter]);
            --counter;
        }

    }

}

bool is_full(int *top_of_stack, int *size_of_stack) {

    if (*top_of_stack == *size_of_stack-1) {
        return true;
    }
    return false;

}

// peek(stack, &top_of_stack);
void peek(int *stack, int *top_of_stack) {

    if (is_empty(top_of_stack)) {
        printf("Empty Stack\n");
    } else {
        printf("%d <-- Top of Stack\n", stack[*top_of_stack]);
    }

}

// pop(stack, &top_of_stack)
int pop(int *stack, int *top_of_stack) {

    int return_value = stack[*top_of_stack];
    *top_of_stack = *top_of_stack -1;
    return return_value;

}

void push(int *stack, int *data, int *top_of_stack) {

    stack[*top_of_stack + 1] = *data;
    *top_of_stack = *top_of_stack + 1;

}


void display_menu() {
    printf("1. Display; 2. Peek; 3. Push; 4. Pop; 5. Expand; 6. isFull; 7.isEmpty; 0. Exit\n");
}

int main() {

    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    stack = malloc(size * sizeof(int));
    if (stack == NULL) {
        printf("Could not allocate memory for stack. Failed!");
        return 0;
    }
    int top_of_stack = -1;

    int choice;
    int temp_data;

    for (int i = 0; i < size; i++){
        printf("Enter the data: ");
        scanf("%d", &temp_data);
        push(stack, &temp_data, &top_of_stack);
    }
    printf("Reversed array: \n");
    while (top_of_stack!= -1){
        printf("%d ", pop(stack, &top_of_stack));
    }

    free(stack);

}

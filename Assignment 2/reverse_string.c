// Exp. 2A: Reverse String using a Stack
// Author: Pranjal Timsina; 20BDS0392
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Initialize the stack variable
char *stack;
// Returns if stack is empty
int is_empty(char *top_of_stack) { return (*top_of_stack == -1 ); }
// Returns if stack is full
int is_full(int *top_of_stack, int *size_of_stack) {
    return (*top_of_stack == *size_of_stack-1);
}
// Pop the top value from stack
char pop(char *stack, int *top_of_stack) {
    char return_value = stack[*top_of_stack];
    *top_of_stack = *top_of_stack -1;
    return return_value;
}
// Push new data to stack
void push(char *stack, char *data, int *top_of_stack) {
    stack[++*top_of_stack ] = *data;
}

int main() {
    // initialize and input the string
    char my_string[500];
    scanf("%[^\n]s", &my_string);
    int size = strlen(my_string);
    // allocate memory for the stack
    stack = malloc(size * sizeof(char));
    int top_of_stack = -1;
    // push each character of the string to the stack
    for (int i = 0; i < size; i++) push(stack, &my_string[i], &top_of_stack);
    // pop each character from the stack and print it
    while (top_of_stack!= -1) printf("%c", pop(stack, &top_of_stack));
    free(stack); // free the allocated memory
}

// Exp 2B: Stack using a linked list to store student details
// Author: Pranjal Timsina; 20BDS0392
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Creating a node struct to store details
typedef struct node {
    struct node *next;
    char name[100];
    char reg_no[10];
    int age;
}node;

node *head = NULL; // initilaize head pointer
// adds new data to the stack
void push(char new_name[100], char new_reg_no[10], int new_age) {
    node *new_node;
    new_node = (node *) malloc(sizeof(node));

    strcpy(new_node->name, new_name);
    strcpy(new_node->reg_no,new_reg_no);
    new_node->age = new_age;
    new_node->next = head;
    head = new_node;
}
// pops the data from the stack and prints
void pop() {
    node* current;
    current = head;
    head = head->next;
    printf("%s %s %d\n", current->name, current->reg_no, current->age);
    free(current);
}

int main() {
    char temp_name[100];
    char temp_reg[10];
    int temp_age;
    while (1) {
        printf("Enter name: [0 to quit] ");
        scanf("%[^\n]s", &temp_name);
        getchar(); // gets the trailing whitespace
        if (temp_name[0] == '0') break;

        printf("Enter reg. no: ");
        scanf("%s", &temp_reg);
        getchar(); // gets the trailing whitespace

        printf("Enter age: ");
        scanf("%d", &temp_age);
        getchar(); // gets the trailing whitespace

        push(temp_name, temp_reg, temp_age);
    }

    while (head != NULL) pop();

    return 0;
}

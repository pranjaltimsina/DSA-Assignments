#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
// create a struct for storing student data
typedef struct node {
    struct node *next;
    char name[100];
    char reg_no[10];
    int age;
}node;
// initialize head and tail of the queue
node *head = NULL;
node *tail = NULL;
// function to add new data to the end of queue
void enqueue(char new_name[100], char new_reg_no[10], int new_age) {
    node *new_node;
    new_node = (node *) malloc(sizeof(node));
    strcpy(new_node->name, new_name);
    strcpy(new_node->reg_no,new_reg_no);
    new_node->age = new_age;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
        new_node->next = NULL;
    } else {
        tail->next = new_node;
        tail=new_node;
        tail->next = NULL;
    }
}
// function to remove data from the front queue
void dequeue() {
    node* current;
    current = head;
    head = head->next;
    printf("%s %s %d\n", current->name, current->reg_no, current->age);
    free(current);
}
void menu() {
    printf("1. Add, 2. Remove, 3. Exit\n");
    printf("Exiting will display the whole queue\n");
}

int main() {
    // initialize variables for input
    char temp_name[100];
    char temp_reg[10];
    int temp_age;
    int choice;
    while (1) {
        menu(); // display menu
        scanf("%d",&choice); // get user choice
        getchar();
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%[^\n]s", &temp_name);
                getchar(); // get trailing whitespace
                printf("Enter reg. no: ");
                scanf("%s", &temp_reg);
                getchar(); // get trailing whitespace

                printf("Enter age: ");
                scanf("%d", &temp_age);
                getchar(); // get trailing whitespace

                enqueue(temp_name, temp_reg, temp_age);
                break;
            case 2:
                if (head != NULL) {
                    dequeue();
                }
                break;
            case 3:
                while (head != NULL)
                    dequeue();
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    }
    return 0;
}

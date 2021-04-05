// Exp 2F: Dynamic sales entries
// Author: Pranjal Timsina; 20BDS0392
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct node to store sales detail
typedef struct node {
    struct node *next;
    char product_name[100];
    int product_id; int price;
}node;
// initialize head and tail pointers of the queue
node *head = NULL, *tail = NULL;

void enqueue(char new_name[100], int new_product_id, int new_price) {
    // create a new node and allocate memory
    node *new_node;
    new_node = (node *) malloc(sizeof(node));
    // copy the relevant contents to the struct
    strcpy(new_node->product_name, new_name);
    new_node->product_id = new_product_id;
    new_node->price = new_price;
    if (head == NULL) {
        // if head is NULL, update HEAD and TAIL
        // to point to the current node
        head = new_node;
        tail = new_node;
        new_node->next = NULL; // set the next to NULL
    } else {
        // update the TAIL to point to next node
        tail->next = new_node;
        tail=new_node;
        tail->next = NULL;
    }
}
void dequeue() {
    // reference the current head
    node* current = head;
    head = head->next; // update head pointer
    printf("%d %s %d\n", current->product_id,
        current->product_name, current->price);
    free(current); // free the memory
}

int main() {
    // variables to store user input
    char temp_name[100];
    int temp_price;
    int temp_id;
    while (1) {
        printf("Enter product name: [0 to quit] ");
        scanf("%[^\n]s", &temp_name);
        getchar(); // get trailing whitespace
        if (temp_name[0] == '0') {
            break; // condition to exit
        }
        printf("Enter product ID: ");
        scanf("%d", &temp_id);
        getchar(); // get trailing whitespace
        printf("Enter product price: ");
        scanf("%d", &temp_price);
        getchar(); // get trailing whitespace
        // enqueue with the relevant details
        enqueue(temp_name, temp_id, temp_price);
    }
    while (head != NULL){
        // call the dequeue function which prints
        // data of the dequeued item.
        dequeue();
    }
}

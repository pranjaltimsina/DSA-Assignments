// Exp2H: Solution to Josephus problem
// Author: 20BDS0392; Pranjal Timsina

#include <stdio.h>
#include <stdlib.h>

// define struct Node to store each person
typedef struct Node {
    int data; // data stores the index of the person
    struct node *next;
} Node;

Node *newPerson(int data) { // func to create a newPerson
    Node *new = (Node* ) malloc(sizeof(Node));
    new->next = new;
    new->data = data;
    return new;
}

// main function to solve the problem
void solve(int m, int n) {
    Node *start = newPerson(1); // starting person
    Node *prev = start;

    // loop to create n people
    for (int i = 2; i <= n; i++) {
        prev->next = newPerson(i);
        prev = prev->next;
    }
    prev->next = start; // make the linked list circular
    Node *winner = start, *temp = start; // initizalize two ptrs
    // loop runs while there are multiple people
    while (winner->next != winner)
    {
        // traverse m people
        int count = 1;
        while (count != m)
        {
            temp = winner;
            winner = winner->next;
            count++;
        }
        // prepare kill the mth person
        temp->next = winner->next;
        free(winner); // kill the mth person
        winner = temp->next; // put the next pointer to ptr1
    }
    printf ("Josephus Position is %d", winner->data);
    free(winner);
}


int main() {
    int people, skip;
    printf("Enter number of people and skip value: ");
    scanf("%d%d", &people, &skip);
    solve(skip, people);
    return 0;
}

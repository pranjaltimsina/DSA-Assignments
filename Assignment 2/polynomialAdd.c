// Exp 2J: Polynomial Addition
// Author: Pranjal Timsina; 20BDS0392
#include<stdio.h>
#include<stdlib.h>

struct Node { // def node to store data
    int coeff;
    int pow;
    struct Node* next;
};

void inputPoly(struct Node** poly) {
    int coeff, exp, cont; // temp variables for input

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    *poly = temp;

    do { // ensures loop runs at least once
        printf("Enter the coeffecient and exponent (eg 3 2): ");
        scanf("%d%d", &coeff, &exp);
        temp->coeff = coeff;
        temp->pow = exp;
        temp-> next = NULL; // set next pointer to null
        printf("Enter 0 to terminate, anything else to continue: ");
        scanf("%d", &cont);
        if (cont) { // create new node if more data
            temp->next = (struct Node*)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL; // point the new node to null
        }
    } while(cont);
}

void printPoly(struct Node* poly) {
    while (poly != NULL) { // terminate if pointer is null
        printf("%dx^%d ", poly->coeff, poly->pow);
        poly = poly->next; // traverse
        if(poly != NULL) printf(" + ");
    }
    printf("\n");
}

void addPolynomials(struct Node** result, struct Node* first, struct Node* second) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL; // create node to store result
    *result = temp;
    // loop while the 2 polys are not null
    while (first && second) {
        if(first->pow > second->pow) {
            // add the first node as it is
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        } else if(first->pow < second->pow) {
            // add the second node as it is
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->next;
        } else {
            // add the sum of the two polys
            temp->coeff = first->coeff + second->coeff;
            temp->pow = first->pow;
            first = first->next;
            second = second->next;
        }

        if (first && second) {
            // create another node for result
            temp->next = (struct Node*)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    // if any of the polynomials contain nodes, add them
    while (first || second) {
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->next = NULL;

        if (first) {  // add the remaining elems of 1st poly
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        } else if(second) { // add the remaining elemes of 2nd poly
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->next;
        }
    }
}

int main() {
    // create nodes
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* result = NULL;
    // input data
    printf("Enter the corresponding data:-\n");
    printf("First polynomial:\n");
    inputPoly(&first);
    printPoly(first);
    printf("Second polynomial:\n");
    inputPoly(&second);

    printf("\n The First polynomail is: ");
    printPoly(first);
    printf("The Second polynomial is: ");
    printPoly(second);
    // add the polynomials
    addPolynomials(&result, first, second);
    printf("The Resulting polynomial is: ");
    // print results
    printPoly(result);
    return 0;
}

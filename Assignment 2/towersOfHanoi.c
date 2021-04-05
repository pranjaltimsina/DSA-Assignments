// Exp 2G: Solution to towers of Hanoi
// Author: Pranjal Timsina; 20BDS0392
#include <stdio.h>

//  Moves n discs from tower 'from' to tower 'to' using tower 'aux'
void shift (int discs, int from, int to, int aux) {
    if (discs == 1) // base case for recursion
        printf ("Move  disc %d from %d to  %d\n", discs, from, to);
    else {
        shift (discs-1, from, aux, to); // shift n-1 discs to 'aux' using 'to' as helper
        printf ("Move  disc %d from %d to  %d\n", discs, from, to);
        shift (discs-1, aux, to, from); // shift n-1 discs from 'aux' to 'to' using 'from' as helper
    }
}

int main() {
    int discs;
    printf("Enter discs: "); scanf("%d", &discs);
    shift(discs, 1, 3, 2); // move discs from tower 1 to 3 using 2 as helper
}

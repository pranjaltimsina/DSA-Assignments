#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n], rev[n];
    for (i = 0; i < n; i++) {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }
    // Initialising rev array by traversing arr backwards
    for (i = 0; i < n; i++) {
        rev[i] = arr[n-i-1];
    }
    // Displaying reversed array
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d  ", rev[i]);
    }
    return 0;
}

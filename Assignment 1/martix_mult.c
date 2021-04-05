#include <stdio.h>
#include <stdlib.h>

void print_matrix(int rows, int cols, int matrix[][cols]) {
    // function to print the matrix
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void input_matrix(int rows, int cols, int matrix[][cols]){
    // function to input a matrix
    printf("Enter the matrix:\n");
    for (int i = 0; i < rows; i ++){
        printf("Row %d: ", i);
        for (int j = 0; j < cols; j++){
            scanf(("%d"), &matrix[i][j]);
        }
    }
}

int main() {
    // Initializing the dimensions of the matrices and taking user input
    int row1, row2, col1, col2;
    printf("Enter the dimensions of the first matrix  (eg. `2 3` where 2 -> rows, 3 -> cols): ");
    scanf("%d%d", &row1, &col1);
    printf("Enter the dimensions of the first matrix  (eg. `2 3` where 2 -> rows, 3 -> cols): ");
    scanf("%d%d", &row2, &col2);

    // Error handling for invalid dimensions
    if (col1 != row2) {
        printf("Invalid dimensions.");
        return 0;
    }
    // Declaring the 2D arrays for matrices
    int matrix_a[row1][col1];
    int matrix_b[row2][col2];
    int product[row1][col2];
    // calling the input functions
    input_matrix(row1, col1, matrix_a);
    input_matrix(row2, col2, matrix_b);
    // product[i][j] = A[i][1]B[1][j] + A[i][2]B[2][j]...
    int temp;
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col2; j++) {
            int temp = 0;
            for (int h =0; h < row2;h++){
                temp+= matrix_a[i][h]*matrix_b[h][j];
            }
            product[i][j] = temp;
        }
    }

    printf("Matrix A \n");
    print_matrix(row1, col1, matrix_a);
    printf("Matrix B \n");
    print_matrix(row2, col2, matrix_b);

    printf("Product \n");
    print_matrix(row1, col2, product);
}

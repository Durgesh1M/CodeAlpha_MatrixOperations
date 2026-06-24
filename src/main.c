#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Functions declaration
void inputMatrix(int matrix[MAX][MAX], int row, int col);
void displayMatrix(int matrix[MAX][MAX], int row, int col);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int row, int col);
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int res[MAX][MAX], int row, int col);

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("    CODEALPHA MATRIX OPERATIONS\n");
        printf("===================================\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("\nExiting Matrix Program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Addition
                printf("\nEnter rows and columns for matrices: ");
                scanf("%d %d", &r1, &c1);
                
                printf("\n--- Matrix A ---\n");
                inputMatrix(mat1, r1, c1);
                printf("\n--- Matrix B ---\n");
                inputMatrix(mat2, r1, c1);

                addMatrices(mat1, mat2, result, r1, c1);

                printf("\nResultant Matrix (A + B):\n");
                displayMatrix(result, r1, c1);
                break;

            case 2: // Multiplication
                printf("\nEnter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);

                // Multiplication condition check
                if (c1 != r2) {
                    printf("\nError: Multiplication not possible! Columns of A must equal Rows of B.\n");
                    break;
                }

                printf("\n--- Matrix A ---\n");
                inputMatrix(mat1, r1, c1);
                printf("\n--- Matrix B ---\n");
                inputMatrix(mat2, r2, c2);

                multiplyMatrices(mat1, mat2, result, r1, c1, c2);

                printf("\nResultant Matrix (A * B):\n");
                displayMatrix(result, r1, c2);
                break;

            case 3: // Transpose
                printf("\nEnter rows and columns for the matrix: ");
                scanf("%d %d", &r1, &c1);

                printf("\n--- Input Matrix ---\n");
                inputMatrix(mat1, r1, c1);

                transposeMatrix(mat1, result, r1, c1);

                printf("\nOriginal Matrix:\n");
                displayMatrix(mat1, r1, c1);

                printf("\nTransposed Matrix:\n");
                displayMatrix(result, c1, r1); // Rows and columns interchanged
                break;

            default:
                printf("\nInvalid choice! Please choose between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to input elements into a matrix
void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter elements (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix in proper grid format
void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Addition
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function for Matrix Multiplication
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    // Initializing result matrix with 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
        }
    }

    // Multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function for Matrix Transpose
void transposeMatrix(int matrix[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}

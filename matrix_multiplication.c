#include "matrix_multiplication.h"

void print_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return;
}

int** create_square_matrix(int size) {
    int** matrix = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
    }
    return matrix;
}

void free_square_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix_with_rand(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
    return;
}

int dot_product(int x, int y, int length, int** A, int** B) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += A[x][i] * B[i][y];
    }
    return sum;
}

indices_t* get_indices(int size, indices_t* global_matrix) {

    indices_t* current_indices = malloc(sizeof(indices_t));
    current_indices->x = global_matrix->x;
    current_indices->y = global_matrix->y;

    if (global_matrix->x == size-1 && global_matrix->y == size-1) {
        return current_indices;
    }

    if (global_matrix->x == size-1) {
        global_matrix->x =   0;
        global_matrix->y +=  1;
    } else {
        global_matrix->x +=  1;
    }

    return current_indices;
}
#include "stdio.h"
#include "stdlib.h"

#define DEBUG
#define SIZE 4
#define THREADS 1

typedef struct indices {
    int x, y;
} indices_t;

extern void print_matrix(int** matrix, int size);
extern int** create_square_matrix(int size);
extern void free_square_matrix(int** matrix, int size);
extern void fill_matrix_with_rand(int** matrix, int size);
extern int dot_product(int x, int y, int length, int** A, int** B);
extern indices_t* get_indices(int size, indices_t* global_matrix);
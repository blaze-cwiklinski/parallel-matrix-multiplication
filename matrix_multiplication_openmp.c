#include "matrix_multiplication.h"
#include "omp.h"

int** A = NULL, ** B = NULL, ** C = NULL;

indices_t global_matrix = {.x = 0, .y = 0};

indices_t* local_indices = NULL;
#pragma omp threadprivate(local_indices)
int main(int argc, char** argv) {
    int size = SIZE;
    int num_of_threads = THREADS;
    if (argc > 1) {
        num_of_threads = atoi(argv[1]);
    }
    if (argc > 2) {
        size = atoi(argv[2]);
    }

    A = create_square_matrix(size);
    B = create_square_matrix(size);
    C = create_square_matrix(size);

    fill_matrix_with_rand(A, size);
    fill_matrix_with_rand(B, size);

#ifdef DEBUG
    printf ("\n**DEBUGGING MODE ENABLED**\n\nA:\n");
    print_matrix(A, size);
    printf("B:\n");
    print_matrix(B, size);
#endif

    indices_t* local_indices = NULL;
    #pragma omp parallel for num_threads(num_of_threads)
    for (int i = 0; i < size*size; i++)
    {
        #pragma omp critical 
        {
            local_indices = get_indices(size, &global_matrix);
        }
        C[local_indices->x][local_indices->y] = dot_product(local_indices->x, local_indices->y, size, A, B);       
    }
        

#ifdef DEBUG
    printf("C:\n");
    print_matrix(C, size);
#endif

    free_square_matrix(A, size);
    free_square_matrix(B, size);
    free_square_matrix(C, size);

    return 0;
}

#include "matrix_multiplication.h"
#include "pthread.h"

pthread_mutex_t lock;

int** A = NULL, ** B = NULL, ** C = NULL;

indices_t global_matrix = {.x = 0, .y = 0};

void* compute_element(void* args) {
    int size = *((int*)args);
    indices_t* local_indices = NULL;
    
    while (13) {
        pthread_mutex_lock(&lock);
        local_indices = get_indices(size, &global_matrix);
        pthread_mutex_unlock(&lock);
        C[local_indices->x][local_indices->y] = dot_product(local_indices->x, local_indices->y, size, A, B);       
        if (local_indices->x == size-1 && local_indices->y == size-1) {
            break;
        }
        free(local_indices);
    }
    free(local_indices);

    return NULL;
}

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

    pthread_t* workers = malloc(num_of_threads * sizeof(pthread_t));
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < num_of_threads; i++) {
        pthread_create(&workers[i], NULL, compute_element, (void*)&size);
    }
    for (int i = 0; i < num_of_threads; i++) {
        pthread_join(workers[i], NULL);
    }

#ifdef DEBUG
    printf("C:\n");
    print_matrix(C, size);
#endif

    free(workers);
    pthread_mutex_destroy(&lock);
    free_square_matrix(A, size);
    free_square_matrix(B, size);
    free_square_matrix(C, size);

    return 0;
}

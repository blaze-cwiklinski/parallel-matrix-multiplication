#!/bin/bash

CC=gcc
CFLAGS=-Wall -O3

lib.o: matrix_multiplication.c matrix_multiplication.h
	$(CC) -c -g matrix_multiplication.c -o lib.o

pos: lib.o matrix_multiplication_possix.c
	$(CC) -c -g matrix_multiplication_possix.c
	$(CC) matrix_multiplication_possix.o lib.o $(CFLAGS) -lpthread -o pos

omp: lib.o matrix_multiplication_openmp.c
	$(CC) -c -g matrix_multiplication_openmp.c
	$(CC) matrix_multiplication_openmp.o lib.o $(CFLAGS) -fopenmp -o omp

clean:
	rm -f pos omp *.o
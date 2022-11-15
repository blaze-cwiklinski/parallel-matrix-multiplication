# parallel-matrix-multiplication

## BUILD
to build the program for the POSSIX implementation run:
```bash
make pos
```
to build the program for the OpenMP implementation run:
```bash
make omp
```

## RUN
to run the program, simply type:
```bash
./pos [number_of_threads] [matrix_dimension]
./omp [number_of_threads] [matrix_dimension]
```
e.g.
```bash
./pos 4 1024
./omp 4 1024
```

## DEFAULT SETTINGS 
* number of threads:    1
* matrix size:          4
* "debug" mode is enabled - to disable, simply comment the DEBUG macro definition

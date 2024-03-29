/*
Lab 8 Part III_A
Fall 2018
Name: Terry-Ann SNEED

 * private.c
 * ... illustrates why private variables are needed with OpenMP's parallel for loop
 *
 * Usage: ./private 
 * Exercise: 
 * - Run, noting that the serial program produces correct results
 * - Uncomment line A, recompile/run and compare
 * - Recomment line A, uncomment line B, recompile/run and compare
 */

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 100

int main(int argc, char** argv) {
    int i, j, ok = 1;
    int m[SIZE][SIZE];

    printf("\n");
    // set all array entries to 1
//    #pragma omp parallel for                     // A
//No error when line B is uncommented
// j can now only be accessed by a single thread
    #pragma omp parallel for private(j)          // B
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m[i][j] = 1;
        }
    }

    // test (without using threads)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if ( m[i][j] != 1 ) {
                printf("Element [%d,%d] not set... \n", i, j);
                ok = 0;
            }
        }
    }

    if ( ok ) {
        printf("\nAll elements correctly set to 1\n\n");
    }

    return 0;
}


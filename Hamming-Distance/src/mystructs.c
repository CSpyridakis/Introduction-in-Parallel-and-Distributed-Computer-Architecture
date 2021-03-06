#include "../include/mystructs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>


double gettime() {
    struct timeval ttime;
    gettimeofday(&ttime, NULL);
    return ttime.tv_sec + ttime.tv_usec * 0.000001;

}

int **init2dArray(int a, int b) {
    int i, j;
    int **serV;

    /// Allocate memory for array
    serV = (int **) malloc(sizeof(int *) * a);
    for (i = 0; i < a; i++) {
        serV[i] = (int *) malloc(sizeof(int) * b);
    }

    /// Initialize Array
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            serV[i][j] = 0;
        }
    }
    return serV;
}

void structsGenerate(structs *src, int alen, int blen, int strlen) {
    int i, j;

    /// Copy main Values
    src->Alen = alen;
    src->Blen = blen;
    src->Strlen = strlen;

    // Initialize random
    if(SEED==RANDOM){
        srand(time(NULL));
    }
    else{
        srand(SEED);
    }


    /// Create two 2d RANDOM char arrays
    src->A = (char **) malloc(sizeof(char *) * src->Alen);
    for (i = 0; i < src->Alen; i++) {
        src->A[i] = (char *) malloc(sizeof(char) * src->Strlen);
        for (j = 0; j < src->Strlen; j++) {
            src->A[i][j] = (rand() % 2) + '0';
        }
    }
    src->B = (char **) malloc(sizeof(char *) * src->Blen);
    for (i = 0; i < src->Blen; i++) {
        src->B[i] = (char *) malloc(sizeof(char) * src->Strlen);
        for (j = 0; j < src->Strlen; j++) {
            src->B[i][j] = (rand() % 2) + '0';
        }
    }
}

void deallsrc(structs *src) {
    int i;
    for (i = 0; i < src->Alen; i++) {
        free(src->A[i]);
    }
    for (i = 0; i < src->Blen; i++) {
        free(src->B[i]);
    }
    free(src->A);
    free(src->B);
    free(src);
}

void dealhamm(int m,int n, int ** hammta){
    int i;

    for (i = 0; i < m; i++) {
        free(hammta[i]);
    }
    free(hammta);
}

void printResults(hammingTimes *hammT) {
    //TODO MAIN LOGIC
}

void displayHammingValues(int alen, int blen, int **serV) {
    int i, j;
    for (i = 0; i < alen; i++) {
        for (j = 0; j < blen; j++) {
            printf("|%6d", serV[i][j]);
        }
        printf("|\n");
    }
}

unsigned long long calcSumOfArray(int alen, int blen, int **hamV) {
    int i, j;
    unsigned long long sum = 0;
    for (i = 0; i < alen; i++) {
        for (j = 0; j < blen; j++) {
            sum += hamV[i][j];
        }
    }
    return sum;
}
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Choose what kind of data structure you want to use below
// File contain function for initualizing database

#include "CRD.h"

void init_HASHTABLE_CR(HASHTABLE_CR hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_CP(HASHTABLE_CP hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_SNAP(HASHTABLE_SNAP hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_CDH(HASHTABLE_CDH hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_CSG(HASHTABLE_CSG hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_PRO(HASHTABLE_PRO hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_CNDH(HASHTABLE_CNDH hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void init_HASHTABLE_CRDH(HASHTABLE_CRDH hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}


void init_HASHTABLE_PRO_DAY_HOUR(HASHTABLE_PRO_DAY_HOUR hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

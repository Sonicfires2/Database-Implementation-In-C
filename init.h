#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Choose what kind of data structure you want to use below
// I am using the CRD.h because I want to use pointer, the array shit is harder to use + annoying
// File contain function for initualizing database

//#include "Relation.h"

#include "CRD.h"

void init_HASHTABLE_CR(HASHTABLE_CR hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = new_TUPLELIST_CR("","");
    }
}

void init_HASHTABLE_CP(HASHTABLE_CP hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = new_TUPLELIST_CP("","");
    }
}

void init_HASHTABLE_SNAP(HASHTABLE_SNAP hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = new_TUPLELIST_SNAP("","","","");
    }
}

void init_HASHTABLE_CDH(HASHTABLE_CDH hashtable) {
    for(int i=0; i<DATABASE_SIZE; i++) {
        hashtable[i] = new_TUPLELIST_CDH("","","");
    }
}

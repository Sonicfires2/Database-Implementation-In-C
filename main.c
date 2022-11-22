#include <stdio.h>
//#include "CRD.h"
#include "part1.h"

//assignment as global variable
HASHTABLE_CR htcr;
HASHTABLE_SNAP htsnap;
HASHTABLE_CDH htcdh;
HASHTABLE_CP htcp;

int main() {
    printf("Hello, World!\n");
    // init
//    init_HASHTABLE_CR(htcr);
//    init_HASHTABLE_CP(htcp);
//    init_HASHTABLE_CDH(htcdh);
//    init_HASHTABLE_SNAP(htsnap);
    // assignment
    TUPLELIST_CR crTemp = new_TUPLELIST_CR("CSC173", "MOREY 203");
    insert_CR(crTemp,htcr);
    int h = hash(concat(crTemp->Course,crTemp->Room));

    // print
    printf("Class %s is in %s stored at location: %d\n", htcr[h]->Course, htcr[h]->Room, h);

    return 0;


}

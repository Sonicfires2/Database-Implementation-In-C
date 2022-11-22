#include "init.h"

void insert_CR(TUPLELIST_CR cr, HASHTABLE_CR ht) {
    int h = hash(cr->Course);
    ht[h] = cr;
}

void insert_SNAP(TUPLELIST_SNAP snap, HASHTABLE_SNAP ht) {
    int h = hash(concat(snap->StudentId,snap->Phone));
    ht[h] = snap;
}

void insert_CDH(TUPLELIST_CDH cdh, HASHTABLE_CDH ht) {
    int h = hash(concat(cdh->Course,cdh->Hour));
    ht[h] = cdh;
}

void insert_CP(TUPLELIST_CDH cp, HASHTABLE_CDH ht) {
    int h = hash(cp->Course);
    ht[h] = cp;
}

//cr used c = Course to hash => Need to check whether c is '*' or not
TUPLELIST_CR lookup_CR(char* c, char* r,HASHTABLE_CR ht) {
    TUPLELIST_CR pointer;
    TUPLELIST_CR last;
    TUPLELIST_CR result = NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(r,pointer->Room)==0 || r[0]=='*')) {
                if (result == NULL) {
                    result = new_TUPLELIST_CR(pointer->Course,pointer->Room);
                    last = result;
                } else {
                    last->next = new_TUPLELIST_CR(pointer->Course,pointer->Room);
                }
            }
            pointer = pointer->next;
        }
    }
    return result;
}

TUPLELIST_SNAP lookup_SNAP(char* s, char* n, char* a, char* p,HASHTABLE_SNAP ht) {
    TUPLELIST_SNAP pointer;
    TUPLELIST_SNAP last;
    TUPLELIST_SNAP result = NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(s,pointer->StudentId) == 0 || s[0] == '*') && (strcmp(n,pointer->Name)==0 || n[0]=='*') && (strcmp(a,pointer->Address)==0 || a[0]=='*') && (strcmp(p,pointer->Phone)==0 || p[0]=='*')) {
                if (result == NULL) {
                    result = new_TUPLELIST_SNAP(pointer->StudentId,pointer->Name,pointer->Address,pointer->Phone);
                    last = result;
                } else {
                    last->next = new_TUPLELIST_SNAP(pointer->StudentId,pointer->Name,pointer->Address,pointer->Phone);
                }
            }
            pointer = pointer->next;
        }
    }
    return result;
}

TUPLELIST_CP lookup_CP(char* c, char* p,HASHTABLE_CP ht) {
    TUPLELIST_CP pointer;
    TUPLELIST_CP last;
    TUPLELIST_CP result = NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(p,pointer->PCourse)==0 || p[0]=='*')) {
                if (result == NULL) {
                    result = new_TUPLELIST_CP(pointer->Course,pointer->PCourse);
                    last = result;
                } else {
                    last->next = new_TUPLELIST_CP(pointer->Course,pointer->PCourse);
                }
            }
            pointer = pointer->next;
        }
    }
    return result;
}

TUPLELIST_CDH lookup_CDH(char* c, char* d, char* h,HASHTABLE_CDH ht) {
    TUPLELIST_CDH pointer;
    TUPLELIST_CDH last;
    TUPLELIST_CDH result = NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(d,pointer->Day)==0 || d[0]=='*') && (strcmp(h,pointer->Hour)==0 || h[0]=='*')) {
                if (result == NULL) {
                    result = new_TUPLELIST_CDH(pointer->Course,pointer->Day,pointer->Hour);
                    last = result;
                } else {
                    last->next = new_TUPLELIST_CDH(pointer->Course,pointer->Day,pointer->Hour);
                }
            }
            pointer = pointer->next;
        }
    }
    return result;
}

void delete_CR(char* c, char* r, HASHTABLE_CR ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CR pointer = ht[i];
        do {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(r,pointer->Room)==0 || r[0]=='*')) {
                free(ht[i]->Course);
                free(ht[i]->Room);
                free(ht[i]);
//                ht[i]->Course = "";
//                ht[i]->Room = "";
            }
            pointer = pointer->next;
        } while (pointer != NULL);
    }
}

void delete_SNAP(char* s, char* n, char* a, char* p, HASHTABLE_SNAP ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_SNAP pointer = ht[i];
        do {
            if ((strcmp(s,pointer->StudentId) == 0 || s[0] == '*') && (strcmp(n,pointer->Name)==0 || n[0]=='*') && (strcmp(a,pointer->Address) == 0 || a[0] == '*') && (strcmp(p,pointer->Phone)==0 || p[0]=='*')) {
                free(ht[i]->StudentId);
                free(ht[i]->Name);
                free(ht[i]->Address);
                free(ht[i]->Phone);
//                ht[i]->StudentId = "";
//                ht[i]->Name = "";
//                ht[i]->Address = "";
//                ht[i]->Phone = "";
            }
            pointer = pointer->next;
        } while (pointer != NULL);
    }
}

void delete_CDH(char* c, char* d, char* h, HASHTABLE_CDH ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CDH pointer = ht[i];
        do {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(d,pointer->Day)==0 || d[0]=='*') && (strcmp(h,pointer->Hour)==0 || h[0]=='*')) {
                free(ht[i]->Course);
                free(ht[i]->Day);
                free(ht[i]->Hour);
                free(ht[i]);
//                ht[i]->Course = "";
//                ht[i]->Day = "";
//                ht[i]->Hour = "";
            }
            pointer = pointer->next;
        } while (pointer != NULL);
    }
}

void delete_CP(char* c, char* p, HASHTABLE_CP ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CP pointer = ht[i];
        do {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(p,pointer->PCourse)==0 || p[0]=='*')) {
                free(ht[i]->Course);
                free(ht[i]->PCourse);
                free(ht[i]);
//                ht[i]->Course = "";
//                ht[i]->PCourse = "";
            }
            pointer = pointer->next;
        } while (pointer != NULL);
    }
}

void print_CR(HASHTABLE_CR ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i]){
            printf("hi");
        }
    }
}

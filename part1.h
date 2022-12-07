#include "init.h"

void insert_CR(TUPLELIST_CR cr, HASHTABLE_CR ht) {
    int h = hash(cr->Course);
    if (ht[h] == NULL) {
        ht[h] = cr;
    } else {
        TUPLELIST_CR a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = cr;
        // free_CR_index(a);
    }
}

void insert_SNAP(TUPLELIST_SNAP snap, HASHTABLE_SNAP ht) {
    int h = hash(snap->StudentId);
    if (ht[h] == NULL) {
        ht[h] = snap;
    } else {
        TUPLELIST_SNAP a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = snap;
        // free_SNAP_index(a);
    }
}

void insert_CDH(TUPLELIST_CDH cdh, HASHTABLE_CDH ht) {
    char str[100];
    strcpy(str,cdh->Course);
    strcat(str, cdh->Day);
    int h = hash(str);
    if (ht[h] == NULL) {
        ht[h] = cdh;
    } else {
        TUPLELIST_CDH a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = cdh;
        // free_CDH_index(a);
    }
}

void insert_CP(TUPLELIST_CP cp, HASHTABLE_CP ht) {
    int h = hash(cp->Course);
    if (ht[h] == NULL) {
        ht[h] = cp;
    } else {
        TUPLELIST_CP a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = cp;
        // free_CP_index(a);
    }
}

void insert_CSG(TUPLELIST_CSG csg, HASHTABLE_CSG ht) {
    char str[100];
    strcpy(str,csg->Course);
    strcat(str, csg->StudentId);
    int h = hash(str);
    if (ht[h] == NULL) {
        ht[h] = csg;
    } else {
        TUPLELIST_CSG a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = csg;
        // free_CP_index(a);
    }
}

void insert_PRO(TUPLELIST_PRO pro, HASHTABLE_PRO ht) {
    int h = hash(pro->Content);
    if (ht[h] == NULL) {
        ht[h] = pro;
    } else {
        TUPLELIST_PRO a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = pro;
        // free_CP_index(a);
    }
}

void insert_CRDH(TUPLELIST_CRDH crdh, HASHTABLE_CRDH ht) {
    char str[100];
    strcpy(str,crdh->Course);
    strcat(str, crdh->Day);
    int h = hash(str);
    if (ht[h] == NULL) {
        ht[h] = crdh;
    } else {
        TUPLELIST_CRDH a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = crdh;
        // free_CP_index(a);
    }
}

void insert_PRO_DAY_HOUR(TUPLELIST_PRO_DAY_HOUR pdh, HASHTABLE_PRO_DAY_HOUR ht) {
    char str[100];
    strcpy(str,pdh->Day);
    strcat(str, pdh->Hour);
    int h = hash(str);
    if (ht[h] == NULL) {
        ht[h] = pdh;
    } else {
        TUPLELIST_PRO_DAY_HOUR a = ht[h];
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = pdh;
        // free_CP_index(a);
    }
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
                    last = last->next;
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
                    last = last->next;
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
                    last = last->next;
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
                    last = last->next;
                }
            }
            pointer = pointer->next;
        }
    }
    return result;
}

TUPLELIST_CSG lookup_CSG(char* c, char* s, char* g,HASHTABLE_CSG ht) {
    TUPLELIST_CSG pointer;
    TUPLELIST_CSG last;
    TUPLELIST_CSG result = NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(s,pointer->StudentId)==0 || s[0]=='*') && (strcmp(g,pointer->Grade)==0 || g[0]=='*')) {
                if (result == NULL) {
                    result = new_TUPLELIST_CSG(pointer->Course,pointer->StudentId,pointer->Grade);
                    last = result;
                } else {
                    last->next = new_TUPLELIST_CSG(pointer->Course,pointer->StudentId,pointer->Grade);
                    last = last->next;
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
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(r,pointer->Room)==0 || r[0]=='*')) {
                ht[i] = pointer->next;
                pointer = NULL;
                pointer = ht[i];
            } else {
                pointer = pointer->next;
            }
        }
    }
}

void delete_SNAP(char* s, char* n, char* a, char* p, HASHTABLE_SNAP ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_SNAP pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(s,pointer->StudentId) == 0 || s[0] == '*') && (strcmp(n,pointer->Name)==0 || n[0]=='*')  && (strcmp(a,pointer->Address)==0 || a[0]=='*') && (strcmp(p,pointer->Phone)==0 || p[0]=='*')) {
                ht[i] = pointer->next;
                pointer = NULL;
                pointer = ht[i];
            } else {
                pointer = pointer->next;
            }
        }
    }
}

void delete_CSG(char* c, char* s, char* g, HASHTABLE_CSG ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CSG pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(s,pointer->StudentId)==0 || s[0]=='*')  && (strcmp(g,pointer->Grade)==0 || g[0]=='*')) {
                ht[i] = pointer->next;
                pointer = NULL;
                pointer = ht[i];
            } else {
                pointer = pointer->next;
            }
        }
    }
}

void delete_CDH(char* c, char* d, char* h, HASHTABLE_CDH ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CDH pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(d,pointer->Day)==0 || d[0]=='*')  && (strcmp(h,pointer->Hour)==0 || h[0]=='*')) {
                ht[i] = pointer->next;
                pointer = NULL;
                pointer = ht[i];
            } else {
                pointer = pointer->next;
            }
        }
    }
}

void delete_CP(char* c, char* p, HASHTABLE_CP ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CP pointer = ht[i];
        while (pointer != NULL) {
            if ((strcmp(c,pointer->Course) == 0 || c[0] == '*') && (strcmp(p,pointer->PCourse)==0 || p[0]=='*')) {
                ht[i] = pointer->next;
                pointer = NULL;
                pointer = ht[i];
            } else {
                pointer = pointer->next;
            }
        }
    }
}

void print_CR(TUPLELIST_CR cr) {
    if (cr == NULL) return;
    TUPLELIST_CR temp_CR;
    temp_CR = cr;
    do {
        printf("%s %s\n", temp_CR->Course, temp_CR->Room);
        temp_CR = temp_CR->next;
    } while (temp_CR != NULL);
}

void print_SNAP(TUPLELIST_SNAP snap) {
    if (snap == NULL) return;
    TUPLELIST_SNAP temp_SNAP;
    temp_SNAP = snap;
    do {
        printf("%s %s %s %s\n", temp_SNAP->StudentId, temp_SNAP->Name, temp_SNAP->Address, temp_SNAP->Phone);
        temp_SNAP = temp_SNAP->next;
    } while (temp_SNAP != NULL);
}

void print_CP(TUPLELIST_CP cp) {
    if (cp == NULL) return;
    TUPLELIST_CP temp_CP;
    temp_CP = cp;
    do {
        printf("%s %s\n", temp_CP->Course, temp_CP->PCourse);
        temp_CP = temp_CP->next;
    } while (temp_CP != NULL);
}

void print_CDH(TUPLELIST_CDH cdh) {
    if (cdh == NULL) return;
    TUPLELIST_CDH temp_CDH;
    temp_CDH = cdh;
    do {
        printf("%s %s %s\n", temp_CDH->Course, temp_CDH->Day, temp_CDH->Hour);
        temp_CDH = temp_CDH->next;
    } while (temp_CDH != NULL);
}

void print_CSG(TUPLELIST_CSG csg) {
    if (csg == NULL) return;
    TUPLELIST_CSG temp_CSG;
    temp_CSG = csg;
    do {
        printf("%s %s %s\n", temp_CSG->StudentId, temp_CSG->Course, temp_CSG->Grade);
        temp_CSG = temp_CSG->next;
    } while (temp_CSG != NULL);
}

void print_CNDH(TUPLELIST_CNDH cndh) {
    if (cndh == NULL) return;
    TUPLELIST_CNDH temp_CNDH;
    temp_CNDH = cndh;
    do {
        printf("%s %s %s %s\n", temp_CNDH->Name, temp_CNDH->CourseLocation, temp_CNDH->Hour, temp_CNDH->Day);
        temp_CNDH = temp_CNDH->next;
    } while (temp_CNDH != NULL);
}

void print_PRO(TUPLELIST_PRO pro) {
    if (pro == NULL) return;
    TUPLELIST_PRO temp_PRO;
    temp_PRO = pro;
    do {
        printf("%s\n", temp_PRO->Content);
        temp_PRO = temp_PRO->next;
    } while (temp_PRO != NULL);
}

void print_CRDH(TUPLELIST_CRDH pro) {
    if (pro == NULL) return;
    TUPLELIST_CRDH temp_CRDH;
    temp_CRDH = pro;
    do {
        printf("%s %s %s %s\n", temp_CRDH->Course, temp_CRDH->Room, temp_CRDH->Day, temp_CRDH->Hour);
        temp_CRDH = temp_CRDH->next;
    } while (temp_CRDH != NULL);
}

void print_PRO_DAY_HOUR(TUPLELIST_PRO_DAY_HOUR pro) {
    if (pro == NULL) return;
    TUPLELIST_PRO_DAY_HOUR temp_PRO_DAY_HOUR;
    temp_PRO_DAY_HOUR = pro;
    do {
        printf("%s %s\n", temp_PRO_DAY_HOUR->Day, temp_PRO_DAY_HOUR->Hour);
        temp_PRO_DAY_HOUR = temp_PRO_DAY_HOUR->next;
    } while (temp_PRO_DAY_HOUR != NULL);
}

void print_CR_DATABASE(HASHTABLE_CR ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_CR(ht[i]);
        }
    }
}

void print_SNAP_DATABASE(HASHTABLE_SNAP snap) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (snap[i] != NULL) {
            print_SNAP(snap[i]);
        }
    }
}

void print_CP_DATABASE(HASHTABLE_CP ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_CP(ht[i]);
        }
    }
}

void print_CDH_DATABASE(HASHTABLE_CDH ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_CDH(ht[i]);
        }
    }
}

void print_CSG_DATABASE(HASHTABLE_CSG ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_CSG(ht[i]);
        }
    }
}

void print_CNDH_DATABASE(HASHTABLE_CNDH ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_CNDH(ht[i]);
        }
    }
}

void print_PRO_DATABASE(HASHTABLE_PRO ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_PRO(ht[i]);
        }
    }
}

void print_CRDH_DATABASE(HASHTABLE_CRDH ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_CRDH(ht[i]);
        }
    }
}

void print_PRO_DAY_HOUR_DATABASE(HASHTABLE_PRO_DAY_HOUR ht) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (ht[i] != NULL) {
            print_PRO_DAY_HOUR(ht[i]);
        }
    }
}

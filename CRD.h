#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define DATABASE_SIZE 1009

//idk how to change file name in CLion :> so the name is CRD
//file contain relations defined with pointer, not with array like in example, professor said ok

//maybe for extra cerdit
//Generalization
//typedef struct BUCKET* BUCKET;
//struct BUCKET{
//    void* contents;
//};
//
//typedef struct GEN_HASHTABLE* GEN_HASHTABLE;
//struct GEN_HASHTABLE{
//    char schema;
//    int size;
//    int entries;
//    BUCKET buckets[DATABASE_SIZE];
//};

//ultility functions
int hash(char* str){
    int hash=0;
    for(int i=0; i<strlen(str); i++){
        hash+=str[i];
    }
    return (hash%DATABASE_SIZE);
}

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


////1. {StudentId, Name, Address, Phone}. The student whose ID appears in the
////        first component of a tuple has name, address, and phone number equal to the
////        values appearing in the second, third, and fourth components, respectively
typedef struct TUPLE_SNAP* TUPLELIST_SNAP;
struct TUPLE_SNAP {
    char* StudentId;
    char* Name;
    char* Address;
    char* Phone;
    TUPLELIST_SNAP next;
};
typedef TUPLELIST_SNAP HASHTABLE_SNAP[DATABASE_SIZE];

////2. {Course, Prerequisite}. The course named in the second component of a tuple
////is a prerequisite for the course named in the first component of that tuple
typedef struct TUPLE_CP* TUPLELIST_CP;
struct TUPLE_CP {
    char* Course;
    char* PCourse;
    TUPLELIST_CP next;
};
typedef TUPLELIST_CP HASHTABLE_CP[DATABASE_SIZE];

////3. {Course, Day, Hour}. The course named in the first component meets on
////        the day specified by the second component, at the hour named in the third component.
typedef struct TUPLE_CDH* TUPLELIST_CDH;
struct TUPLE_CDH {
    char* Course;
    char* Day;
    char* Hour;
    TUPLELIST_CDH next;
};
typedef TUPLELIST_CDH HASHTABLE_CDH[DATABASE_SIZE];

//BUCKET new_BUCKET(void* contents){
//    BUCKET b = (BUCKET)malloc(sizeof(BUCKET));
//    b->contents = contents;
//    return b;
//}
//
//GEN_HASHTABLE new_GEN_HASHTABLE(char s){
//    GEN_HASHTABLE h = (GEN_HASHTABLE)malloc(sizeof(struct GEN_HASHTABLE));
//    h->schema = s;
//    h->entries = 0;
//    h->size = DATABASE_SIZE;
//    for(int i=0; i<DATABASE_SIZE; i++){
//        h->buckets[i] = new_BUCKET(NULL);
//    }
//    return h;
//}

////4. {Course, Room}. The course named in the first component meets in the room
////        indicated by the second component
typedef struct TUPLE_CR* TUPLELIST_CR;
struct TUPLE_CR {
    char* Course;
    char* Room;
    TUPLELIST_CR next;
};
typedef TUPLELIST_CR HASHTABLE_CR[DATABASE_SIZE];

TUPLELIST_SNAP new_TUPLELIST_SNAP(char* s, char* n, char* a, char* p) {
    TUPLELIST_SNAP t = (TUPLELIST_SNAP) malloc(sizeof(TUPLELIST_SNAP));
    t->StudentId = s;
    t->Name = n;
    t->Address = a;
    t->Phone = p;
    t->next = NULL;
    return t;
}

TUPLELIST_CP new_TUPLELIST_CP(char* c, char* p) {
    TUPLELIST_CP t = (TUPLELIST_CP) malloc(sizeof(TUPLELIST_CP));
    t->Course = c;
    t->PCourse = p;
    t->next = NULL;
    return t;
}

TUPLELIST_CDH new_TUPLELIST_CDH(char* c, char* d, char* h) {
    TUPLELIST_CDH t = (TUPLELIST_CDH) malloc(sizeof(TUPLELIST_CDH));
    t->Course = c;
    t->Day = d;
    t->Hour = h;
    t->next = NULL;
    return t;
}

TUPLELIST_CR new_TUPLELIST_CR(char* c, char* r) {
    TUPLELIST_CR t = (TUPLELIST_CR) malloc(sizeof(TUPLELIST_CR));
    t->Course = c;
    t->Room = r;
    t->next = NULL;
    return t;
}

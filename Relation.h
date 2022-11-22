#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define DATABASE_SIZE 1009

int hash(char* str){
    int hash=0;
    for(int i=0; i<strlen(str); i++){
        hash+=str[i];
    }
    return (hash%DATABASE_SIZE);
}

////1. {StudentId, Name, Address, Phone}. The student whose ID appears in the
////        first component of a tuple has name, address, and phone number equal to the
////        values appearing in the second, third, and fourth components, respectively
typedef struct TUPLE_SNAP* TUPLELIST_SNAP;
struct TUPLE_SNAP {
    int StudentId;
    char Name[30];
    char Address[50];
    char Phone[8];
    TUPLELIST_SNAP next;
};
typedef TUPLELIST_SNAP HASHTABLE_SNAP[DATABASE_SIZE];

////2. {Course, Prerequisite}. The course named in the second component of a tuple
////is a prerequisite for the course named in the first component of that tuple
typedef struct TUPLE_CP* TUPLELIST_CP;
struct TUPLE_CP {
    char Course[6];
    char PCourse[6];
    TUPLELIST_CP next;
};
typedef TUPLELIST_CP HASHTABLE_CP[DATABASE_SIZE];

////3. {Course, Day, Hour}. The course named in the first component meets on
////        the day specified by the second component, at the hour named in the third component.
typedef struct TUPLE_CDH* TUPLELIST_CDH;
struct TUPLE_CDH {
    char Course[6];
    char Day[2];
    char Hour[4];
    TUPLELIST_CDH next;
};
typedef TUPLELIST_CDH HASHTABLE_CDH[DATABASE_SIZE];

////4. {Course, Room}. The course named in the first component meets in the room
////        indicated by the second component
typedef struct TUPLE_CR* TUPLELIST_CR;
struct TUPLE_CR {
    char Course[6];
    char Room[20];
    TUPLELIST_CR next;
};
typedef TUPLELIST_CR HASHTABLE_CR[DATABASE_SIZE];

extern TUPLELIST_SNAP new_TUPLELIST_SNAP();
extern TUPLELIST_CP new_TUPLELIST_CP();
extern TUPLELIST_CDH new_TUPLELIST_CDH();
extern TUPLELIST_CR new_TUPLELIST_CR();

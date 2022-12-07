#include <stdio.h>
#include "part3.h"

HASHTABLE_CR htcr;
HASHTABLE_SNAP htsnap;
HASHTABLE_CDH htcdh;
HASHTABLE_CP htcp;
HASHTABLE_CSG htcsg;

void Part2_1(char* name,char* course){
    TUPLELIST_CSG pointer;
    TUPLELIST_CSG pointer2;
    TUPLELIST_SNAP SNAP;
    SNAP = lookup_SNAP("*",name,"*","*",htsnap);
    if (SNAP == NULL) {
        printf("Nil -No User found\n");
        return ;
    }
//    print_SNAP(SNAP);
    printf("1\n");
//    printf("%s %s\n",SNAP->next->StudentId,SNAP->StudentId);
    if (SNAP->next != NULL) {
//        printf("1.1\n");
        pointer = lookup_CSG(course, SNAP->StudentId,"*",htcsg);
        pointer2 = lookup_CSG(course, SNAP->next->StudentId,"*",htcsg);
//        print_CSG(pointer);
        if(pointer==NULL){
//            printf("1.1 first cond\n");
            printf("Nil -No Course found\n");
            return;
        } else if (pointer != NULL && pointer2 == NULL) {
//            printf("1.2 Second cond\n");
            printf("The grade of the person in question inside the course is: %s\n",pointer->Grade);
            return;
        } else if (pointer != NULL && pointer2 != NULL){
//            printf("1.3 Third cond\n");
            printf("The grade of the person in question inside the course is: %s\n",pointer->Grade);
            printf("The grade of a person with similar name who is the same course is: %s\n",pointer2->Grade);
            return;
        }
    } else if (SNAP->next == NULL) {
//        printf("2 Snap->next is NULL\n");
        pointer = lookup_CSG(course, SNAP->StudentId,"*",htcsg);
//        print_CSG(pointer);
        if(pointer==NULL){
//            printf("2.1 pointer null\n");
            printf("Nil -No Course found\n");
            return;
        } else {
//            printf("2.2 final esle\n");
            printf("The grade of the person in question inside the course is: %s\n",pointer->Grade);
            return;
        }
        return;
    }
    return;
}


void Part2_1_REPL(){
    printf("\n CSC173 Project 4 :Where is Name's grade in Course?\n");
    while(true){
        char *point;
        printf("\n Enter an input Name(\"quit\" to quit):");
        char IN1[128];
        fgets(IN1,128,stdin);
        point = strchr(IN1, '\n');
        if (point) {
            *point = '\0';
        }
        if(strcmp(IN1,"quit") == 0) {
            return;
        }
        printf("Enter an input Course:");
        char IN2[128];
        fgets(IN2,128,stdin);
        point = strchr(IN2, '\n');
        if (point) {
            *point = '\0';
        }
        if(strcmp("quit", IN1) == 0){
            break;
        }
        Part2_1(IN1,IN2);
    }
}


void Part2_2(char* name,char* day,char* hour){
    TUPLELIST_CSG pointer;
    TUPLELIST_CDH CDH = NULL;
    //Take htsnap as hashTabel to lookup Name -> StudentId
    TUPLELIST_SNAP SNAP=lookup_SNAP("*", name, "*", "*",htsnap);
    if(SNAP==NULL){
        printf("Nil -No User found\n");
        return ;
    }
    TUPLELIST_CSG CSG=lookup_CSG("*",SNAP->StudentId, "*",htcsg);
    if(CSG==NULL){
        printf("Nil -No ID found\n");
        return ;
    }
    pointer = CSG;
    do{
        CDH=lookup_CDH(pointer->Course,day,hour,htcdh);
        if(CDH!=NULL){
            TUPLELIST_CR CR=lookup_CR(CDH->Course,"*",htcr);
            printf("The person in question is in %s at the time being questioned\n",CR->Room);
            return ;
        }
        pointer = pointer->next;
    }while(pointer!=NULL || CDH!=NULL);

    if(CDH==NULL){
        printf("Nil -No Course on that time found \n");
        return ;
    }
    return ;
}

void Part2_2_REPL(){
    printf("\n CSC173 Project 4 :Where is Name at Hour on Day?\n");
    while(true){
        char *point;
        printf("\n Enter an input Name(\"quit\" to quit):");
        char IN1[128];
        fgets(IN1,128,stdin);
        point = strchr(IN1, '\n');
        if (point) {
            *point = '\0';
        }
        if(strcmp(IN1,"quit") == 0) {
            return;
        }
        printf("Enter an input Day:");
        char IN2[128];
        fgets(IN2,128,stdin);
        point = strchr(IN2, '\n');
        if (point) {
            *point = '\0';
        }
        printf("Enter an input Hours:");
        char IN3[128];
        fgets(IN3,128,stdin);
        point = strchr(IN3, '\n');
        if (point) {
            *point = '\0';
        }
        // printf("%s:",IN1);
        // printf("%s:",IN2);
        // printf("%s:",IN3);
        if(strcmp("quit", IN1) == 0){
            break;
        }
        Part2_2(IN1,IN2,IN3);
    }
}


//assignment as global variable

int main() {
    printf("Part 1!\n");
    // init
    init_HASHTABLE_CR(htcr);
    init_HASHTABLE_CP(htcp);
    init_HASHTABLE_CDH(htcdh);
    init_HASHTABLE_SNAP(htsnap);
    init_HASHTABLE_CSG(htcsg);
    //
    insert_CSG(new_TUPLELIST_CSG("CSC171","12345","A"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("CSC171","67890","B"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("MATH150","12345","A"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("DSCC201","12345","C"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("DSCC201","11111","B+"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("CSC172","98789","A-"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("MATH150","67890","C+"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("CSC173","98789","A"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("CSC173","12321","B+"),htcsg);
    insert_CSG(new_TUPLELIST_CSG("DSCC201","98789","C"),htcsg);

    insert_CR(new_TUPLELIST_CR("CSC171","Hutchison Hall 141"),htcr);
    insert_CR(new_TUPLELIST_CR("CSC172","Hutchison Hall 141"),htcr);
    insert_CR(new_TUPLELIST_CR("CSC173","Wegmans 1400"),htcr);
    insert_CR(new_TUPLELIST_CR("CSC252","Wegmans 1400"),htcr);
    insert_CR(new_TUPLELIST_CR("CSC254","Wegmans 1400"),htcr);
    insert_CR(new_TUPLELIST_CR("DSCC201","Bausch & Lomb 109"),htcr);
    insert_CR(new_TUPLELIST_CR("DSCC202","Dewey 2162"),htcr);
    insert_CR(new_TUPLELIST_CR("DSCC265","Wegmans 1400"),htcr);
    insert_CR(new_TUPLELIST_CR("MATH150","Harkness 115"),htcr);

    insert_CP(new_TUPLELIST_CP("CSC172","CSC171"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC172","CSC150"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC173","CSC172"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC252","CSC172"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC254","CSC252"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC201","CSC171"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC202","DSCC201"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC265","DSCC262"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC265","CSC171"),htcp);

    insert_SNAP(new_TUPLELIST_SNAP("11111","M. Subban","1 Exchange Blvd","555-1212"), htsnap);
    insert_SNAP(new_TUPLELIST_SNAP("12345","R. Zmolek","2700 B-H Townline Rd","555-1111"), htsnap);
    insert_SNAP(new_TUPLELIST_SNAP("67890","P. Tischke","1 Exchange Blvd","555-1234"), htsnap);
    insert_SNAP(new_TUPLELIST_SNAP("12321","F. Cedarqvist","80 Lyndon Rd","555-2222"), htsnap);
    insert_SNAP(new_TUPLELIST_SNAP("98789","M. Subban","123 ling Rd","555-3333"), htsnap);

    insert_CDH(new_TUPLELIST_CDH("CSC171","T","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC171","R","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC172","T","1525"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC172","R","1640"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC173","T","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC173","R","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC252","T","1230"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC252","R","1230"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC201","M","900"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC201","W","900"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC202","M","1650"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC202","W","1650"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC265","M","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC265","W","1400"),htcdh);

    printf("Part 1, data of the datatables:\n");
    print_CSG_DATABASE(htcsg);
    printf("----------------\n");
    print_CR_DATABASE(htcr);
    printf("----------------\n");
    print_CP_DATABASE(htcp);
    printf("----------------\n");
    print_SNAP_DATABASE(htsnap);
    printf("----------------\n");
    print_CDH_DATABASE(htcdh);
    printf("----------------\n");

    printf("Last of part 1, deletion and lookups:\n");
    printf("(a) lookup('CSC172', '98789', '/*', Course-StudentId-Grade)\n");
    print_CSG(lookup_CSG("CSC172","98789","*",htcsg));
    printf("(b) lookup('CSC173', 'CSC172', Course-Prerequisite)\n");
    print_CP(lookup_CP("CSC173","CSC172",htcp));
    printf("(c) delete('DSCC201','/*', '/*', Course-Day-Hour)\n");
    delete_CDH("DSCC201","*","*",htcdh);
    printf("Table after deletion: \n");
    print_CDH_DATABASE(htcdh);
    printf("(d) insert('CSC280', 'CSC173', Course-Prerequisite)\n");
    printf("(e) insert('DSCC202', 'DSCC201', Course-Prerequisite)\n");
    insert_CP(new_TUPLELIST_CP("CSC280","CSC173"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC202","DSCC201"),htcp);
    printf("Table after insertion: \n");
    print_CP_DATABASE(htcp);

    printf("\n");

    //set ups for part 3:
    init_HASHTABLE_CP(htcp);
    init_HASHTABLE_CDH(htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC171","T","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC171","R","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC172","T","1525"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC172","R","1640"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC173","T","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC173","R","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC252","T","1230"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("CSC252","R","1230"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC201","M","900"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC201","W","900"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC202","M","1650"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC202","W","1650"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC265","M","1400"),htcdh);
    insert_CDH(new_TUPLELIST_CDH("DSCC265","W","1400"),htcdh);
    insert_CP(new_TUPLELIST_CP("CSC172","CSC171"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC172","CSC150"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC173","CSC172"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC252","CSC172"),htcp);
    insert_CP(new_TUPLELIST_CP("CSC254","CSC252"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC201","CSC171"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC202","DSCC201"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC265","DSCC262"),htcp);
    insert_CP(new_TUPLELIST_CP("DSCC265","CSC171"),htcp);

    Part2_1_REPL();
    Part2_2_REPL();

    //part3
    printf("------- Part 3 -------\n");
    printf("Printing result of selection of StudentID = '67890': as in the pdf\n");
    HASHTABLE_CSG resultContainerStudentId;
    init_HASHTABLE_CSG(resultContainerStudentId);
    selection_StudentID_CSG(htcsg,"67890",resultContainerStudentId);
    print_CSG_DATABASE(resultContainerStudentId);


    printf("--------------\n");
    printf("Printing result of projection (8.13) of Course of selection of studentId = '67890' as described in the pdf:\n");
    HASHTABLE_PRO projectionResultContainerCourse;
    init_HASHTABLE_PRO(projectionResultContainerCourse);
    projection_Course_CSG(resultContainerStudentId,projectionResultContainerCourse);
    print_PRO_DATABASE(projectionResultContainerCourse);

    printf("--------------\n");
    printf("Printing result of join (8.14) of CDH and CR as described in the book and in the pdf:\n");
    HASHTABLE_CRDH join;
    init_HASHTABLE_CRDH(join);
    join_CR_CDH_Course(htcr,htcdh,join);
    print_CRDH_DATABASE(join);

    printf("--------------\n");
    printf("Printing result of projection of last of part 3:\n");
    HASHTABLE_PRO_DAY_HOUR pdh2;
    HASHTABLE_CRDH new_Join2;
    init_HASHTABLE_CRDH(new_Join2);
    init_HASHTABLE_PRO_DAY_HOUR(pdh2);
    selection_Room_JOIN(join,"Wegmans 1400",new_Join2);
    projection_Day_Hour_Join(new_Join2,pdh2);
    print_PRO_DAY_HOUR_DATABASE(pdh2);

    return 0;
}

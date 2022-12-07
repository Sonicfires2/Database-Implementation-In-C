#include "part1.h"

void selection_StudentID_CSG(HASHTABLE_CSG ht, char* id, HASHTABLE_CSG resultContainer) {
    TUPLELIST_CSG pointer= NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if (strcmp(id,pointer->StudentId) == 0) {
                insert_CSG(new_TUPLELIST_CSG(pointer->Course,pointer->StudentId,pointer->Grade),resultContainer);
            }
            pointer = pointer->next;
        }
    }
}

void selection_Course_CSG(HASHTABLE_CSG ht, char* c, HASHTABLE_CSG resultContainer) {
    TUPLELIST_CSG pointer= NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if (strcmp(c,pointer->Course) == 0) {
                insert_CSG(new_TUPLELIST_CSG(pointer->Course,pointer->StudentId,pointer->Grade),resultContainer);
            }
            pointer = pointer->next;
        }
    }
}


void projection_StudentId_CSG(HASHTABLE_CSG ht, HASHTABLE_PRO target) {
    int count = 0;
    char* AlreadyIn[10];
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CSG pointer = ht[i];
        if(pointer!=NULL) {
            while (pointer!=NULL) {
                if (count == 0) {
                    insert_PRO(new_TUPLELIST_PRO(ht[i]->StudentId),target);
                    AlreadyIn[count] = ht[i]->StudentId;
                    pointer = pointer->next;
                    count++;
                } else {
                    bool canBeInserted = true;
                    for (int u = 0; u < 9; u++) {
                        if (strcmp(ht[i]->StudentId,AlreadyIn[u]) == 0) {
                            canBeInserted = false;
                        }
                    }
                    if (canBeInserted) {
                        insert_PRO(new_TUPLELIST_PRO(ht[i]->StudentId),target);
                        pointer = pointer->next;
                        count++;
                    } else {
                        pointer = pointer->next;
                    }
                }
            }
        }
    }
}

void projection_Course_CSG(HASHTABLE_CSG ht, HASHTABLE_PRO target) {
    int count = 0;
//    char* AlreadyIn[10];
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CSG pointer = ht[i];
        if(pointer!=NULL) {
//            printf("Currently at i = %d and value of %s\n",i,pointer->Course);
            while (pointer!=NULL) {
                if (count == 0) {
//                    printf("Inserting %s\n",pointer->Course);
                    insert_PRO(new_TUPLELIST_PRO(pointer->Course),target);
//                    AlreadyIn[count] = ht[i]->Course;
                    pointer = pointer->next;
                    count++;
                } else {
                    bool canBeInserted = true;
//                    for (int u = 0; u < 9; u++) {
//                        printf("testing %s and %s\n",pointer->Course, AlreadyIn[u]);
//                        if (strcmp(ht[i]->Course,AlreadyIn[u]) == 0) {
//                            canBeInserted = false;
//                        }
//                    }
                    if (canBeInserted) {
//                        printf("Inserting %s after first\n",pointer->Course);
                        insert_PRO(new_TUPLELIST_PRO(pointer->Course),target);
                        pointer = pointer->next;
//                        AlreadyIn[count] = ht[i]->Course;
                        count++;
                    } else {
                        pointer = pointer->next;
                    }
                }
            }
        }
    }
}

void join_CR_CDH_Course(HASHTABLE_CR cr, HASHTABLE_CDH cdh, HASHTABLE_CRDH crdh) {
    for (int i = 0; i<DATABASE_SIZE;i++) {
        TUPLELIST_CDH tempCDH = cdh[i];
        while(tempCDH!=NULL) {
            TUPLELIST_CR tempCR = cr[hash(tempCDH->Course)];
            while(tempCR != NULL) {
//                printf("Courses to compare'%s' and '%s'\n",tempCDH->Course,tempCDH->Course);
                if(strcmp(tempCDH->Course,tempCR->Course) == 0) {
//                    printf("Inserting %s %s %s %s at i = %d and at hash = %d\n",tempCDH->Course,tempCR->Room,tempCDH->Day,tempCDH->Hour,i,hash(tempCDH->Course));
                    insert_CRDH(new_TUPLELIST_CRDH(tempCDH->Course,tempCR->Room,tempCDH->Day,tempCDH->Hour),crdh);
                }
                tempCR = tempCR->next;
            }
            tempCDH = tempCDH->next;
        }
    }
}

void selection_Room_JOIN(HASHTABLE_CRDH ht, char* r, HASHTABLE_CRDH resultContainer) {
    TUPLELIST_CRDH pointer= NULL;
    for(int i=0; i<DATABASE_SIZE; i++){
        pointer = ht[i];
        while (pointer != NULL) {
            if (strcmp(r,pointer->Room) == 0) {
                insert_CRDH(new_TUPLELIST_CRDH(pointer->Course,pointer->Room,pointer->Day, pointer->Hour),resultContainer);
            }
            pointer = pointer->next;
        }
    }
}


void projection_Day_Hour_Join(HASHTABLE_CRDH ht, HASHTABLE_PRO_DAY_HOUR target) {
    int count = 0;
    for (int i = 0; i < DATABASE_SIZE; i++) {
        TUPLELIST_CRDH pointer = ht[i];
        if(pointer!=NULL) {
            while (pointer!=NULL) {
                if (count == 0) {
                    insert_PRO_DAY_HOUR(new_TUPLELIST_PRO_DAY_HOUR(ht[i]->Day, ht[i]->Hour),target);
                    pointer = pointer->next;
                    count++;
                } else {
                    bool canBeInserted = true;
                    if (canBeInserted) {
                        insert_PRO_DAY_HOUR(new_TUPLELIST_PRO_DAY_HOUR(pointer->Day,pointer->Hour),target);
                        pointer = pointer->next;
                    } else {
                        pointer = pointer->next;
                    }
                }
            }
        }
    }
}

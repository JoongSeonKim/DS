//
//  SimpleHashMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "Person.h"
#include "Table2.h"
//#include "Table1.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main(void)
{
    Table myTbl;
    Person *np;
    Person *sp;
    Person *rp;
    
    TBLInit(&myTbl, MyHashFunc);
    
    np = MakePersonData(20120003, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20130012, "Kim", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(20170049, "Han", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL) ShowPerInfo(sp);
    printf(" \n");

    sp = TBLSearch(&myTbl, 20130012);
    if(sp != NULL) ShowPerInfo(sp);
    printf(" \n");

    sp = TBLSearch(&myTbl, 20170049);
    if(sp != NULL) ShowPerInfo(sp);
    printf(" \n");

    
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != NULL) free(rp);
    
    rp = TBLDelete(&myTbl, 20130012);
    if(rp != NULL) free(rp); 
    
    rp = TBLDelete(&myTbl, 20170049);
    if(rp != NULL) free(rp);
    
    
    return 0;
}

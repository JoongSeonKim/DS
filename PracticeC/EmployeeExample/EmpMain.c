//
//  EmpMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Emp * NightDuty(List *plist, char *name, int day);

int main(void)
{
    Emp *data;
    
    List list;
    ListInit(&list);
    
    data = (Emp*)malloc(sizeof(Emp));
    SetEmpInfo(data, 1111, "adam smith");
    LInsert(&list, data);

    data = (Emp*)malloc(sizeof(Emp));
    SetEmpInfo(data, 2222, "bincent ban goch");
    LInsert(&list, data);
    
    data = (Emp*)malloc(sizeof(Emp));
    SetEmpInfo(data, 3333, "christina aguilera");
    LInsert(&list, data);
    
    data = (Emp*)malloc(sizeof(Emp));
    SetEmpInfo(data, 4444, "draconian");
    LInsert(&list, data);
    
    data = NightDuty(&list, "adam smith", 2);
    ShowEmpInfo(data);
    
    data = NightDuty(&list, "draconian", 2584726);
    ShowEmpInfo(data);
    
    return 0;
}


Emp * NightDuty(List *plist, char *name, int day)
{
    int i, num;
    Emp *ret;
    
    num = LCount(plist);
    
    LFirst(plist, &ret);
    
    if(strcmp(ret->EmpName, name))
    {
        for(i=0; i<num-1; i++)
        {
            LNext(plist, &ret);
            
            if(!strcmp(ret->EmpName, name)) break;
        }
        if(i>=num-1) return NULL;
    }
    
    for(i=0; i<(day%plist->numofData); i++)
    {
        LNext(plist, &ret);
    }
    
    return ret;
}




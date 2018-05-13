//
//  Person.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Person.h"

int GetSSN(Person *p)
{
    return p->ssn;
}

void ShowPerInfo(Person *p)
{
    printf("SSN : %d \n", p->ssn);
    printf("Name : %s \n", p->name);
    printf("Addr : %s \n", p->addr);
}

Person * MakePersonData(int ssn, char *name, char* addr)
{
    Person *newP = (Person*)malloc(sizeof(Person));
    
    newP->ssn = ssn;
    strcpy(newP->name, name);
    strcpy(newP->addr, addr);
    
    return newP;
}


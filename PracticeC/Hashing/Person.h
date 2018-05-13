//
//  Person.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 13..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Person_h
#define Person_h

#define STR_LEN 50

typedef struct _person
{
    int ssn;
    char name[STR_LEN];
    char addr[STR_LEN];
} Person;

int GetSSN(Person *p);
void ShowPerInfo(Person *p);
Person * MakePersonData(int ssn, char *name, char* addr);

#endif /* Person_h */

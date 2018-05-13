//
//  Employee.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

typedef struct _Employee
{
    int EmpNum;
    char EmpName[20];
} Emp;

void SetEmpInfo(Emp *person, int num, char name[]);

void ShowEmpInfo(Emp *person);

#endif /* Employee_h */

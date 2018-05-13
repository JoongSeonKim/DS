//
//  Employee.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Employee.h"

void SetEmpInfo(Emp *emp, int num, char name[])
{
    emp->EmpNum = num;
    strcpy(emp->EmpName, name);
}

void ShowEmpInfo(Emp *emp)
{
    printf("Employee Name : %s \n", emp->EmpName);
    printf("Employee Number : %d \n", emp->EmpNum);
}


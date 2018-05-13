//
//  UnderstandingTable.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 12..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

typedef struct _empInfo
{
    int empNum;
    int age;
} EmpInfo;

int main(void)
{
    EmpInfo empInfoArr[1000];
    EmpInfo ei;
    int eNum;
    
    printf("Input Emp Number and Age: ");
    scanf("%d %d", &ei.empNum, &ei.age);
    empInfoArr[ei.empNum] = ei;
    
    printf("Input Emp number for check: ");
    scanf("%d", &eNum);
    
    ei = empInfoArr[eNum];
    printf("empNum : %d, age : %d \n", ei.empNum, ei.age);
    
    return 0;
}

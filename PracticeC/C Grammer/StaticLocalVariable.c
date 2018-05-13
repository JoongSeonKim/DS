//
//  StaticLocalVariable.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 5..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void SimpleFunc(void)
{
    static int num1=0; // limited in SimpleFunc()
    int num2=0;
    num1++, num2++;
    
    printf("static: %d, local: %d \n", num1, num2);
}

int main(void)
{
    int i;
    for(i=0; i<3; i++)
    {
        SimpleFunc();
    }
    return 0;
}

//
//  320 p2 swap3.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void swap3(int *a, int *b, int *c)
{
    int tmp;
    
    tmp=*c;
    *c=*b;
    *b=*a;
    *a=tmp;
}

int main(void)
{
    int a=97;
    int b=98;
    int c=99;
    
    swap3(&a, &b, &c);
    
    printf("%d %d %d \n", a, b, c);
    return 0;
}

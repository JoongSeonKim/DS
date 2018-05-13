//
//  TwoWhile.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 6..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i=0, j;
    while(i<5)
    {
        j=0;
        while(j<i) {
            printf("o");
            j++;
        }
        printf("*\n");
        i++;
    }
    return 0;
}

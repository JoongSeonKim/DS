//
//  268problem1.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int idx=0;
    char str[50];
    scanf("%s", str);
    
    while(str[idx]!='\0')
    {
        idx++;
    }
    printf("%d \n", idx);
    
    return 0;
}

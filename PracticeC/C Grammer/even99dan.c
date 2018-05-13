//
//  even99dan.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i=2, j;
    
    while(i<9)
    {
        j=1;
        if( (i%2) != 0)
        {
            i++;
            continue;
        }
    
        while(j<9)
        {
            if(j>i) break;
            printf("%d X %d = %d\n", i, j, i*j);
            j++;
        }
        i++;
    }
}

//
//  300 problem4.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int i;
    int tmp;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    
    for(i=0; i<3; i++)
    {
        tmp=arr[i];
        arr[i]=arr[5-i];
        arr[5-i]=tmp;
    }
    
    printf("%d %d %d %d %d %d \n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    return 0;
}

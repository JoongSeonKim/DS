//
//  ArrayRead.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 4. 30..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int arr[10];
    int readCount = 0;
    int readData;
    int i;
    
    while(1)
    {
        printf("Input Neutral Number: ");
        scanf("%d", &readData);
        
        if(readData < 1) break;
        
        arr[readCount++] = readData;
    }
    
    for(i=0; i<readCount; i++) printf("%d ", arr[i]);
    
    return 0;
}

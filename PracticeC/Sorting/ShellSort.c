//
//  ShellSort.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 10..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void SelSort(int arr[], int n)
{
    int i, j;
    int temp;
    int idx;
    
    for(i=0; i<n-1; i++)
    {
        idx = i;
        
        for(j=i+1; j<n; j++)
        {
            if( arr[j] < arr[idx] ) idx=j;
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

int main(void)
{
    int arr[5] = { 1, 3, 5, 4, 2 };
    int idx;
    
    SelSort( arr, sizeof(arr)/sizeof(int) );
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
        
    return 0;
}

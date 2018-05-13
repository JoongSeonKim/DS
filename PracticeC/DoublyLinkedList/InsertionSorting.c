//
//  InsertionSorting.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 10..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void InsSort(int arr[], int n)
{
    int i, j;
    int ins;
    
    
    for(i=1; i<n; i++)
    {
        ins = arr[i];

        for(j=i-1; j>=0; j--)
        {
            if ( arr[j] > ins ) arr[j+1] = arr[j];
            
            else break;
        }
        
        arr[j+1] = ins;
    }
}


int main(void)
{
    int arr[5] = { 4, 1, 2, 5, 3 };
    int idx;
    
    InsSort(arr, sizeof(arr) / sizeof(int));
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}


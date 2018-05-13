//
//  InsertionSort.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 9..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void InserSort(int arr[], int n)
{
    int i, j;
    int insData;
    
    for(i=1; i<n; i++)
    {
        insData = arr[i];
        
        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > insData) arr[j+1] = arr[j];
            
            else break;
        }
        
        arr[j+1] = insData;
    }
}

int main(void)
{
    int arr[5] = { 4, 5, 3, 1, 2 };
    int idx;
    
    InserSort(arr, sizeof(arr)/sizeof(int));
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}

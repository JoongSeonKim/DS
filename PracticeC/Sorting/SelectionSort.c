//
//  SelectionSort.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 9..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void SelSort(int arr[], int n);

int main(void)
{
    int arr[5] = { 2, 3, 1, 4, 5 };
    int idx;
    
    SelSort(arr, sizeof(arr)/sizeof(int));
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}

void SelSort(int arr[], int n)
{
    int i, j;
    int temp;
    int minIdx;
    
    for(i=0; i<n-1; i++)
    {
        minIdx = i;
        
        for(j=i+1; j<n; j++) // O(n^2) for comparison
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        
        temp = arr[i]; // O(n) for data movement
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

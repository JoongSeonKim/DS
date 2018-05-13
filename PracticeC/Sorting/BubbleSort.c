//
//  BubbleSort.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 9..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

void BubbleSort(int arr[], int n);  // O(n^2)

int main(void)
{
    int idx;
    int arr[10] = { 4, 7, 10, 1, 5, 9, 2, 6, 8, 3 };
    
    BubbleSort(arr, sizeof(arr)/sizeof(int));
    
    for(idx=0; idx<10; idx++)
    {
        printf("arr[idx] = %d \n", arr[idx]);
    }
    
    return 0;
}

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;
    
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++) // no doubt, comparison operate for 1+2+ ... + (n-1) times for worst/best case
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j]; // but in best case, there is no data movement! minimum to 0 move!
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

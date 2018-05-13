//
//  MergeSort.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 10..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid+1; // important point
    int i;
    
    int *sortArr = (int*)malloc(sizeof(int) * (right+1));
    
    int sIdx = left;
    
    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx] < arr[rIdx]) sortArr[sIdx] = arr[fIdx++];
        
        else sortArr[sIdx] = arr[rIdx++];
        
        sIdx++;
    }
    
    if(fIdx > mid)
    {
        for(i=rIdx; i<=right; i++, sIdx++)
        {
            sortArr[sIdx] = arr[i];
        }
    }
    
    else
    {
        for(i=fIdx; i<=mid; i++, sIdx++)
        {
            sortArr[sIdx] = arr[i];
        }
    }
    
    for(i=left; i<=right; i++) arr[i] = sortArr[i];
    
    free(sortArr);
    
}


void MergeSort(int arr[], int left, int right)
{
    int mid;
    printf("call right:%d left:%d \n", left, right);
    
    if(left < right)
    {
        mid = (left+right) / 2;
        
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        
        MergeTwoArea(arr, left, mid, right);
    }
}


int main(void)
{
    int arr[12] = { 5, 11, 7, 3, 1, 9, 2, 12, 6, 4, 8 };
    int idx;
    
    MergeSort(arr, 0, (sizeof(arr)/sizeof(int)) - 1 );
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}

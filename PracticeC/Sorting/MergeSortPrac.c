//
//  MergeSortPrac.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int first, int mid, int last)
{
    int fIdx = first;
    int lIdx = mid+1; //
    int i;
    
    int *sortArr = (int*)malloc(sizeof(int)*(last+1));
    int sIdx = first;
    
    while(fIdx<=mid && lIdx<=last) // have to reach end of area. so "=" is important
    {
        if(arr[fIdx] < arr[lIdx]) sortArr[sIdx] = arr[fIdx++]; // can have same int value. so "=" have to be in one side
        
        else sortArr[sIdx] = arr[lIdx++]; // but just use "else" can do same.

        sIdx++;
    }
    
    if(fIdx>mid)
    {
        for(i=lIdx; i<=last; i++, sIdx++) // must reach lIdx to last!
        {
            sortArr[sIdx] = arr[i];
        }
    }
    
    else // (lIdx>last)
    {
        for(i=fIdx; i<=mid; i++, sIdx++) // must reach fIdx to mid
        {
            sortArr[sIdx] = arr[i];
        }
    }
    
    for(i=first; i<=last; i++)
    {
        arr[i] = sortArr[i];
    }
    
    free(sortArr);
}

void MergeSort(int arr[], int first, int last)
{
    int mid;
    
    if(first < last)
    {
        mid = (first+last)/2;
        
        MergeSort(arr, first, mid);
        MergeSort(arr, mid+1, last);
        
        MergeTwoArea(arr, first, mid, last);
    }
    
}

int main(void)
{
    int arr[12] = { 7, 9, 12, 11, 5, 4, 3, 8, 6, 10, 1, 1 };
    int idx;
    
    MergeSort(arr, 0, sizeof(arr)/sizeof(int) -1 );
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}

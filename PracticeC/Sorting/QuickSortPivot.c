//
//  QuickSortPivot.c
//  fork version of QuickSortme.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp;
    
    temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int median(int arr[], int left, int right)
{
    int arrof3[3] = { left, (left+right)/2, right };
    
    if(arr[arrof3[0]]>arr[arrof3[1]]) Swap(arrof3, 0, 1);
    
    if(arr[arrof3[1]]>arr[arrof3[2]]) Swap(arrof3, 1, 2);
    
    if(arr[arrof3[0]]>arr[arrof3[1]]) Swap(arrof3, 0, 1);
    
    return arrof3[1];
}

int Partition(int arr[], int left, int right)
{
    int pIdx = median(arr, left, right);
    int pivot = arr[pIdx];
    
    //int pivot = arr[left]; // leftest pivot.
    int low = left+1;
    int high = right;
    
    Swap(arr, left, pIdx);
    
    printf("pivot = %d \n", pivot);
    
    while(low <= high)
    {
        while(pivot >= arr[low] && low <= right) low++;
        
        while(pivot <= arr[high] && high >= (left+1)) high--;
        
        if(low <= high) Swap(arr, low, high);
    }
    
    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main(void)
{
    srand(time(NULL));
    
    int arr[21] = {11, 6, 3, 21, 13, 19, 20, 7, 2, 10, 17, 18, 8, 14, 5, 9, 1, 4, 12, 15, 11 }; // if same element exist, ....
    int arr1[14] = {3, 2, 1, 11, 13, 14, 12, 6, 7, 4, 5, 8, 9, 10};
    int idx;
    
    QuickSort(arr, 0, (sizeof(arr)/sizeof(int))-1);
    
    printf("------------------ End of Pivot Print Session. ----------------------- \n");
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}



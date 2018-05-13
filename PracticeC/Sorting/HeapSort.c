//
//  HeapSort.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 10..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
    return n2-n1; // small thing comes first
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;
    
    HeapInit(&heap, pc);
    
    for(i=0; i<n; i++) HInsert(&heap, arr[i]); // O(n) = log(n) * n
    
    for(i=0; i<n; i++) arr[i] = HDelete(&heap); // O(n) = log(n) * n
    
}

int main(void)
{
    int arr[10] = { 7, 5, 1, 4, 10, 9, 2, 3, 6, 8 };
    int idx;
    
    HeapSort(arr, sizeof(arr)/sizeof(int), PriComp); // O(n) = nlog(n)
    
    for(idx=0; idx<sizeof(arr)/sizeof(int); idx++) printf("arr[%d] = %d \n", idx, arr[idx]);
    
    return 0;
}

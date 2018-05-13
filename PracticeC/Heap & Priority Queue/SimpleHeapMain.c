//
//  SimpleHeapMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 8..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
//#include "SimpleHeap.h"
#include "UsefulHeap.h"

/*
int main(void)
{
    Heap heap;
    HeapInit(&heap);
    
    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("1st deletion : %c \n", HDelete(&heap));
    
    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("2nd deletion : %c \n", HDelete(&heap));
    
    while(!HIsEmpty(&heap)) printf("%c \n", HDelete(&heap));
    
    return 0;
} */
int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);
    
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("1st deletion : %c \n", HDelete(&heap));
    
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("2nd deletion : %c \n", HDelete(&heap));
    
    while(!HIsEmpty(&heap)) printf("%c \n", HDelete(&heap));
    
    return 0;
}

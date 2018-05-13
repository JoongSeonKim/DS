//
//  CLLStackMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 4..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "CLLStack.h"

int main(void)
{
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 1); SPush(&stack, 2);
    SPush(&stack, 3); SPush(&stack, 4);
    SPush(&stack, 5);
    
    while(!SIsEmpty(&stack))
    {
        printf("%d ", SPop(&stack));
    }
    
    return 0;
}

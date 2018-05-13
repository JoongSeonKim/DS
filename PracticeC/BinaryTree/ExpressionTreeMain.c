//
//  ExpressionTreeMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
    char exp[] = "12+7*";
    BTreeNode *eTree = MakeExpTree(exp);
    
    printf("Prefix expression : ");
    ShowPrefixTypeExp(eTree); printf("\n");
    
    printf("Infix expression : ");
    ShowInfixTypeExp(eTree); printf("\n");
    
    printf("Postfix expression : ");
    ShowPostfixTypeExp(eTree); printf("\n");
    
    printf("Result of the expression : %d ", EvaluateExpTree(eTree));
    
    return 0;
}

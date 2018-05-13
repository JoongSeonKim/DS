//
//  ExpressionTree.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BinaryTree2.h"
#include "ListBaseStack.h"
#include "ExpressionTree.h"

BTreeNode *MakeExpTree(char exp[]) // make Exp Tree
{
    Stack stack;
    BTreeNode *pnode;
    
    int expLen = strlen(exp);
    int i;
    
    StackInit(&stack);
    
    for(i=0; i<expLen; i++)
    {
        pnode = MakeBTreeNode();
        
        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i] - '0');
        }
        
        else
        {
            MakeRightSubTree(pnode, SPop(&stack)); // make right subtree first
            MakeLeftSubTree(pnode, SPop(&stack)); // then left
            SetData(pnode, exp[i]);
        }
        
        SPush(&stack, pnode);
    }
    
    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode *bt) // calculate Exp Tree
{
    int op1, op2;
    
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) return GetData(bt);
    
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    
    switch (GetData(bt))
    {
        case '+':
            return op1+op2;
            break;
            
        case '-':
            return op1-op2;
            break;
            
        case '*':
            return op1*op2;
            break;
            
        case '/':
            return op1/op2;
            break;
    }
    return 0;
}

void ShowNodeData(int data)
{
    if(0<=data && data<=9) printf("%d ", data);
    
    else printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt)
{
    if(bt == NULL) return;
    
    if(bt->left != NULL || bt->right != NULL) printf("( ");
    
    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);

    if(bt->right != NULL || bt->left != NULL) printf(") ");
}

void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowNodeData);
}



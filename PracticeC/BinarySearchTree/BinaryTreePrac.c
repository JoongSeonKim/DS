//
//  BinaryTreePrac.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "BinaryTreePrac.h"

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *bt = (BTreeNode*)malloc(sizeof(BTreeNode));
    bt->left = NULL;
    bt->right = NULL;
    
    return bt;
}

Data GetData(BTreeNode *bt)
{
    if(bt == NULL)
    {
        printf("Memory Error!");
        exit(-1);
    }

    return bt->data;
}

void SetData(BTreeNode *bt, Data data)
{
    if(bt == NULL)
    {
        printf("Memory Error!");
        exit(-1);
    }
    
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *bt, BTreeNode *sb)
{
    if(bt->left != NULL) free(bt->left);
    
    bt->left = sb;
}
void MakeRightSubTree(BTreeNode *bt, BTreeNode *sb)
{
    if(bt->right != NULL) free(bt->right);
    
    bt->right = sb;
}

void DeleteTree(BTreeNode *bt)
{
    if(bt == NULL) return;
    
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    
    free(bt);
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if(bt == NULL) return;
    
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if(bt == NULL) return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if(bt == NULL) return;
    
    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

BTreeNode *RemoveLeftSubTree(BTreeNode *bt)
{
    BTreeNode *delNode;
    
    if(bt != NULL)
    {
        delNode = bt->left;
        bt->left = NULL;
    }
    return delNode;
}

BTreeNode *RemoveRightSubTree(BTreeNode *bt)
{
    BTreeNode *delNode;
    
    if(bt != NULL)
    {
        delNode = bt->right;
        bt->right = NULL;
    }
    return delNode;
}

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->right = sub;
}


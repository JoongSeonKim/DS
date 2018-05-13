//
//  BinaryTreePrac.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef BinaryTreePrac_h
#define BinaryTreePrac_h

typedef int Data;

typedef struct _treenode
{
    Data data;
    struct _treenode *left;
    struct _treenode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void);

Data GetData(BTreeNode *bt);

void SetData(BTreeNode *bt, Data data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);

BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *bt, BTreeNode *sb);

void MakeRightSubTree(BTreeNode *bt, BTreeNode *sb);

void DeleteTree(BTreeNode *bt);

typedef void VisitFuncPtr(Data data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

BTreeNode *RemoveLeftSubTree(BTreeNode *bst);
BTreeNode *RemoveRightSubTree(BTreeNode *bst);

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);


#endif /* BinaryTreePrac_h */

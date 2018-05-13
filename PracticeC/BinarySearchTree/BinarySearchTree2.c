//
//  BinarySearchTree2.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 12..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst)
{
    if(bst == NULL)
    {
        printf("Memory Error!");
        exit(-1);
    }
    
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BTreeNode *pNode = NULL; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *nNode = NULL; // new node
    
    while(cNode != NULL)
    {
        if(data == GetData(cNode)) return;
        
        pNode = cNode;
        
        if(GetData(cNode) > data)
        {
            cNode = GetLeftSubTree(cNode);
        }
        
        else cNode = GetRightSubTree(cNode);
    }
    
    nNode = MakeBTreeNode();
    SetData(nNode, data);
    
    if(pNode != NULL)
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        
        else MakeRightSubTree(pNode, nNode);
    }
    
    else
    {
        *pRoot = nNode;
    }
}

BTreeNode * BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = bst;
    BSTData cd;
    
    while(cNode != NULL)
    {
        cd = GetData(cNode);
        
        if(target == cd) return cNode; // if find target -> return current cNode
        
        else if(target < cd) cNode = GetLeftSubTree(cNode); // else if target is smaller than cd, cNode -> left child of cNode
        
        else cNode = GetRightSubTree(cNode); // else (target is bigger than cd) than cNode -> right child of cNode
    }
    
    return NULL;
}

BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target)
{
    BTreeNode *pVRoot = MakeBTreeNode();    // Virtal Root node
    BTreeNode *pNode = pVRoot;  // parent node
    BTreeNode *cNode = *pRoot;  // current node
    BTreeNode *dNode;   // delete node
    
    ChangeRightSubTree(pVRoot, *pRoot);
    
    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;
        
        if(target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
        
        else cNode = GetRightSubTree(cNode);
    }
    
    if(cNode == NULL) return NULL;
    
    dNode = cNode;
    
    ////////// end of find target part //////////
    
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
        
        else RemoveRightSubTree(pNode);
    }
    
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode *dcNode;
        
        // find only child of right or left
        
        if(GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
        
        else dcNode = GetRightSubTree(dNode);
        
        // and make parent -> dc, if parent->d right, dc also right / parent->d left, dc also left.
        
        if(GetLeftSubTree(pNode) == dNode) ChangeLeftSubTree(pNode, dcNode);
        
        else ChangeRightSubTree(pNode, dcNode);
    }
    
    else // two child exist!
    {
        BTreeNode *mNode = GetRightSubTree(dNode);
        
        BTreeNode *mpNode = dNode;
        
        int delData;
        
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        
        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));
        
        if(GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        
        else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        
        dNode = mNode;
        SetData(dNode, delData);
    }
    
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);
    
    free(pVRoot);
    return dNode;
    
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

void BSTShowAll(BTreeNode *bst)
{
    InorderTraverse(bst, ShowIntData);
}



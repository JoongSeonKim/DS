//
//  BinarySearchTree.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

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


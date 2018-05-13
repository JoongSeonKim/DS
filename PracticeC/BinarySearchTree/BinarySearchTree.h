//
//  BinarySearchTree.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "BinaryTreePrac.h"

typedef Data BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

BSTData BSTGetNodeData(BTreeNode *bst);

void BSTInsert(BTreeNode **pRoot, BSTData data);

BTreeNode * BSTSearch(BTreeNode *bst, BSTData target);

#endif /* BinarySearchTree_h */

//
//  BinarySearchTree2.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 12..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef BinarySearchTree2_h
#define BinarySearchTree2_h

#include "BinaryTreePrac.h"

typedef Data BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

BSTData BSTGetNodeData(BTreeNode *bst);

void BSTInsert(BTreeNode **pRoot, BSTData data);

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target);

void BSTShowAll(BTreeNode *bst);

#endif /* BinarySearchTree2_h */

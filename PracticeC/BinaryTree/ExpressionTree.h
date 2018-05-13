//
//  ExpressionTree.h
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#ifndef ExpressionTree_h
#define ExpressionTree_h

#include "BinaryTree2.h"

BTreeNode *MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode *bt);

void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);

#endif /* ExpressionTree_h */

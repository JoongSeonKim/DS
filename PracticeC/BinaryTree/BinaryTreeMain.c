//
//  BinaryTreeMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    
    printf("%d \n", GetData(GetRightSubTree(bt1)));
    
    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
 
    return 0;
}

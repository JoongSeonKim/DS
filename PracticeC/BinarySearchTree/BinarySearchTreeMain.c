//
//  BinarySearchTreeMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

int main(void)
{
    BTreeNode *bstRoot;
    BTreeNode *sNode;
    
    BSTMakeAndInit(&bstRoot);
    
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 3);
    
    sNode = BSTSearch(bstRoot, 1);
    
    if(sNode == NULL) printf("Failed to Search \n");
    
    else printf("Search Result : %d \n", BSTGetNodeData(sNode));
    
    return 0;
}

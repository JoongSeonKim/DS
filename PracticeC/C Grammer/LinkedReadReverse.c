//
//  LinkedReadReverse.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 3..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(void)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    
    Node *newNode = NULL;
    int readData;
    
    while(1)
    {
        printf("input neutral number: ");
        scanf("%d", &readData);
        if(readData < 1) break;
        
        // add node"s"
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;
        
        // invert this part...
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        
        else
        {
            newNode->next = head;
            head = newNode;
        }
        
    }
    printf("\n");
    
    printf("Print all received input data: \n");
    
    if(head == NULL) printf("No number exists\n");
    
    else
    {
        cur = head;
        printf("%d ", cur->data);
        
        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");
    
    // free memory
    
    if(head == NULL)
    {
        return 0;
    }
    
    else
    {
        Node *delNode = head;
        Node *delNextNode = head->next;
        
        printf("Delete %d. \n", head->data);
        free(delNode);
        
        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            
            printf("Delete %d. \n", delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}


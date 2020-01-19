#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 12568 - Reverse Linked List ver 2
 typedef struct _Node{
    int data;
    struct _Node* next;
} Node; 
// add a new node with data=x to the beginning
void Push(Node** ptr_head, int x)
{
    Node *temp;
    temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = *ptr_head;
    *ptr_head = temp;
}

// delete the head node
 void Pop(Node** ptr_head)
{
    Node *temp;
    if(*ptr_head == NULL) return;
    temp = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(temp);
} 

void Reverse_List(Node** ptr_head)
{
    Node *temp,*scan;
    Node *new = NULL;
    while(*ptr_head != NULL){
        scan = *ptr_head;
        temp = (Node*) malloc(sizeof(Node));
        temp->data = scan->data;
        temp->next = new;
        new = temp;
        *ptr_head = scan->next;
        free(scan);
    }
    *ptr_head = new;
}
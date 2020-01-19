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
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new -> data = x;
    new -> next = *ptr_head;
    *ptr_head = new;
}

// delete the head node
 void Pop(Node** ptr_head)
{
    Node *temp;
    if(*ptr_head == NULL) 
        return;
    temp = *ptr_head;
    *ptr_head = (*ptr_head) -> next;
    free(temp);
} 

void Reverse_List(Node** ptr_head)
{
    Node *temp,*scan;
    Node *new = NULL;
    while(*ptr_head != NULL){
        scan = *ptr_head;
        // maintain
        temp = (Node *) malloc(sizeof(Node));
        temp -> data = scan -> data;
        temp -> next = new;
        new = temp;
        // clear old
        *ptr_head = scan -> next;
        free(scan);
    }
    *ptr_head = new;
    
}

int main(){
    char op[10];
    Node* head = NULL;
    while( ~scanf("%s", op) ){
        if( strcmp(op, "push") == 0 ){
            int x;
            scanf("%d", &x);
            Push(&head, x);
        }
        if( strcmp(op, "pop") == 0 ){
            Pop(&head);
        }
        if( strcmp(op, "reverse") == 0 ){
            Reverse_List(&head);
        }
        if( strcmp(op, "print") == 0 ){
            Print_List(head);
        }
    }

    Delete_List(head);
    head = NULL;

    return 0;
}
void Print_List(Node* head){
    if( head == NULL ){
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if( head->next != NULL ) printf(" -> ");
    Print_List(head->next);
}

void Delete_List(Node* head){
    if( head == NULL ) return;
    Delete_List(head->next);
    free(head);
}
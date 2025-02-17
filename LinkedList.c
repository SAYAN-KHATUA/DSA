#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}Node;


typedef struct LinkedList
{
    Node* head;
    Node* tail;
}list;

void initList(list*List){
    List -> head = NULL;
    List -> tail = NULL;
}

void insertNode(list*List,int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = val;
    node->next = NULL;

    if(List->head == NULL){
        List -> head = node;
        List -> tail = node;
    }
    else{
        (List -> tail) -> next = node;
        List -> tail = node;
    }
}

void dispList(list* List){
    Node* temp = List -> head;
    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL");
}

int main()
{
    list list;
    initList(&list);

    int arr[] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 7; i++)
    {
        insertNode(&list,arr[i]);
    }
    
    dispList(&list);

    return 0;
}
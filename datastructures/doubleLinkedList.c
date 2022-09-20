#include <stdio.h>
#include <stdlib.h>

//index from 0
typedef struct Node_S{
    int val;
    struct Node_S* next;
    struct Node_S* prev;
} node;

node* initList();
int getNodeValAtIndex(node* head, int index);
void addNodeAtHead(node** head, int val);
void addNodeAtTail(node** head, int val);
//@index between 1 and listLength-1
void addNodeAtIndex(node** head, int index, int val);
void deleteNodeAtIndex(node** head, int index);
void freeList(node* head);
void printList(node* head);
//@return Number of Elements in List counting from 1
int getLength(node *head);

int main(){
    node* head = initList();
    addNodeAtHead(&head, 1);
    addNodeAtHead(&head, 2);
    addNodeAtTail(&head, 3);
    addNodeAtTail(&head, 6);
    addNodeAtTail(&head, 4);
    addNodeAtIndex(&head, 3, 89);
    addNodeAtIndex(&head, 3 ,88);
    deleteNodeAtIndex(&head, 5);
    printList(head);
    freeList(head);
    return 0;
}

node* initList(){
    //initializes Empty list
    return NULL;
}

void addNodeAtHead(node** head, int val){
    node*tmp = *head;
    node* new = malloc(sizeof(node));
    new->val = val;
    //if list is empty new is head
    if(!tmp){
        *head = new;
        return;
    }
    new->next = tmp;
    new->prev = NULL;
    tmp->prev = new;
    *head = new;
}

void addNodeAtTail(node** head, int val){
    node* tmp = *head;
    node* new = malloc(sizeof(node));
    new->val = val;
    while(tmp->next){
        tmp = tmp->next;
    }
    new->prev = tmp;
    new->next = NULL;
    tmp->next = new;
}

void addNodeAtIndex(node** head, int index, int val){
    //index between 1 and n-1 starting from 0
    node* tmp = *head;
    node* new = malloc(sizeof(node));
    new->val = val;
    while(index > 0){
        tmp = tmp->next;
        --index;
    }
    new->next = tmp;
    new->prev = tmp->prev;
    tmp->prev->next = new;
    tmp->prev = new;
}

void deleteNodeAtIndex(node** head, int index){
    //index from 0
    node * tmp = *head;
    if(index == 0){
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
        return;
    }
    if(index == getLength(*head)-1){
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
        free(tmp);
        return;
    }
    while(index > 0){
        tmp = tmp->next;
        --index;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
}

int getLength(node* head){
    int l = 0;
    while(head){
        head = head->next;
        ++l;
    }
    return l;
}

void printList(node* head){
    node* tmp = head;
    printf(" %p ->", head->prev);
    while(tmp){
        printf(" %p|(%d) ->", tmp, tmp->val);
        tmp = tmp->next;
    }

    printf(" %p\n", tmp);
}

void freeList(node* head){
    node* tmp = NULL;
    while(head){
        tmp = head->next;
        head = tmp;
        free(head); 
    }
}

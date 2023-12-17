#include<stdio.h>
#include<stdlib.h>

struct sLinkedList {
    int data;
    struct sLinkedList *next;
};

typedef struct sLinkedList node;

node *start = NULL;

node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

node *lastNode(){
    node *temp;
    temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;

}

int countNode(){
    node *temp;
    int count=0;
    temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
        count++;
    }

    return ++count;
}

void createList(int n){
    node *newnode, *temp;
        for(int i=0;i<n;i++){
        newnode = getnode();
        if(start == NULL){
            start = newnode;
            end = newnode;
            }else{
        temp = lastNode();
        temp->next = newnode;
    }

    }
}

void push(int n){
    node *newnode,*temp;
    if(countNode()>=n){
        printf("\nQueue is full....");
    }else{
        if(start==NULL){
            start = newnode;
        }else{
            newnode = getnode();
            temp = lastNode();
            temp->next = newnode;
            printf("\nElement inserted successfully...");
        }
    }
}

void pop(int n){
    node *temp;
    if(countNode()<=0){
        printf("\nQueue is empty...");
    }else{
        temp = start;
        start = temp->next;
        printf("\npoped element is %d",temp->data);
        free(temp);
    }
}

void traverse(){
    node *temp;
    temp = start;
    printf("\nThe elements of the queue are\n");
    while(temp->next!=NULL){
        printf("\t%d\t",temp->data);
        temp = temp->next;
    }
    printf("\t%d\t",temp->data);
}

void main(){
    int option,n;
    printf("\nEnter the size of the Queue: ");
    scanf("%d",&n);
    createList(n);
    while(1){
        printf("\nSelect the option you wanna perform\n");
        printf("\n1.push");
        printf("\n2.POP");
        printf("\n3.Traverse");
        printf("\n4.exit");
        printf("\n> ");
        scanf("%d",&option);

        switch(option){
            case 1:
            push(n);
            break;
            case 2:
            pop(n);
            break;
            case 3:
            traverse();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nInvalid OPtion");
            break;
        }
    }
}
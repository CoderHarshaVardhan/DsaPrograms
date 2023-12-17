#include<stdio.h>
#include<stdlib.h>

struct slink{
    int data;
    struct slink *next;
};

typedef struct slink node;

node *start = NULL;

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

node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

node *lastNode(){
    node *last;
    last = start;
    while(last->next!=NULL){
        last = last->next;
    }
    return last;
}

void createList(int n){
    node *newnode, *temp;
    for(int i=0;i<n;i++){
        newnode = getnode();
        if(start == NULL){
            start = newnode;
        }else{
            temp = lastNode();
            temp->next = newnode;  
        }
    }
}



void push(int n){
    node *newnode, *temp;
    if(countNode()>=n){
        printf("\nStack overflow....");
    }else{
        newnode = getnode();
        if(start==NULL){
            start = newnode;
        }else{
            temp =lastNode();
            temp->next = newnode;
        }
    }
}

void pop(int n){
    node *temp, *prev;
    if(countNode()<=0){
        printf("\nStack underflow....");
    }else{
        temp = start;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
    }
        prev->next = NULL;
        free(temp);
        printf("\nElement poped successfully...");
    }
}

int display(){
    node *temp;
    printf("\nThe content of the stack are\n");
    temp = start;
    while(temp->next!=NULL){
        printf("\t%d\t",temp->data);
        temp = temp->next;
        }
    printf("\t%d\t",temp->data);
    }



void main(){
    int option,n;
    printf("\nEnter the size of the stack: ");
    scanf("%d",&n);
    createList(n);
    printf("\nStack created Successfully...");
    while(1){
        printf("\nSelect the operation you wanna perform");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
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
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nInvalid option...");
            break;
        }
    }
}

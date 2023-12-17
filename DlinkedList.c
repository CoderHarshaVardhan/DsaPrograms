#include<stdio.h>
#include<stdlib.h>

struct link{
    int data;
    struct link *next;
    struct link *prev;
};

typedef struct link node;
node *start = NULL;

node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
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

void createList(int n){
    node *newnode, *temp;
    for(int i=0;i<n;i++){
        newnode = getnode();
        if(start == NULL){
            start = newnode;
            }else{
        temp = lastNode();
        temp->next = newnode;
        newnode->prev = temp;
    }
    }
}

node *lastSecondNode(){
    node *temp, *prev;
    temp = start;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    return prev;
}

int traverse(){
    node *temp;
    if(start==NULL){
        printf("\nEmpty List...");
    }else{
        printf("\nThe content of the list are\n");
        temp = start;
        while(temp->next!=NULL){
            printf("\t%d\t",temp->data);
            temp = temp->next;
            }
        printf("\t%d\t",temp->data);
        printf("\nThe contents of the list from end\n");
        temp = lastNode();
        while(temp->prev!=NULL){
            printf("\t%d\t",temp->data);
            temp = temp->prev;
        }
        printf("\t%d\t",temp->data);
    }
}

int count(){
    node *temp;
    int count = 0;
    temp = start;
    while(temp->next!=NULL){
        count++;
        temp = temp->next;
    }
    return ++count;
}

void insertAtBig(){
    node *newnode, *temp;
    newnode = getnode();
    if(start==NULL){
        start = newnode;
    }else{
        start->prev = newnode;
        newnode->next = start;
        start = newnode;
        printf("\nNode inserted Successfully...");
    }
}


void insertAtEnd(){
    node *newnode,*temp;
    newnode = getnode();
    if(start==NULL){
        start = newnode;
    }else{
        temp = lastNode();
        temp->next = newnode;
        newnode->prev = temp;
        printf("\nNode inserted Successfully...");
    }
}

void insertAtMid(int pos){
    node *newnode, *temp, *prev;
    if(start==NULL){
        printf("List is Empty");
    }else{
        if(pos>1&&pos<count()){
            newnode = getnode();
            temp = start;
            for(int i=2;i<=pos;i++){
                prev = temp;
                temp = temp->next;
                }
            newnode->prev = prev;
            newnode->next = temp;
            temp->prev = newnode;
            prev->next = newnode;
            printf("\nNode inserted Successfully...");
        }else{
            printf("\nInvalid position...");
        }
    }
}

void deleteAtBig(){
    node *newnode, *temp;
    if(start == NULL){
        printf("\nNo nodes to delete....");
    }else{
        temp = start->next;
        temp->prev = NULL;
        free(start);
        start = temp;
        printf("\nNode delted Succesfully....");
    }
}

void deleteAtEnd(){
    node *temp, *prev;
    if(start==NULL){
        printf("\nNo nodes to delete..");
    }else{
        temp = lastNode();
        prev = lastSecondNode();
        prev->next = NULL;
        free(temp);
        printf("\nNode deleted Successfully....");
    }
}

void deleteAtMid(int pos){
    node *temp1,*temp2,*prev;   
    if(start==NULL){
        printf("\nNo nodes to delete...");
    }else{
        temp1 = start;
        if(pos>1&&pos<count()){
            for(int i=2;i<=pos;i++){
                prev = temp1;
                temp1 = temp1->next;
                }
                temp2 = temp1->next;
                prev->next = temp2;
                temp2->prev = prev;
                free(temp1);
                printf("\nNode deleted Successfully...");
                }else{
                    printf("\nInvalid Position....");
                    }
        }
}

void main(){
    int option,n,pos;
    do{
        printf("\nselect your option\n");
        printf("\n1.Create list");
        printf("\n2.Insert a node at bigining");
        printf("\n3.Insert a node at end");
        printf("\n4.Insert a node in the middle");
        printf("\n5.Delete a node at bigining");
        printf("\n6.Delete a node at end");
        printf("\n7.Delete a node in the middle");
        printf("\n8.Traverse the list");
        printf("\n9.To know the Number of nodes");
        printf("\n10.exit");
        printf("\n>");
        scanf("%d",&option);

        switch(option){
            case 1:
            if(start==NULL){
                printf("\nEnter the number of nodes to create: ");
                scanf("%d",&n);
                createList(n);
                printf("\nList created Successfully...");
            }else{
                printf("\nList already exists....");
            }
            break;
            case 2:
            insertAtBig();
            break;
            case 3:
            insertAtEnd();
            break;
            case 4:
            printf("\nEnter the position at which you wanna insert: ");
            scanf("%d",&pos);
            insertAtMid(pos);
            break;
            case 5:
            deleteAtBig();
            break;
            case 6:
            deleteAtEnd();
            break;
            case 7:
            printf("\nEnter the position at which you wanna delete: ");
            scanf("%d",&pos);
            deleteAtMid(pos);
            break;
            case 8:
            traverse();
            break;
            case 9:
            printf("\nNumber of nodes = %d",count());
            break;
            default:
            printf("\nInvalid option....Please select valid option...");
            break;

        }
    }while(option!=10);

}

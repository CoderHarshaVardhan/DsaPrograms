#include<stdio.h>
#include<stdlib.h>

struct cLinkedList{
    int data;
    struct cLinkedList *next;
    struct cLinkedList *prev;
};

typedef struct cLinkedList node;

node *start = NULL;
node *end = NULL;

node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
}

node *lastnode(){
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
        if(start==NULL){
            start = newnode;
        }else{
            temp = lastnode();
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    end = lastnode();
    end->next = start;
    start->prev = end;

}

void traverse(){
    node *temp;
    printf("\nThe contents of list from left to right\n");
    temp = start;
    while(temp->next!=start){
        printf("\t%d\t",temp->data);
        temp = temp->next;
    }
    printf("\t%d\t",temp->data);
    printf("\nThe contents of the list from right to left\n");
    temp = end;
    while(temp->prev!=end){
        printf("\t%d\t",temp->data);
        temp = temp->prev;
    }
    printf("\t%d\t",temp->data);

}

int countNode(){
    int count=0;
    node *temp = start;
    while(temp->next!=start){
        temp = temp->next;
        count++;
    }
    return ++count;
}

void insertAtBig(){
    node *newnode;
    newnode = getnode();
    if(start==NULL){
        start = newnode;
    }else{
        newnode->prev = start->prev;
        start->prev = newnode;
        newnode->next = start;
        start = newnode;
        end->next = newnode;
        printf("\nNode inserted Successfully...");
    }

}

void insertAtEnd(){
    node *newnode;
    newnode = getnode();
    if(start==NULL){
        start = newnode;
    }else{
        end->next = newnode;
        newnode->prev = end;
        newnode->next = start;
        start->prev = newnode;
        end = newnode;
        printf("\nNode inserted Successfully...");
    }
}

void insertAtMid(int pos){
    node *newnode, *temp;
    newnode = getnode();
    if(start==NULL){
        start = newnode;
    }else{
        if(pos>1&&pos<countNode()){
            temp = start;
            for(int i=2;i<=pos;i++){
                temp = temp->next;
            }
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
            newnode->next = temp;
            printf("\nNode inserted successfully....");
        }else{
            printf("\nEntered Position is not a middle position..");
        }
    }
}

void deleteAtBig(){
    if(start == NULL){
        printf("\nList is empty....");
    }else{
        start = start->next;
        free(start->prev);
        start->prev = end;
        end->next = start;

    }
}

void deleteAtEnd(){
    if(start==NULL){
        printf("\nNo Nodes to delete....");
    }else{
        end = end->prev;
        free(end->next);
        end->next = start;
        start->prev = end;
        printf("\nNode deleted Successfully...");
    }
}

void deleteAtMid(int pos){
    node *temp;
    if(start==NULL){
        printf("\nList is empty....");
    }else{
        if(pos>1&&pos<countNode()){
            temp = start;
            for(int i=2;i<=pos;i++){
                temp = temp->next;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
        }
    }

}


void main(){
    int option,n,pos;
    while(1){
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
            printf("\nNumber of nodes = %d",countNode());
            break;
            case 10:
            exit(0);
            break;
            default:
            printf("\nInvalid option....Please select valid option...");
            break;

        }
    }

}
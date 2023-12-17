#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int start = 0, end = -1, a[SIZE];


void enQueue(int n){
    if(end>=SIZE-1){
        printf("\nQueue over flow.....");
    }else{
        a[++end] = n;
        printf("\nelement %d pushed successfully",n);
    }
}

void deQueue(){
    if(end<=start){
        printf("\nQUeue underflow.....");
    }else{
        start++;
        printf("\nElement deleted successfully...");
    }
}

void traverse(){
    if(end<=start){
        printf("\nQueue is empty...");
    }else{
        for(int i=start;i<=end;i++){
            printf("%d\t",a[i]);
        }
    }
}

void main(){
    int n,option;
    while(1){
        printf("\nEnter the operation you wanna perform...");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n>");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("\nEnter the element you wanna insert: ");
            scanf("%d",&n);
            enQueue(n);
            break;
            case 2:
            deQueue();
            break;
            case 3:
            traverse();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Invalid option.....");
        }
    }

}
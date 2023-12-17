#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int top = -1, a[SIZE];


void push(int n){
    if(top>=SIZE-1){
        printf("\nStack over flow.....");
    }else{
        a[++top] = n;
        printf("\nelement %d pushed successfully",n);
    }
}

void pop(){
    if(top<=-1){
        printf("\nStack underflow.....");
    }else{
        top--;
        printf("\nElement poped successfully...");
    }
}

void traverse(){
    if(top<=-1){
        printf("\nStack is empty...");
    }else{
        for(int i=0;i<=top;i++){
            printf("%d\t",a[i]);
        }
    }
}

void main(){
    int n,option;
    while(1){
        printf("\nEnter the operation you wanna perform...");
        printf("\n1.Push\n2.Pop\n3.Display\n4.exit\n>");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("\nEnter the element you wanna insert: ");
            scanf("%d",&n);
            push(n);
            break;
            case 2:
            pop();
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
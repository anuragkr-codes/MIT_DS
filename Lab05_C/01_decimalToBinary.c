#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int* arr;
    int size;
    int top;
}stack;

void initializeStack(stack* st){
    st->size = 1000;
    st->arr = (int*)calloc(st->size, sizeof(int));
    st->top = -1;
}

bool isEmpty(stack* st){
    return st->top == -1;
}

bool pushStack(stack* st, int data){
    if((st->top) + 1 >= st->size) //check for overflow
        return false;
    else{
        st->arr[++(st->top)] = data;
        return true;
    }
}

int popStack(stack* st){
    if(isEmpty(st))
        return -1;
    else{
        int topEle = st->arr[st->top];
        (st->top)--;
        return topEle;
    }
}

void printInBinary(int n){
    stack st;
    initializeStack(&st);
    while(n > 0){
        int lastBit = n&1;
        n = n>>1;
        bool ok = pushStack(&st, lastBit);
    }
    //now print
    while(!isEmpty(&st)){
        printf("%d",popStack(&st));
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter decimal number to convert to binary : ");
    scanf("%d", &n);
    printf("The equivalent binary representation is : ");
    printInBinary(n);
    
    return 0;
}
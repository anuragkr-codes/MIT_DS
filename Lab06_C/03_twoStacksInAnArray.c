#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
    int size;
    int *arr;
    int top1, top2;
}twoStack;

bool isEmpty(twoStack *st, int stackNo){
    if(stackNo == 1 && st->top1 == -1)
        return true;
    else if(stackNo == 2 && st->top2 == st->size)
        return true;
}

void initializeTwoStack(twoStack *st, int size){
    st->size = size;
    st->arr = (int*)calloc(size, sizeof(int));
    st->top1 = -1;
    st->top2 = size;
}

bool pushStack(twoStack *st,int stackNo, int data){
    if(st->top1 + 1 == st->top2){
        return false; //stack overflow
    }
    else{
        if(stackNo == 1){
            st->arr[++(st->top1)] = data;
            return true;
        }
        else{
            st->arr[--(st->top2)] = data;
            return true;
        }
    }
}

bool popStack(twoStack *st, int stackNo){
    if(stackNo == 1){
        if(st->top1 == -1)
            return false;
        else{
            (st->top1)--;
            return true;
        }
    }
    else{
        if(st->top2 == st->size)
            return false;
        else{
            (st->top2)++;
            return true;
        }
    }
}

int topStack(twoStack *st, int stackNo){
    if(stackNo == 1){
        if(st->top1 == -1)
            return -1;
        else{
            return st->arr[st->top1];
        }
    }
    else{
        if(st->top2 == st->size)
            return -1;
        else{
            return st->arr[st->top2];
        }
    }
}

int main() {
    twoStack st;
    initializeTwoStack(&st, 100);
    pushStack(&st, 2, 10);
    pushStack(&st, 2, 11);
    pushStack(&st, 2, 12);
    pushStack(&st, 2, 13);
    pushStack(&st, 1, 1);
    pushStack(&st, 1, 2);
    pushStack(&st, 1, 3);
    printf("top of stack1 : %d\n", topStack(&st, 1)); 
    printf("top of stack2 : %d\n", topStack(&st, 2)); 
    printf("Popping stack 1 \n");
    popStack(&st, 1);
    printf("Popping stack 2 \n");
    popStack(&st, 2);
    printf("top of stack1 : %d\n", topStack(&st, 1)); 
    printf("top of stack2: %d\n", topStack(&st, 2)); 
}
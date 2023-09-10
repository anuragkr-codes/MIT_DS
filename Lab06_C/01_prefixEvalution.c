#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int size;
    int *arr;
    int top;
}Stack;

void initializeStack(Stack* st, int size){
    st->size = size;
    st->arr = (int*)calloc(size, sizeof(int));
    st->top = -1;
}

bool isEmpty(Stack* st){
    return st->top == -1;
}

bool pushStack(Stack *st, int data){
    if(st->top >= st->size-1)
        return false; //overflow
    else{
        st->arr[++(st->top)] = data;
        return true;
    }
}

int topStack(Stack* st){
    if(isEmpty(st))
        return -1;
    else{
        return st->arr[st->top];
    }
}

bool popStack(Stack* st){
    if(isEmpty(st))
        return false;
    else{
        (st->top)--;
        return true;
    }
}

int main() {
    char* exp;
    printf("Enter a valid prefix expression : \n");
    scanf("%s", exp);
    Stack st;
    initializeStack(&st, 100);
    int length = strlen(exp);
    //in prefix we start from right side and top element of stack gives ele1 , 2nd top gives ele2.
    //in postfix we start from left side and top element of stack gives ele2, 2nd top gives ele1.
    for(int i = length-1; i >= 0; i--){
        char ch = exp[i];
        if(ch == '/' || ch == '*' || ch == '+' || ch == '-'){
            int ele1 = topStack(&st);
            popStack(&st);
            int ele2 = topStack(&st);
            popStack(&st);
            int tempAns = 0;
            if(ch == '*'){
                tempAns = ele1*ele2;
            }
            else if(ch == '/'){
                tempAns = ele1/ele2;
            }
            else if(ch == '+'){
                tempAns = ele1+ele2;
            }
            else if(ch == '-'){
                tempAns = ele1-ele2;
            }        
            pushStack(&st, tempAns);
        }
        else{
            int num = ch - '0';
            pushStack(&st, num);
        }
    }
    printf("Output of given prefix expression is = %d", topStack(&st));

return 0;
}
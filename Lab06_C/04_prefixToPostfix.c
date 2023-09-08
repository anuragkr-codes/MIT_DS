#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int size;
    char **arr; //points to first block of rows. which furter has addresses to 1d arrays(of character)
    int top;
}Stack; //string stack

void initializeStack(Stack* st, int size){
    st->size = size;
    st->arr = (char**)calloc(size, sizeof(char*));
    st->top = -1;
}

bool isEmpty(Stack* st){
    return st->top == -1;
}

bool pushStack(Stack *st, char* data){
    if(st->top+1 >= st->size)
        return false; //overflow
    else{
        st->arr[++(st->top)] = data;
        return true;
    }
}

char* topStack(Stack* st){
    if(isEmpty(st))
        return NULL;
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

char* prefixToPostfix(char *prefix, int length){
    Stack st; //string stack
    initializeStack(&st, 100);
    //either reverse the prefix string or start from right side. I start from right side.
    for(int i = length-1; i >= 0; i--){
        char ch = prefix[i];
        //we push operands into the stack. As soon as an operator is encountered top two strings are popped out and concatenated with operator at the end. and finally pushed again back in the stack.
        char* chStr = (char*)calloc(2, sizeof(char));
        chStr[0] = ch;
        chStr[1] = '\0';
        if(ch != '/' && ch != '*' && ch != '+' && ch != '-'){ //means ch is an operand
            pushStack(&st, chStr);
        }
        else{ //means ch is one of the operators
            //pop out two recent strings from the stack and concatenate them as str1+str2+operator
            char* str1 = topStack(&st);
            popStack(&st);
            char* str2 = topStack(&st);
            popStack(&st);
            int newStrLength = strlen(str1) + strlen(str2) + 1 + 1;
            char* newStr = (char*)calloc(newStrLength, sizeof(char));
            strcat(newStr, str1);
            strcat(newStr, str2);
            strcat(newStr, chStr);
            //push it back into the stack
            pushStack(&st, newStr);
        }
    }
    return topStack(&st);
}

int main() {
    char *prefix;
    printf("Enter prefix expression to convert to postfix : ");
    scanf("%s", prefix);
    int length = strlen(prefix);
    printf("Entered prefix expression is : %s\n", prefix);
    printf("Length of entered prefix expression is : %d\n", length);
    char* postfix = (char*)calloc(length, sizeof(char));
    postfix = prefixToPostfix(prefix, length);
    printf("The equivalent postfix expression is : %s", postfix);

return 0;
}
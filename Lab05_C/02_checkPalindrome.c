#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int size;
    char *arr;
    int top;
}Stack; //character stack

void initializeStack(Stack* st, int size){
    st->size = size;
    st->arr = (char*)calloc(size, sizeof(char));
    st->top = -1;
}

bool isEmpty(Stack* st){
    return st->top == -1;
}

bool pushStack(Stack *st, char data){
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

bool checkPalindrome(char* str){
    int length = strlen(str);
    Stack st;
    initializeStack(&st, 100);
    int i = 0;
    while(i < length/2){
        pushStack(&st, str[i++]);
    }
    if(length & 1)//check for odd length
        i++;
    
    //now check if other half is same as first reversed half
    while(!isEmpty(&st)){
        if(topStack(&st) == str[i]){
            popStack(&st);
            i++;
        }
        else{
            return false;
        }
    }

    return true;
}

int main() {
    char *str;
    printf("Enter a string to check palindrome or not : ");
    gets(str);
    bool ans = checkPalindrome(str);
    if(ans)
        printf("Entered string is a valid Palindrome.");
    else
        printf("Entered string is NOT a palindrome!");

return 0;
}
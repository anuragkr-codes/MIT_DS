#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int size;
    char *arr;
    int top;
}Stack;

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

bool relativePrecedence(char opr1, char opr2){
    //this function returns true if opr1 has more precedence than opr2
    //while calling this funcn opr2 represents the operator on top of the stack
    if(opr1 == opr2)
        return true;
    
    if(opr1 == '/'){
        if(opr2 == '*')
            return false;
        else if(opr2 == '+' || opr2 == '-' || opr2 == '(')
            return true;    
    }
    else if(opr1 == '*'){
        if(opr2 == '/')
            return false;
        else if(opr2 == '+' || opr2 == '-' || opr2 == '(')
            return true;    
    }
    else if(opr1 == '+'){
        if(opr2 == '(')
            return true;
        else
            return false;
    }
    else// if(opr1 == '-'){
        {
        if(opr2 == '(')
            return true;
        else
            return false;    
    }
}

void convertToPostfix(char* exp, int length, char* postFix){
    Stack st; //character stack
    initializeStack(&st, 100);
    int j = 0; 
    for(int i = 0; i < length; i++){
        char ch = exp[i];
        if(ch == '/' || ch == '*' || ch == '+' || ch == '-'){
            if(isEmpty(&st)){
                pushStack(&st, ch);
            }
            else{
                if(relativePrecedence(ch, topStack(&st))){
                    pushStack(&st, ch);
                }
                else{
                    while(!relativePrecedence(ch, topStack(&st)) && !isEmpty(&st)){
                        postFix[j++] = topStack(&st);
                        popStack(&st);
                    }
                    pushStack(&st, ch);
                }
            }
        }
        else if(ch == '('){
            pushStack(&st, ch);
        }
        else if(ch == ')'){
            //pop and print untill opening bracket found in the stack
            while(topStack(&st) != '('){
                postFix[j++] = topStack(&st);
                popStack(&st);
            }
            popStack(&st);
        }
        else{
            postFix[j++] = ch;
        }
    }
    while(!isEmpty(&st)){
        postFix[j++] = topStack(&st);
        popStack(&st);
    }
}

int main() {
    char* exp;
    printf("Enter a valid infix expression to convert to postfix: \n");
    scanf("%s", exp);
    int length = strlen(exp);
    char* postFix = (char*)calloc(length, sizeof(char));
    //use a stack. If operand -> simply print it..only operators and opening bracket goes into the stack. We maintain low to 
    //high operator precedence in stack. follow precedence : / = * and + = -. For same precedence operators, treat the one coming first as of higher precedence
    convertToPostfix(exp, length, postFix);    
    printf("The postfix expression is : %s", postFix);
return 0;
}
#include<stdio.h>
#include<string.h>
#define MAX 50

struct Stack{
    char arr[MAX];
    int top;
}s;

void push(char ch){
    s.top++;
    s.arr[s.top] = ch;
}

char pop(){
    return s.arr[s.top--];
}

int precedence(char ch){
    switch(ch){
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
        default:
            return 0;
    }
}

void main(){
    int i,j,c;
    char temp,choice='y';
    char infix[MAX],postfix[MAX];

    while(choice=='y'){
        c=0;
        printf("Enter infix expression:\n");
        scanf(" %[^\n]", infix);
        fflush(stdin);

        for(i=0;i<strlen(infix);i++){
            switch(infix[i]){

            case'(':
                push(infix[i]);
                break;

            case ')':
                while(s.arr[s.top]!='(')
                        postfix[c++]=pop();
                temp = pop();
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                if(precedence(s.arr[s.top])>=precedence(infix[i])){
                    while(precedence(s.arr[s.top])>=precedence(infix[i]))  //check the >= sign if anything goes wrong
                        postfix[c++]=pop();
                    push(infix[i]);
                }
                else{
                    push(infix[i]);
                }
                break;

            default:
                postfix[c++]=infix[i];
            }
        }

        while(s.top!=-1){
            postfix[c++]=pop();
        }
        postfix[c]='\0';
        printf("Postfix Expression is:\n");
        for(i=0;i<c;i++)
            printf("%c",postfix[i]);
        printf("\n");

        printf("Another?(y/n):\n");
        scanf("%c",&choice);
    }
}

//Scan all the symbols one by one from left to right in the given Infix Expression.
//If the reading symbol is an operand, then immediately append it to the Postfix Expression.
//If the reading symbol is left parenthesis ‘( ‘, then Push it onto the Stack.
//If the reading symbol is right parenthesis ‘)’, then Pop all the contents of the stack until
//the respective left parenthesis is popped and append each popped symbol to Postfix Expression.
//If the reading symbol is an operator (+, –, *, /), then Push it onto the Stack.
//However, first, pop the operators which are already on the stack that have
//higher or equal precedence than the current operator and append them to the postfix.
//If an open parenthesis is there on top of the stack then push the operator into the stack.
//If the input is over, pop all the remaining symbols from the stack and append them to the postfix.

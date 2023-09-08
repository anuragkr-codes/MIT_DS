#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
	int size;
	char *arr;
	int top;
}stack;

void initializeStack(stack *st){
	st->size = 1000;
	st->arr = (char*)calloc(st->size, sizeof(char)); 
	st->top = -1;
}

bool isEmpty(stack *st){
	if(st->top == -1)
		return true;
	else
		return false;
}


bool push_stack(stack *st, char data){
	if((st->top)+1 >= st->size) //check for overflow
		return false;
	else{
		st->arr[++(st->top)] = data;
		return true;
	}
}

char pop_stack(stack *st){
	if(isEmpty(st)) //check for underflow
		return '/';
	else{
		int temp = st->top;
		(st->top)--;
		return st->arr[temp];
	}
}
			
bool checkValidParenthesis(char *expn){
	stack st;
	initializeStack(&st);
	int i = 0;
	while(expn[i] != '\0'){
		char ch = expn[i];
		if(ch == '{'){
			push_stack(&st, ch);
			i++;
		}
		else if(ch == '}'){
			if(isEmpty(&st)){
				return false;
			}
			else{
				char topEle = pop_stack(&st);
				i++;
			}
		}
		else{
			i++;
		}
	}
	//final check
	if(isEmpty(&st))
		return true;
	else
		return false;
}
			
int main(){
	char* expn = (char*)calloc(100, sizeof(char));
	printf("Enter the expression to check valid or not : \n");
	scanf("%s", expn);
	bool valid = checkValidParenthesis(expn);
	if(valid)
		printf("Entered expression is valid!");
	else
		printf("Entered expression is NOT valid");
return 0;
}

	
	

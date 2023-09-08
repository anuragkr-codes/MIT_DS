#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int* arr;
    int size;
    int top;
}stack;

void initializeStack(stack* st, int size){
    st->size = size;
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

bool popStack(stack* st){
    if(isEmpty(st))
        return false;
    else{
        (st->top)--;
        return true;
    }
}

int topStack(stack* st){
    if(isEmpty(st))
        return -1;
    else{
        return st->arr[st->top];
    }
}

int* takeArrayInput(int size){
    int *arr = (int*)calloc(size, sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%d", arr+i);
    }
    return arr;
} 

void printArr(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void solve(int *arr, int n, int k){
    stack st;
    initializeStack(&st, 100);
    int count = 0;
    int i = 0;
    while(count != k && i<n){
        int ele = arr[i];
        if(isEmpty(&st)){
            pushStack(&st, ele);
            i++;
        }
        else{
            //check if top element is greater than the curr element
            if(topStack(&st) >= ele){
                pushStack(&st, ele);
                i++;
            }
            else{
                popStack(&st);
                count++;
            }
        }
    }

    //make the final array using stack elements and leftout string
    int newLength = st.top+1+(n-i);
    int *ans = (int*)calloc(newLength, sizeof(int));
    int j = 0;
    while(!isEmpty(&st)){
        ans[j++] = topStack(&st);
        popStack(&st);
    }
    while(i < n){
        ans[j++] = arr[i++];
    }
    printf("The modified array after the required operations is : ");
    printArr(ans, newLength);
}


int main() {
    int n, k;
    printf("Enter the no of elements and value of k : ");
    scanf("%d %d", &n, &k);
    int *arr;
    printf("Enter %d elements of the array : \n", n);
    arr = takeArrayInput(n);
    printf("The entered array is : \n");
    printArr(arr, n);
    solve(arr, n, k);
return 0;
}
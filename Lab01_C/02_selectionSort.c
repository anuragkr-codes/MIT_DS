#include<stdio.h>

void swap(int *a,  int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int size){
	for(int i=0; i<size-1; i++){
		// int minElement = arr[i];
		int minIndex = i;
		for(int j=i; j<size; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(&arr[i], &arr[minIndex]);
	}
}

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){

	int arr[100];
	int size;

	//input
	printf("Enter the number of elements : ");
	scanf("%d", &size);

	printf("Enter the elements : \n");

	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	//function Call
	selectionSort(arr, size);

	//output
	printArray(arr, size);
	

return 0;
}
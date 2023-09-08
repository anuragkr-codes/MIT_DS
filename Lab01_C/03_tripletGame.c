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

void printTriplets(int arr[], int size){
	for(int i=0; i<size; i++){
		int fixedEle = arr[i];
		int s = i+1;
		int e = size-1;
		

		while(s < e){
			if(arr[s] + arr[e] + fixedEle == 0){
				printf("(%d, %d, %d) \n", fixedEle, arr[s], arr[e]);
				break;
			}
			else if(arr[s] + arr[e] + fixedEle < 0)
				s++;
			else if(arr[s] + arr[e] + fixedEle > 0)
				e--;
		}
	}
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

	//function call
	//step 1 : sort
	selectionSort(arr, size);
	printTriplets(arr, size);

return 0;
}
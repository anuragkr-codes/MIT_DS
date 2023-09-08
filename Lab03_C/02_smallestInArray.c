#include<stdio.h>
#include<stdlib.h>
int smallest(int *arr, int size){
	int ans = arr[0];
	for(int i = 0; i < size; i++){
		if(arr[i] < ans)
			ans = arr[i];
	}
	return ans;
}
int main(){
	int size;
	printf("Enter the size of the array : ");
	scanf("%d", &size);
	int *arr = (int*)calloc(size, sizeof(int));
	printf("Now enter the elements : \n");
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	int smallestEle = smallest(arr, size);
	printf("The smallest element in the array is : %d \n", smallestEle); 
	free(arr);
return 0;
}

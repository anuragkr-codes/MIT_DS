#include<stdio.h>

int binarySearch(int *arr, int s, int e, int key){
	//base case
	if(s > e){
		return -1;
	}

	int mid = s + (e-s)/2;
	if(arr[mid] == key)
		return mid;
	else if(key > arr[mid])
		return binarySearch(arr, mid+1, e, key);
	else
		return binarySearch(arr, s, mid-1, key);
}

int main(){
	int arr[100];
	int size;
	int key;
	printf("Enter the size of the array : ");
	scanf("%d", &size);

	//input 
	printf("Now enter the elements : \n");
	for(int i = 0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the element to search : ");
	scanf("%d", &key);

	int index = binarySearch(arr, 0, size-1, key);

	if(index == -1){
		printf("Element not found! \n");
	}
	else{
		printf("Element found at index %d \n", index);
	}

return 0;
}
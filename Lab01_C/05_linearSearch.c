 #include<stdio.h>

int linearSearch(int *arr, int size, int key){
	for(int i=0; i<size; i++){
		if(arr[i] == key)
			return i;
	}

	return -1;
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

	printf("Enter the element to search (linear search) : ");
	scanf("%d", &key);

	int index = linearSearch(arr, size, key);

	if(index == -1){
		printf("Element not found! \n");
	}
	else{
		printf("Element found at index %d \n", index);
	}

return 0;
}
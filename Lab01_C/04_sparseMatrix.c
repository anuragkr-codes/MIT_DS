#include<stdio.h>
#include<stdbool.h>

bool checkSparse(int arr[][20], int rows, int cols){
	// sparse matrix is a matrix with no of zeroes more than the number of rest of the elements.
	int count = 0;
	int size = rows*cols;

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(arr[i][j] == 0)
				count++;
			if(count > (size/2))
				return true;
		}
	}

	return false;
}

int main(){

	int arr[20][20];
	int rows, cols;

	//input
	printf("Enter the number of rows and columns of the 2d matrix : ");
	scanf("%d %d", &rows, &cols);

	printf("Enter the elements : \n");

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	//function Call
	bool answer = checkSparse(arr, rows, cols);

	//output
	if(answer){
		printf("The entered matrix is a sparse matrix\n");
	}
	else{
		printf("Not a sparse Matrix. \n");
	}	

return 0;
}
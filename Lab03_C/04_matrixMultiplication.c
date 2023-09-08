#include<stdio.h>
#include<stdlib.h>

int** multiplyMat(int **matrix1, int **matrix2, int rows1, int cols1, int cols2){
	int **ans = (int**)calloc(rows1, sizeof(int*));
	for(int i = 0; i < rows1; i++){
		ans[i] = (int*)calloc(cols2, sizeof(int));
		for(int j = 0; j < cols2; j++){
			int tempSum = 0;
			for(int k = 0; k < cols1; k++){
				tempSum += matrix1[i][k] * matrix2[k][j];
			}
			*(*(ans+i)+j) = tempSum;
		}
	}

	return ans;
}

void display(int **matrix, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("%d ", *(*(matrix+i) + j));
		}
		printf("\n");
	}
}

int main(){
	int rows1;
	int cols1;
	int cols2;
	printf("Enter the no of rows of the first matirx : ");
	scanf("%d", &rows1);
	printf("Enter the no of cols of the first matirx : ");
	scanf("%d", &cols1);
	printf("Enter the no of cols of the second matirx : ");
	scanf("%d", &cols2);

	int **matrix1 =(int**)calloc(rows1, sizeof(int*));
	int **matrix2 =(int**)calloc(cols1, sizeof(int*));	
	//input
	printf("Enter the elements of 1st Matrix: \n");	
	for(int i = 0; i < rows1; i++){
		*(matrix1+i) = (int*)calloc(cols1, sizeof(int));
		for(int j = 0; j < cols1; j++){
			scanf("%d", (*(matrix1+i)+j) );
		}
	}
	printf("Enter the elements of 2nd Matrix: \n");
	for(int i = 0; i < cols1; i++){
		*(matrix2+i) = (int*)calloc(cols2, sizeof(int));
		for(int j = 0; j < cols2; j++){
			scanf("%d", *(matrix2+i)+j);
		}
	}
	
	//output
	printf("matrix1 is : \n");
	display(matrix1, rows1, cols1);
	printf("matrix2 is : \n");
	display(matrix2, rows1, cols2);

	int** multiplicationMatrix = multiplyMat(matrix1, matrix2, cols1, rows1, cols2);
	printf("Multiplied matrix is : \n");
	display(multiplicationMatrix, rows1, cols2);
return 0;
}
	

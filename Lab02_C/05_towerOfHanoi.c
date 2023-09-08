#include<stdio.h>

void towerOfHanoi(int n, char from, char to, char using){
	//base case
	if(n == 0)
		return;

	towerOfHanoi(n-1, from, using, to);
	printf("Move disk %d from %c to %c \n", n, from, to);
	towerOfHanoi(n-1, using, to, from);
}

int main(){

	int n;
	printf("Enter the number of disks : ");
	scanf("%d", &n);

	printf("The steps to solve tower of hanoi game with %d disks is : \n", n);
	towerOfHanoi(n, 'A', 'C', 'B');

return 0;
}
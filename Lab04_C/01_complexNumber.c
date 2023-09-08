#include<stdio.h>

typedef struct complex{
	int Re;
	int Im;
} complex;

complex addComplex(complex a, complex b){
	complex ans;
	ans.Re = a.Re + b.Re;
	ans.Im = a.Im + b.Im;
	return ans;
}

complex diffComplex(complex a, complex b){
	complex ans;
	ans.Re = a.Re - b.Re;
	ans.Im = a.Im - b.Im;
	return ans;
}

complex multiplyComplex(complex a, complex b){
	complex ans;
	ans.Re = (a.Re * b.Re)-(a.Im * b.Im); 
	ans.Im = a.Im*b.Re + a.Re*b.Im;
	return ans;
}

int main() {
	complex a;
	complex b;
	printf("Enter real and imaginary part of 1st complex no: ");
	scanf("%d %d", &a.Re, &a.Im);
	printf("Enter real and imaginary part of 2nd complex no: ");
	scanf("%d %d", &b.Re, &b.Im);
	complex sum = addComplex(a, b);
	complex diff = diffComplex(a, b);
	complex prod = multiplyComplex(a, b);
	printf("The sum is : %d + i%d\n", sum.Re, sum.Im);
	printf("The diff is : %d + i%d\n", diff.Re, diff.Im);
	printf("The multiplication is : %d + i%d\n", prod.Re, prod.Im);
	return 0;
}


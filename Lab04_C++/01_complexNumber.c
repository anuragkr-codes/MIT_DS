#include<iostream>
using namespace std;

typedef struct complex{
	int Re;
	int Im;
} complex;

complex addComplex(complex a, complex b){
	complex ans;
	ans.Re = a.Re + b.Re;
	ans.Im = a.Im + b.Re;
	return ans;
}

complex diffComplex(complex a, complex b){
	complex ans;
	ans.Re = a.Re - b.Re;
	ans.Im = a.Im - b.Re;
	return ans;
}

complex addComplex(complex a, complex b){
	complex ans;
	ans.Re = (a.Re * b.Re)-(a.Im * b.Im); 
	ans.Im = a.Im*b.Re + a.Re*b.Im;
	return ans;
}

int main() {
	complex a;
	complex b;
	cout << "Enter real and imaginary part of 1st complex no: ";
	cin >> a.Re >> a.Im;
	cout << "Enter real and imaginary part of 2nd complex no: ";
	cin >> b.Re >> b.Im;
	
	complex sum = addComplex(a + b);
	complex diff = subComplex(a - b);
	complex prod = multiplyComplex(a * b);

	cout << "The sum is : " << sum.Re << " + i" << sum.Im << endl;
	cout << "The diff is : " << diff.Re << " + i" << diff.Im << endl;
	cout << "The sum is : " << prod.Re << " + i" << prod.Im << endl;

return 0;
}


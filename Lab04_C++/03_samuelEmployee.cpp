#include<iostream>
using namespace std;

typedef struct{
	int day;
	int month;
	int year;
} dateOfBirth;

typedef struct{
	int houseNo;
	int zipCode;
	char state[30];
} address;
	
typedef struct employee_data {
	char name[100];
	dateOfBirth dob;
	address add;
} empData;



int main(){
	int n;
	cout << "Enter the count of employees : ";
	cin >> n;	
	empData *data = (empData*)calloc(n, sizeof(empData));
	cout << "Enter the data : " << endl;
	inputMultiple(data, n);
	cout << "The entered data is : " << endl;
	outputMultiple(data, n);
return 0;
}

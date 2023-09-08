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

void inputMultiple(empData* data, int n){
	for(int i = 0; i < n; i++){
		cout << "Enter data of employee number " << i+1 << endl;
		cout << "Name : ";
		cin >> data[i].name;
		cout << "DOB(D,M,Y)(space separated) : ";
		cin >> data[i].dob.day >> data[i].dob.month >> data[i].dob.year;
		cout << "Address : " << endl;
		cout << "House no : ";
		cin >> data[i].add.houseNo;
		cout << "Zip Code : ";
		cin >> data[i].add.zipCode;
		cout << "State : ";
		cin >> data[i].add.state;
	}
}

void outputMultiple(empData* data, int n){
	for(int i = 0; i < n; i++){
		cout << "Data of employee number " << i+1 << ":" << endl;
		cout << "Name : " << data[i].name << endl;
		cout << "DOB : " << data[i].dob.day << "-" << data[i].dob.month << "-" << data[i].dob.year << endl;
		cout << "Address : " << endl;
		cout << "House no : " << data[i].add.houseNo << endl;
		cout << "Zip Code : " << data[i].add.zipCode << endl;
		cout << "State : " <<  data[i].add.state << endl;
	}
}

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

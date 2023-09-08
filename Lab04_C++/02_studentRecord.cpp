#include<iostream>
using namespace std;

typedef struct student{
	char name[100];
	int roll;
	float cgpa;
} student;

void input(student* s){
	cout << "Enter student data in Roll No, Name, CGPA format : "<< endl;
	cin >> s->roll >> s->name >> s->cgpa;
return;
}

void output(student s){
	cout << "Entered record is : " << endl;
	cout << "Roll : " << s.roll << endl;
	cout << "Name : " << s.name << endl;
	cout << "CGPA : " << s.cgpa << endl;
return;
}

void inputMultiple(student* record, int n){
	for(int i=0; i<n; i++){
		cin >> (record+i)->roll;
		cin >> (record+i)->name;
		cin >> (record+i)->cgpa;
	}
return;
}

void  bubbleSortStudentData(student* s, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(s[j].roll > s[j+1].roll){
				student temp;
				temp = s[j+1];
				s[j+1] = s[j];
				s[j] = temp;
			}
		}
	}
}

void outputMultiple(student *s, int n){
	cout << "Roll \t" << "Name \t" << "CGPA \t" << endl;
	for(int i = 0; i<n; i++){
		cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].cgpa << endl;
	}
}


int main(){
	student s;
	int n;
	input(&s);
	output(s);

	cout << "Enter the number of records to sort : ";
	cin >> n;
	student *record = (student*)calloc(n, n*sizeof(s));	
	cout << "Enter the data for each student in Roll No, Name, CGPA format " << endl;
	inputMultiple(record, n);
	bubbleSortStudentData(record, n);
	cout << "The record in sorted order is : " << endl;
	outputMultiple(record, n);

	free(record);
return 0;
}

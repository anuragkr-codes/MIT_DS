#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} dateOfBirth;

typedef struct {
    int houseNo;
    int zipCode;
    char state[30];
} address;

typedef struct {
    char name[100];
    dateOfBirth dob;
    address add;
} empData;

void inputMultiple(empData* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter data of employee number %d\n", i + 1);
        printf("Name : ");
        scanf("%s", data[i].name);
        printf("DOB(D,M,Y)(space separated) : ");
        scanf("%d %d %d", &data[i].dob.day, &data[i].dob.month, &data[i].dob.year);
        printf("Address : \n");
        printf("House no : ");
        scanf("%d", &data[i].add.houseNo);
        printf("Zip Code : ");
        scanf("%d", &data[i].add.zipCode);
        printf("State : ");
        scanf("%s", data[i].add.state);
    }
}

void outputMultiple(empData* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("Data of employee number %d:\n", i + 1);
        printf("Name : %s\n", data[i].name);
        printf("DOB : %d-%d-%d\n", data[i].dob.day, data[i].dob.month, data[i].dob.year);
        printf("Address : \n");
        printf("House no : %d\n", data[i].add.houseNo);
        printf("Zip Code : %d\n", data[i].add.zipCode);
        printf("State : %s\n", data[i].add.state);
    }
}

int main() {
    int n;
    printf("Enter the count of employees : ");
    scanf("%d", &n);
    empData* data = (empData*)calloc(n, sizeof(empData));
    printf("Enter the data : \n");
    inputMultiple(data, n);
    printf("The entered data is : \n");
    outputMultiple(data, n);
    free(data);
    return 0;
}


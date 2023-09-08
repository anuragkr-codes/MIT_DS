#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[100];
    int roll;
    float cgpa;
} student;

void input(student* s) {
    printf("Enter student data in Roll No, Name, CGPA format:\n");
    scanf("%d %s %f", &(s->roll), s->name, &(s->cgpa));
}

void output(student s) {
    printf("Entered record is:\n");
    printf("Roll : %d\n", s.roll);
    printf("Name : %s\n", s.name);
    printf("CGPA : %f\n", s.cgpa);
}

void inputMultiple(student* record, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &record[i].roll, record[i].name, &record[i].cgpa);
    }
}

void bubbleSortStudentData(student* s, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                student temp;
                temp = s[j + 1];
                s[j + 1] = s[j];
                s[j] = temp;
            }
        }
    }
}

void outputMultiple(student* s, int n) {
    printf("Roll \tName \tCGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t%s \t%f\n", s[i].roll, s[i].name, s[i].cgpa);
    }
}

int main() {
    student s;
    int n;
    input(&s);
    output(s);

    printf("Enter the number of records to sort: ");
    scanf("%d", &n);
    student* record = (student*)calloc(n, sizeof(student));
    printf("Enter the data for each student in Roll No, Name, CGPA format:\n");
    inputMultiple(record, n);
    bubbleSortStudentData(record, n);
    printf("The record in sorted order is:\n");
    outputMultiple(record, n);

    free(record);
    return 0;
}

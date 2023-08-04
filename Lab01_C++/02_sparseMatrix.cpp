#include<iostream>
using namespace std;

void print_matrix(int **a, int rows, int cols){
    cout << "The entered matrix is : " << endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int rows;
    int cols;
    cout << "Enter the rows and cols : ";
    cin >> rows >> cols;

    //input
    //int *matrix = new int[rows][100]; // Doesn't work like this.

    //This is one of the ways to create a matrix on heap memory.
    int **a = new int*[rows];
    for(int i=0; i<rows; i++){
        (a[i]) = new int[cols];
    }

    cout << "Enter the values : " << endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> a[i][j];
        }
    }

    print_matrix(a, rows, cols);

return 0;
}
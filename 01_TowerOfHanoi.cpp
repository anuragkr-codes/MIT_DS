//Also coded on gfg https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
#include<iostream>
using namespace std;

void TOH(int n, char from, char to, char aux){
    //base case.
    if(n == 0){
        return;
    }

    TOH(n-1, from, aux, to);
    cout << "Move disc " << n << " from " << from << " to " << to << endl;
    TOH(n-1, aux, to, from);
}

int main(){
    int n;
    cout << "Enter the number of discs for Tower Of Hanoi problem : ";
    cin >> n;
    
    TOH(n, 'A', 'C', 'B'); //A to C using B.

    return 0;
}
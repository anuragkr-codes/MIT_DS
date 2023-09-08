#include<iostream>
using namespace std;

int main(){
    string s = new string(100);
    cout << "Enter a valid prefix expression to evaluate : ";
    cin >> s;
    cout << "The ans of given expression is : " << evaluatePrefix(s) << endl;
    
}
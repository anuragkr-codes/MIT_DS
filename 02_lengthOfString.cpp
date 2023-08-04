#include<iostream>
using namespace std;

int length(string str){
    static int len=0;
    //base case
    if(str[0] == '\0')
        return len;

    len++;
    return length(&str[1]);
}

int main(){
    string str;
    cout << "Enter the string to calculate the length of it : ";
    getline(cin, str);
    cout << str << endl;
    cout << "The lenght of string is (using static variable)" << length(str) << endl;
    return 0;
}
#include<algorithm>
#include<iostream>
using namespace std;

void print_triplets(int *arr, int size){
    //Step 1 : sort the array.
    sort(arr, arr+size);

    //Step 2 : use two pointer approach to find the triplets.
    for(int i=0; i<size; i++){
        int fixed_element = arr[i];
        int s = i+1;
        int e = size-1;
        while(s < e){
            if(fixed_element + arr[s] + arr[e] == 0){
                cout << "(" << fixed_element << ", " << arr[s] << ", " << arr[e] << ")" << endl;
                break;
            }
            else if(fixed_element + arr[s] + arr[e] < 0)
                s++;
            else
                e--;
        }
    }
}

int main(){
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    int *arr = new int[size];

    //input
    cout << "Enter the elements : " << endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    print_triplets(arr, size);
    delete []arr;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void print2Largest(int arr[], int arr_size){
    int i, first, second;
    if(arr_size < 2){
        cout << "Invalid Input"<<endl;
        return;
    }

    int largest = INT_MIN;
    int largi = -1;
    for(int i=0;i<arr_size;i++){
        if(arr[i] > largest){
            largest = arr[i];
            largi = i;
        }
        
    }
    int slar = INT_MIN;
    for(int i=0;i<arr_size;i++){
        if(arr[i] <= largest && i != largi && arr[i] > slar){
            slar = arr[i];
        }
    }
    cout << slar << endl;
}

int main(){
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(int);
    print2Largest(arr, n);
    return 0;
}
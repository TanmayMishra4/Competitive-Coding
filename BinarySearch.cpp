#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(int* arr, int len, int ele){
    int lo = 0;
    int hi = len;
    
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid] >= ele){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(lo < len && arr[lo] < ele){
        return lo+1;
    }
    return lo;
}

int binarySearchRecursive(int* arr, int len, int ele, int low, int high){
    if(low >= high){
        if(low < len && arr[low] < ele){
            return low+1;
        }
        else{
            return low;
        }
    }
    int mid = (low+high)/2;
    if(arr[mid] >= ele){
        return binarySearchRecursive(arr, len, ele, low, mid);
    }
    return binarySearchRecursive(arr, len, ele, mid+1, high);
}

int main(){
    int n;

    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int element;
    cin>>element;
    cout<<"Index using iterative solution: "<<binarySearchIterative(arr, n, element)<<endl;
    cout<<"Index using recursive solution: "<<binarySearchRecursive(arr, n, element, 0, n)<<endl;
}
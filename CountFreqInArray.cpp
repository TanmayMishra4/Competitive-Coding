#include <bits/stdc++.h>
using namespace std;

void countFreq(vector<int>& arr){
    int n = arr.size();
    int i = 0;

    while(i < n){
        if(arr[i] <= 0){
            i++;
            continue;
        } 
        else{
            int ind = arr[i]-1;
            if(arr[ind] <= 0){
                arr[ind]--;
                arr[i] = 0;
            }
            else{
                int temp = arr[ind];
                arr[i] = temp;
                arr[ind] = -1;
            }
        }
    }
    cout << "\n";
    for(int i : arr){
        cout << i << ",  ";
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    countFreq(arr);
    return 0;
}
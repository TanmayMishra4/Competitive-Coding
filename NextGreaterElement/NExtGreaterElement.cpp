#include <bits/stdc++.h>
using namespace std;

void printNge(int arr[], int n){
    cout<<"\n";
    if(n == 0){
        cout<<"array is empty";
    }
    // if(n == 1) cout<<"-1";
    stack<int> st;
    stack<int> ans;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans.push(-1);
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top() < arr[i]){
                st.pop();
            }
            if(st.empty()) st.push(-1);
            else ans.push(st.top());
            st.push(arr[i]);
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" -> ";
        ans.pop();
    }
}

int main(){
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(int);
    printNge(arr, n);
    return 0;
}
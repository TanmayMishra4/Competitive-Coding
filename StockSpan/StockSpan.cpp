#include <bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n){
        vector<int> v;
        if(n == 1){
            v.push_back(1);
            return v;        
        }
        stack<int> st;
        st.push(0);
        v.push_back(1);
        for(int i=1;i<n;i++){
            while(!st.empty() && price[st.top()] <= price[i]){
                st.pop();
            }
            int x = (st.empty())?(i+1):(i-st.top());
            v.push_back(x);
            st.push(i);
            
        }
        return v;

    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int a : calculateSpan(arr, n)){
        cout<<a<<" ";
    }

}
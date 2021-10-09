#include <bits/stdc++.h>
using namespace std;

vector<int> maxWindow(int n, int *A, int k){
    vector<int> v;
    if(k > n){
        int ans = A[0];
        for(int i=0;i<n;i++){
            ans = max(ans, A[i]);
        }
        v.push_back(ans);
        return v;
    }
    deque<int> qi;
    int i;
    for(i=0;i<k;i++){
        while(!qi.empty() && A[qi.back()]<=A[i]){
            qi.pop_back();
        }
        qi.push_back(i);
    }
    for(;i<n;i++){
        v.push_back(qi.front());
        while(!qi.empty() && qi.front()<=i-k){
            qi.pop_front();
        }
        while(!qi.empty() && A[i]>=A[qi.back()])
            qi.pop_back();
        qi.push_back(i);
    }
    v.push_back(qi.front());
    return v;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int w;
    cin>>w;
    cout<<"\n Answer is \n";
    for(auto a : maxWindow(n, arr, w)){
        cout << a<<" ";
    }
}
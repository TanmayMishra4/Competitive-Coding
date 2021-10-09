#include <bits/stdc++.h>
using namespace std;

int maxArea(int n, int A[]){
    vector<int> arr;
    for(int j=0;j<n;j++){
        arr.push_back(A[j]);
    }
    int ans=0,cur;
    stack<int> s;
    s.push(-1);
    
    for (int i=0;i<n;i++)
    {
        while (s.top()!=-1 && arr[s.top()]>arr[i]) // get the right min 
        {
            cur=s.top();
            s.pop();   
            ans=max(ans,(i-s.top()-1)*arr[cur]); // left min is s.top() and calc area for current bar
        }
        s.push(i);
    }
    while (s.top()!=-1) // for the remaining elements in stack right index will be n
    {
        cur=s.top();
        s.pop();
        ans=max(ans,(n-s.top()-1)*arr[cur]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nAnswer is\n"<<maxArea(n, arr)<<"\n";
}
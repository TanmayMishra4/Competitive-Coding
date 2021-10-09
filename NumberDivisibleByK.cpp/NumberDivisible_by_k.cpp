#include <bits/stdc++.h>
using namespace std;


long long smallestMultiple(int x){
    queue<long long> q;
    q.push(1ll);
    while(!q.empty()){
        long long current = q.front();
        q.pop();
        if(current%x == 0){
            return current;
        }
        q.push(current*10);
        q.push(current*10+1);

    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    cout<<"\n Answer is \n"<<smallestMultiple(n);
}
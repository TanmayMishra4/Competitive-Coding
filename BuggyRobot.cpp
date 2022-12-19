#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string st;
    int row=0,col=0;
    cin>>st;
    for(int i=0;i<n;i++){
        if(st[i]=='U'){
            ++col;
        }
        else if(st[i]=='D'){
            --col;
        }
        else if(st[i]=='L'){
            --row;
        }
        else if(st[i]=='R'){
            ++row;
        }
    }

    int val1=abs(row)+abs(col);
    cout<<n-val1;
    return 0;
}
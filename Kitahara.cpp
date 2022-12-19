#include <bits/stdc++.h>
using namespace std;

int main(){
    int one = 0, two = 0;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x == 100) one++;
        else two++;
    }
    two = two%2;
    one = one - 2*two;
    if(one%2 == 0 && one>=0) cout <<"YES\n";
    else cout <<"NO\n";
}
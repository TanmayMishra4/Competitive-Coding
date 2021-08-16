#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> st;
    int t;
    cin >> t;
    while(t--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int x;
            cin >>x;
            st.push(x);
        }
        else if(typ == 2){
            if(st.size() != 0){
                st.pop();
            }
        }
        else{
            if(st.size() == 0){
                cout << "Empty!" <<"\n";
            }
            else{
                cout << st.top() <<"\n";
            }
        }
        
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

list<int> permute(vector<int>& V, string& str){
    int i, n = V.size();
    list<int> l;
    list<int> res;

    sort(V.begin(), V.end());

    for(i=0;i<n;i++){
        l.push_back(V[i]);
    }
    // for(int i : l) cout<<i<<" ";
    for(i=0;i<str.size();i++){
        //insert the code
        if(str[i] == '0'){
            res.push_back(l.back());
            l.pop_back();
        }
        else{
            res.push_back(l.front());
            l.pop_front();
        }
    }

    res.push_back(l.front());
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    string s;
    cin>>s;
    cout<<"\n"<<"Answer is\n";
    for(int i : permute(v, s)){
        cout<<" "<<i<<" ";
    }

}
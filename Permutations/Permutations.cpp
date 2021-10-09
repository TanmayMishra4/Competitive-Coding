#include <bits/stdc++.h>
using namespace std;


void generatePerm(vector<string>& v, string s, int l, int r){
    if(l == r){
        v.push_back(s);
    }
    else{
        for(int i=l;i<=r;i++){
            swap(s[l], s[i]);
            generatePerm(v, s, l+1, r);
            swap(s[i], s[l]);
        }
    }
}


vector<string> generatePerm(string str){
    vector<string> v;
    generatePerm(v, str, 0, str.length()-1);
    return v;
}

int main(){
    string s;
    cin>>s;
    cout<<"\n Answer is \n";
    for(string st : generatePerm(s)){
        cout<< st <<"  ";
    }
    return 0;
}
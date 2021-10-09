#include <bits/stdc++.h>
using namespace std;

void generateBits(int n, string curr, vector<string>& ans){
    if(curr.size() == n){
        ans.push_back(curr);
        return;
    }

    generateBits(n, curr+"0", ans);
    generateBits(n, curr+"1", ans);
}

vector<string> generateBits(int n){
    vector<string> ans;
    generateBits(n, "", ans);
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<string> v = generateBits(n);
    for(auto s : v){
        cout<<s+" ";
    }
    cout<<"\n   size is "<<v.size();
}
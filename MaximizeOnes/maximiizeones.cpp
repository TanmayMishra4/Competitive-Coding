#include <bits/stdc++.h>
using namespace std;

vector<int> maximizeOnes(string str){
    int n=str.size();
    vector<int> A;
    int i,j,k;
    for(i=0;i<n;i++){
        if(str[i]=='0'){
            A.push_back(1);
        }
        else{
            A.push_back(-1);
        }
    }

    // 0111001001
    int start = 0;
    int end = 0;
    int sum = 0;
    int globmax = 0;
    for(int i=0;i<A.size();i++){
        sum += A[i];
        if(sum > globmax){
            globmax = sum;
            end = i;
        }
        if(sum < 0){
            sum = 0;
            start = i+1;
            end = i+1;
        }
    }
    vector<int> v{start, end};
    return v;
}

int main(){
    string s;
    cin>>s;

    cout<<"\n"<<"Answer is \n";
    for(int i : maximizeOnes(s)){
        cout<<" "<<i<<" ";
    }
}
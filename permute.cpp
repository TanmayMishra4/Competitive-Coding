#include <bits/stdc++.h>
using namespace std;

void permute(string& str, int low, int high){
    if(low == high){
        cout << str << endl;
    }
    else{
        for(int i=low;i<=high;i++){
            swap(str[low], str[i]);
            permute(str, low+1, high);
            swap(str[low], str[i]);
        }
    }
}

void permute(string& str){
    permute(str, 0, str.length()-1);
}

int main(){
    string str;
    cout << "enter string" << endl;
    cin >> str;
    cout << "the permutations are: "<< endl;
    permute(str);

    return 0;
}
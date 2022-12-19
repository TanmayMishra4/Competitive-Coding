#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string& A, string& B){
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for(auto c : A){
        arr[c-'a']++;
    }
    for(auto c : B){
        arr[c-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i] != 0) return false;
    }
    return true;
}

int main(){
    string A = "abbbcbaaccacaacc";
    string B = "acaaaccabcabcbcb";
    cout << ((isAnagram(A, B)==1)?"true":"false")<<"\n";
    return 0;
}
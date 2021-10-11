#include <bits/stdc++.h>
using namespace std;

vector<int> nextPerm(vector<int> A){
    if(A.size()==1){
        return A;
    }
    int i,j,n=A.size(),currItem=n-1;
    for(i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            currItem=i;
            break;
        }
    }
    //insert the rest of the code
    int temp = A[currItem];
    A[currItem] = A[n-1];
    A[n-1] = temp;
    sort(A.begin()+currItem+1, A.end());

    return A;
}

int main(){
    vector<int> v{1, 2, 5, 4, 3};
    cout<<"\n";
    for(auto i : nextPerm(v)){
        cout << " "<< i << " ";
    }

}
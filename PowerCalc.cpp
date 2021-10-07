#include <bits/stdc++.h>
using namespace std;


struct Power{
    long long value, countOfOperations;
};  
Power pow(int a, int n){
    long long answer = 1;
    long long count = 0;
    while(n--){
        answer *= a;
        count++;
    }
    Power ans;
    ans.value = answer;
    ans.countOfOperations = count;
    return ans;
}
long long powBetter(int a, int n){
    if(a == 1 || n == 0){
        return 1ll;
    }
    if(n == 1){
        return (long long)a;
    }

    long long half = powBetter(a, n/2);
    if(n%2 == 0){
        return half*half;
    }
    else{
        return half*half*a;
    }
}
int main(){
    int a,n;
    cin>>a>>n;
    Power p = pow(a,n);
    cout<<"pow(a,n): "<<p.value<<endl;
    cout<<"No. of multiplications: "<<p.countOfOperations<<endl;
    cout<<"------------ Better Method -----------------\n";
    long long s = powBetter(a, n);
    cout<<"pow(a,n): "<<s<<endl;
}
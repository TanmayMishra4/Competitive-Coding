#include <bits/stdc++.h>
using namespace std;

template < typename T1, typename T2 > T2 product(T1 a, T2 b){
    return (T2)a*b;
}

int main(){
    cout << "Product of 2 and 3.5 is  " << product(2, 3.5)<<endl;
    cout << product(3, 2.4) << endl;
}
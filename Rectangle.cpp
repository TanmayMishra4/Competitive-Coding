#include <bits/stdc++.h>
using namespace std;

class rec{
    private:
        int l,b;
    public:
        rec(int a, int c){
            l = a;
            b = c;
        }
        int getWidth(){
            return b;
        }
        int getLength(){
            return l;
        }
        int area(){
            return l*b;
        }
};

int main(){
    rec obj[3] = {rec(3,6), rec(2,5), rec(5,5)};
    int lar = INT_MIN;
    rec larg(0, 0);
    int sz = sizeof(obj)/sizeof(rec);
    cout << "Displaying Areas of rectangles \n";
    for(int i=0;i<sz;i++){
        int ar = obj[i].area();
        cout << ar <<endl;
        if(ar > lar){
            lar = ar;
            larg = obj[i];
        }
    }
    cout << "Largest rectangle area is: " << lar << "\nlength is : "<< larg.getLength() << "\twidth is : " << larg.getWidth() << endl;

}
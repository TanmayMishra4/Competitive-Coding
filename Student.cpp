#include <bits/stdc++.h>
using namespace std;

template < class T > 
class Student {
    T marks1, marks2;
    public:
        Student(T marks1, T marks2){
            this->marks1 = marks1;
            this->marks2 = marks2;
        }
        T totalMarks(){
            return marks1+marks2;
        }
};

int main(){
    Student<int> s1 (45, 50);
    Student<float> s2 (47.5, 54.7);
    cout << s1.totalMarks() << endl;
    cout << s2.totalMarks() << endl;
}

#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start, end;
};

bool comparator(const Interval& a, const Interval& b){
    return (a.end < b.end);
}

vector<Interval> maxIntervals(vector<Interval> intervals){
    sort(intervals.begin(), intervals.end(), comparator);
    //insert the rest of the code
    //also solve the same problem by sorting through the start time
    vector<Interval> v;
    int prev = 0;
    for(Interval i : intervals){
        if(prev < i.start){
            v.push_back(i);
            prev = i.end;
        }
    }
    return v;   
}   

int main(){
    int n;
    cin>>n;
    cout<<"enter start and end\n";
    vector<Interval> arr;
    for(int x=0;x<n;x++){
        Interval i;
        cin>>i.start>>i.end;
        arr.push_back(i);
    }
    cout<<endl;
    for(Interval i : maxIntervals(arr)){
        cout<<"{ "<<i.start<<", "<<i.end<<" }, ";
    }
}

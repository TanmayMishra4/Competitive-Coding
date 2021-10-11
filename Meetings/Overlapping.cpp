#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start, end;
};

bool comparator(const pair<int, int>& a, const pair<int, int>& b){
    //insert the code
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}
int maxOverlap(vector<Interval> intervals){
    vector<pair<int,int>> arr;
    int i,n = intervals.size();
    int count=0, maxCount=INT_MIN;

    for(i=0;i<n;i++){
        arr.push_back(make_pair(intervals[i].start, 1));
        arr.push_back(make_pair(intervals[i].end, -1));
    }
    //insert the rest of the code
    sort(arr.begin(), arr.end(), comparator);
    cout<<endl<<"printing sorted vector\n";
    for(auto i : arr){
        cout<<"{ "<<i.first<<", "<<i.second<<" }, ";
    }

    for(pair<int, int> p : arr){
        if(p.second == 1)
            count++;
        if(p.second == -1)
            count--;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main(){
    int n;
    cin >> n;
    vector<Interval> arr;
    for(int i=0;i<n;i++){
        Interval a;
        cin>>a.start>>a.end;
        arr.push_back(a);
    }
    cout<<endl;
    cout<<maxOverlap(arr);
}
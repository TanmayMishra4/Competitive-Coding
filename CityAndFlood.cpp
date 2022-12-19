#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5+10;
int parent[sz];
int depth[sz];
multiset<int> sizes;

void make(int x){
    parent[x] = x;
    depth[x] = 1;
    sizes.insert(1);
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    sizes.erase(sizes.find(depth[a]));
    sizes.erase(sizes.find(depth[b]));
    // depth[a] += depth[b];
    sizes.insert(depth[a]+depth[b]);

}

void Union(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a != b){
        if(depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        merge(a, b);
        depth[a] += depth[b];
    }
}


int main(){
    int n, q;
    cin >> n >>q;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        Union(u,v);
        if(sizes.size() == 1)
            cout << 0 << endl;
        else{
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx-mn << endl;
        }
    }
}

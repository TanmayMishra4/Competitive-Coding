#include <bits/stdc++.h>

using namespace std;




// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

void solve(int tc) {
    // Add your solution here
    int n;
    cin >> n;
    vector<char> inres(n);
    vector<char> outres(n);
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        inres[i] = c;
    }
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        outres[i] = c;
    }
    cout << "Case #" << tc << ":\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool ok = true;
            if(i <= j){
                for(int k=i;k<j;k++){
                    if(outres[k] != 'Y' || inres[k+1] != 'Y'){
                        ok = false;
                    }
                }
            }
            else{
                for(int k=i;k>j;k--){
                    if(outres[k] != 'Y' || inres[k-1] != 'Y'){
                        ok = false;
                    }
                }
            }
            if(ok)
                cout << "Y";
            else
                cout << "N";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
 
        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);
    
        // Printing the Output to output.txt file
        freopen("output.txt", "w", stdout);
 
    #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}
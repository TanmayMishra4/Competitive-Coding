#include <bits/stdc++.h>
#define ll long long 
using namespace std;


// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

bool comparator(pair<int, int> one, pair<int, int> two){
	if(one.second != two.second)
		return one.second > two.second;
	return one.first > two.first;
}
void solve() {
    // Add your solution here
    int n , d;
	cin >> n >> d;
	vector<pair<int, int>> arr(n);
	for(int i=0;i<n;i++){
		int x, y;
		cin >> x >> y;
		arr[i] = make_pair(x,y);
	}
	sort(arr.begin(), arr.end(), comparator);
	int s = 0, e = 0;
	int csum = 0;
	int ans = 0;
	while(e < n){
		if(arr[e].first - arr[s].first < d){
			csum += arr[e].second;
			e++;
		}
		else{
			csum -= arr[s].second;
			s++;
		}
		ans = max(ans, csum);
	}
	cout << ans << "\n";
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
    // cin >> tc;
    // for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    // }
}
#include <bits/stdc++.h>
using namespace std;

void lcs(string s, string t)
{
	//Write your code here
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string ans = "";
    int len = dp[n][m];
    for(int i=0;i<len;i++)
        ans += '$';
	int i = n, j = m;
	int count = len-1;
	while(i > 0 && j > 0 && count >= 0){
		if(s[i-1] == t[j-1]){
			ans[count] = s[i-1];
			count--;
		}
		else{
			if(dp[i-1][j] == dp[i][j]){
				i--;
			}
			else{
				j--;
			}
		}
	}
    cout << "hello" << endl;
	cout << ans << "\n";
}

int main(){
    string a = "adebc";
    string b = "dcadb";
    cout << lcs <<endl;
}
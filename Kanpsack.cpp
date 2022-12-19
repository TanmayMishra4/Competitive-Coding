#include <bits/stdc++.h>
using namespace std;
long long func2(int n, int W, int* wt, int* val){
    long long dp[n+1][W+1];
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] +
                                dp[i - 1][w - wt[i - 1]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
int main(){
    int n, w;
    cin >> n >> w;
    int wt[n+1];
    int val[n+1];
    for(int i=0;i<n;i++)
        cin >> wt[i] >> val[i];
    
    cout << func2(n, w, wt, val);
}

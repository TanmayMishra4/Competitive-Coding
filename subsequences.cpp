#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 100005
ll n, k;
ll BIT[MAXN][12];
void update(ll i, ll j, ll vl) {
	for (; i <= n; i += i & -i)
		BIT[i][j] += vl;
}
ll query(ll i, ll j) {
	ll su = 0;
	for (; i; i -= i & -i)
		su += BIT[i][j];
	return su;

}
void fastscan(ll &x)
{
	bool neg = false;
	ll c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}

int main() {
	fastscan(n); fastscan(k);
	ll x;
	k++;
	for (ll i = 0; i < n; i++) {
		fastscan(x);
		update(x, 1, 1);
		for (ll j = 2; j <= k; j++)
			update(x, j, query(x - 1, j - 1));
	}
	cout << query(n, k) << "\n";
	return 0;
}

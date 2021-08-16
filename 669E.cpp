#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 100005
int N = 1000000000;
map<int, map<int, int>> bit;



void update(int time, int val, int c) {
	for (; time < N; time += (time & -time)) {
		bit[time][val] += c;
	}
}

int query(int time, int val) {
	int ans = 0;
	for (; time > 0; time -= (time & -time)) {
		ans += bit[time][val];
	}
	return ans;
}

void fastscan(int &x)
{
	bool neg = false;
	int c;
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
	int q;
	fastscan(q);
	int ty, t, val;
	for (int i = 0; i < q; ++i) {
		fastscan(ty);
		fastscan(t);
		fastscan(val);

		if (ty == 1) {
			update(t, val, 1);
		}
		else if (ty == 2) {
			update(t, val, -1);
		}
		else {
			cout << query(t, val) << "\n";
		}
	}
	return 0;
}














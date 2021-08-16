#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 1000002

vector<ll> bit(1000001, 0);
ll n;

ll query(ll idx) {
    ll ans = 0;
    for (; idx > 0; idx -= (idx & -idx)) {
        ans += bit[idx];
    }
    return ans;
}

void update(ll idx, ll val) {
    for (; idx < MAXN; idx += (idx & -idx)) {
        bit[idx] += val;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, c;
    char typ;
    ll l, r, p, k;

    cin >> n >> m >> c;
    for (ll i = 0; i < m; i++) {
        cin >> typ;
        if (typ == 'Q') {
            cin >> p;
            cout << (query(p) + c) << "\n";

        }
        else {
            cin >> l >> r >> k;
            update(l, k);
            update(r + 1, -k);

        }
    }
}
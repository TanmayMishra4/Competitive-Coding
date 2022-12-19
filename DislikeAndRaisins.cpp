#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int> > &A) {
	list<list<int>> arr;
	for (vector<int> i : A) {
		arr.push_back({i[0], 1});
		arr.push_back({i[1], 0});
	}
	arr.sort();
	int current = 0;
	int maxi = 1;

	for (auto ar : arr) {
		if (ar.back() == 1) {
			current++;
			maxi = max(maxi, current);
		}
		else {
			current = max(current - 1, 0);
		}
	}

	return maxi;
}

int main() {
	vector<vector<int>> a{{0, 30}, {5, 10}, {15, 20}};
	cout << "\n" << solve(a) << "\n";
	return 0;
}


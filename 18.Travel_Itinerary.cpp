//
// Created by Jay on 2022-02-25.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll TravelItinerary(int n, vector<int> distance) {
	reverse(distance.begin(), distance.end());

	vector<ll> DP(n + 1, 0);
	vector<ll> sums(n + 2, 0);
	DP[0] = sums[1] = 1;

	for (int i = 1; i <= n; i++) {
		int dist = distance[i - 1];
		ll sum = sums[i] - sums[i - dist];

		DP[i] = (DP[i] + sum) % MOD;
		sums[i + 1] = (sums[i] + DP[i]) % MOD;
	};

	return (DP[n] < 0) ? DP[n] + MOD : DP[n];
}

vector<int> Generate(int n) {
	vector<int> distance(n);
	ll val = 1;

	for (int i = 0; i < n; i++) {
		val = (val * 1103515245 + 12345) / 65536;
		val %= 32768;

		distance[i] = ((val % 10000) % (n - i)) + 1;
	}

	return distance;
}

int main() {
	int n;
	cin >> n;

	vector<int> distance(n);

	if (n == 1e7) distance = Generate(n);
	else {
		for (int i = 0; i < n; i++) {
			cin >> distance[i];
		}
		cout << endl;
	}

	ll result = TravelItinerary(n, distance);
	cout << result << endl;
}
//
// Created by Jay on 2022-02-25.
//

#include <bits/stdc++.h>
#define endl '\n'

#define DEBUG 1

#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

using namespace std;

void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets) {
	if (index == set.size()) {
		allSubsets[subset.size()].push_back(subset);
		return;
	}

	GetAllSubsets(set, subset, index + 1, allSubsets);

	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubsets);
}

bool SubsetSum_BruteForce(vector<int> set, int target) {
	vector<vector<vector<int>>> allSubsets(set.size() + 1);

	GetAllSubsets(set, {}, 0, allSubsets);

	for (int size = 0; size <= set.size(); size++) {
		PRINT("부분집합의 원소의 개수: " << size << endl);

		for (auto subset : allSubsets[size]) {
			PRINT("\t{");

			int sum = 0;
			for (auto number : subset) {
				sum += number;
				PRINT(number << " ");
			}

			PRINT("} = " << sum << endl);

			if (sum == target) return true;
		}
	}
	return false;
}

bool SubsetSum_Backtracking(vector<int> &set, int sum, int i) {
	if (sum == 0) return true;

	if (i == set.size() || set[i] > sum) return false;

	return SubsetSum_Backtracking(set, sum - set[i], i + 1) || SubsetSum_Backtracking(set, sum, i + 1);
}

vector<string> types = {"BRUTE FORCE", "BACKTRACKING", "MEMOIZATION", "TABULATION"};

void GetTime(clock_t& timer, string type) {
	// 현재 시간에서 timer를 빼서 경과 시간을 계산
	timer = clock() - timer;

	// 화면에 경과 시간 출력
	cout << type << " 방법 경과 시간: ";
	cout << fixed << setprecision(5) << (float)timer / CLOCKS_PER_SEC << endl;

	timer = clock(); // timer를 현재 시간으로 초기화
}

int main() {
	vector<int> set = {16, 1058, 22, 13, 46, 55, 3, 92, 47, 7,
					   98, 367, 807, 106, 333, 85, 577, 9, 3059};
	int target = 6076;
	int tests = 2;

	sort(set.begin(), set.end());

	for (int i = 0; i < tests; i++) {
		bool found = false;

		clock_t timer = clock();

		switch (i) {
			case 0:
				found = SubsetSum_BruteForce(set, target);
				break;
			case 1:
				found = SubsetSum_Backtracking(set, target, 0);
				break;
		}

		if (found)
			cout << "원소 합이 " << target << "인 부분집합이 있습니다." << endl;
		else
			cout << "원소 합이 " << target << "인 부분집합이 없습니다." << endl;

		GetTime(timer, types[i]);
		cout << endl;
	}
}
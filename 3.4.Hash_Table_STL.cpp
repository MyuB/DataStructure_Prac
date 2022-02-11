//
// Created by Jay on 2022-02-11.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void print(const unordered_set<int>& container) {
	for (const auto& elem : container) cout << elem << " ";
	cout << endl;
}

void print(const unordered_map<int, int>& container) {
	for (const auto& elem : container) cout << elem.first << " : " << elem.second << ", ";
	cout << endl;
}

void find(const unordered_set<int>& container, const int elem) {
	if (container.find(elem) == container.end()) cout << elem << " 검색 실패" << endl;
	else cout << elem << " 검색 성공" << endl;
}

void find(const unordered_map<int, int>& container, const int elem) {
	auto it = container.find(elem);
	if (it == container.end()) cout << elem << " 검색 실패" << endl;
	else cout << elem << " 검색 성공, 값 = " << it->second << endl;
}
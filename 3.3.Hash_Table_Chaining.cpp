//
// Created by Jay on 2022-02-11.
//

//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//using uint = unsigned int;
//
//class hash_map {
//	vector<list<int>> data;
//
//public:
//	hash_map(size_t n) {
//		this->data.resize(n);
//	}
//
//	void insert(uint value) {
//		int n = data.size();
//		data[value % n].push_back(value);
//		cout << value << "를 삽입했습니다" << endl;
//	}
//
//	bool find(uint value) {
//		int n = data.size();
//		auto& entries = data[value % n];
//		return std::find(entries.begin(), entries.end(), value) != entries.end();
//	}
//
//	void erase(uint value) {
//		int n = data.size();
//		auto& entries = data[value % n];
//		auto iter = std::find(entries.begin(), entries.end(), value);
//
//		if (iter != entries.end()) {
//			entries.erase(iter);
//			cout << value << "을 삭제했습니다" << endl;
//		}
//	}
//};

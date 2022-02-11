//
// Created by Jay on 2022-02-11.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using uint = unsigned int;

class hash_map {
	vector<int> data;

public:
	hash_map(size_t n) {
		data = vector<int>(n, -1);
	}

	void insert(uint value) {
		int n = data.size();
		data[value % n] = value;
		cout << value << "을 삽입했습니다. " << endl;
	}

	bool find(uint value) {
		int n = data.size();
		return (data[value % n] == value);
	}

	void erase(uint value ) {
		int n = data.size();
		if (data[value % n] == value) {
			data[value % n] = -1;
			cout << value << "을 삭제했습니다." << endl;
		}
	}
};

//int main() {
//	hash_map map(7);
//
//	auto print = [&](int value) {
//		if (map.find(value)) cout << value << "를 찾았습니다.";
//		else cout << value << "를 못찾았습니다. ";
//		cout << endl;
//	};
//
//	map.insert(2);
//	map.insert(25);
//	map.insert(10);
//	print(25);
//
//	map.insert(100);
//	print(100);
//	print(2);
//
//	map.erase(25);
//
//	return 0;
//}

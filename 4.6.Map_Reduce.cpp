//
// Created by Jay on 2022-02-14.
//

//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//void transform_test(vector<int> v) {
//	vector<int> Tr;
//	cout << "[맵 테스트] " << endl;
//	cout << "입력 배열, v: ";
//	for (auto i : v) cout << i << " ";
//	cout << endl;
//
//	//transform() 함수 사용
//	transform(v.begin(), v.end(), back_inserter(Tr), [](int x) { return pow(x, 2.0); });
//
//	cout << "transform(), Tr: ";
//	for (auto i : Tr) cout << i << " ";
//	cout << endl;
//
//	for_each(v.begin(), v.end(), [](int& x) { x = pow(x, 2.0); });
//	for (auto i : v) cout << i << " ";
//	cout << endl;
//}
//
//void reduce_test(vector<int> v) {
//	cout << endl << "[리듀스 테스트]" << endl;
//	cout << "입력 배열, v: ";
//	for (auto i : v) cout << i << " ";
//	cout < endl;
//
//	//accumulate() 함수 사용
//	auto ans = accumulate(v.begin(), v.end(), 0, [](int acc, int x) { return acc + x; });
//	cout << "accumulate(), ans: " << ans << endl;
//}
//
//int main() {
//	vector<int> v {1, 10, 4, 7, 3, 5, 6, 9, 8, 2};
//
//	transform_test(v);
//	reduce_test(v);
//}
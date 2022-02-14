////
//// Created by Jay on 2022-02-14.
////
//
//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//bool linear_search(int n, vector<int>& v) {
//	for (auto i : v)
//		if (i == n) return true;
//	return false;
//}
//
//bool binary_search(int n, vector<int>& S) {
//	auto first = S.begin();
//	auto last = S.end();
//
//	while (true) {
//		// 현재 검색 범위의 중간 원소를 mid_element에 저장
//		auto range_length = std::distance(first, last);
//		auto mid_element_index = floor(range_length / 2);
//		auto mid_element = *(first + mid_element_index);
//
//		// mid_element와 N 값을 비교
//		if (mid_element == n)
//			return true;
//		else if (mid_element > n)
//			advance(last, -mid_element_index);
//		else
//			advance(first, mid_element_index);
//
//		if (range_length == 1)
//			return false;
//	}
//}
//
//void run_small_search_test() {
//	auto n = 2;
//	vector<int> v {1, 3, 2, 4, 5, 7, 9, 8, 6};
//	sort(v.begin(), v.end());
//
//	if (linear_search(n, v))
//		cout << "linear search found elem" << endl;
//	else cout << "linear search could not found elem" << endl;
//
//	if (binary_search(n, v)) cout << "binary search found elem" << endl;
//	else cout << "binary search could not found elem" << endl;
//}
//
//void run_large_search_test(int size, int n) {
//	vector<int> v;
//	random_device rd;
//	mt19937 rand(rd());
//	uniform_int_distribution<mt19937::result_type> uniform_dist(1, size);
//
//	for (auto i = 0; i < size; i++) {
//		v.push_back(uniform_dist(rand));
//	}
//	sort(v.begin(), v.end());
//
//	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
//	bool search_result = binary_search(n, v);
//	chrono::steady_clock::time_point end = chrono::steady_clock::now();
//
//	auto diff = chrono::duration_cast<chrono::microseconds >(end - begin);
//	cout << "binary search durantion" << diff.count() << endl;
//
//	if (search_result) cout << "elem found" << endl;
//	else cout << "elem not found" << endl;
//}
//
//int main() {
//	run_small_search_test();
//
//	run_large_search_test(100000, 36543);
//	run_large_search_test(1000000, 36543);
//	run_large_search_test(10000000, 36543);
//	return 0;
//}
////
//// Created by Jay on 2022-02-14.
////
//
//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//template <typename T>
//auto partition(typename std::vector<T>::iterator begin,
//			   typename std::vector<T>::iterator end)
//{
//	auto pivot_val = *begin;
//	auto left_iter = begin + 1;
//	auto right_iter = end;
//
//	while (true)
//	{
//		while (*left_iter <= pivot_val && left_iter != right_iter)
//			left_iter++;
//		while (*right_iter >= pivot_val && left_iter != right_iter)
//			right_iter--;
//
//
//		if (left_iter == right_iter)
//			break;
//		else
//			std::iter_swap(left_iter, right_iter);
//	}
//
//	if (pivot_val > * right_iter)
//		std::iter_swap(begin, right_iter);
//
//	return right_iter;
//}
//
//template <typename T>
//void quick_sort(typename std::vector<T>::iterator begin,
//				typename std::vector<T>::iterator last)
//{
//	if (std::distance(begin, last) >= 1)
//	{
//		auto partition_iter = partition<T>(begin, last);
//
//		quick_sort<T>(begin, partition_iter - 1);
//		quick_sort<T>(partition_iter, last);
//	}
//}
//
//template<typename T>
//auto find_median(typename vector<T>::iterator begin, typename vector<T>::iterator last) {
//	quick_sort<T>(begin, last);
//
//	return begin + (distance(begin, last) / 2);
//}
//
//template<typename T>
//auto partition_using_given_pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end, typename vector<T>::iterator pivot) {
//	auto left_iter = begin;
//	auto right_iter = end;
//
//	while(true) {
//		while(*left_iter < *pivot && left_iter != right_iter)
//			left_iter++;
//		while(*right_iter >= *pivot && left_iter != right_iter)
//			right_iter--;
//
//		if (left_iter == right_iter) break;
//		else iter_swap(left_iter, right_iter);
//	}
//	if (*pivot > *right_iter)
//		iter_swap(pivot, right_iter);
//
//	return right_iter;
//}
//
//template<typename T>
//typename vector<T>::iterator linear_time_select(
//		typename vector<T>::iterator begin,
//		typename vector<T>::iterator last,
//		size_t i) {
//	auto size = distance(begin, last);
//	if (size > 0 && i < size) {
//		auto num_Vi = (size + 4) / 5;
//		size_t j = 0;
//
//		vector<T> M;
//		for (; j < size / 5; j++) {
//			auto b = begin + (j * 5);
//			auto l = begin + (j * 5) + 5;
//
//			M.push_back(*find_median<T>(b, l));
//		}
//
//		if (j * 5 < size) {
//			auto b = begin + (j * 5);
//			auto l = begin + (j * 5) + (size % 5);
//
//			M.push_back(*find_median<T>(b, l));
//		}
//
//		auto median_of_medians = (M.size() == 1) ? M.begin() :
//								 linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);
//
//		auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);
//		auto k = distance(begin, partition_iter) + 1;
//
//		if (i == k) return partition_iter;
//		else if (i < k) return linear_time_select<T>(begin, partition_iter - 1, i);
//		else if (i > k) return linear_time_select<T>(partition_iter, last, i - k);
//	}
//	else
//		return begin;
//}
//
//template<typename T>
//vector<T> merge(vector<T>& arr1, vector<T>& arr2) {
//	vector<T> merged;
//	auto iter1 = arr1.begin();
//	auto iter2 = arr2.begin();
//
//	while(iter1 != arr1.end() && iter2 != arr2.end()) {
//		if (*iter1 < *iter2) {
//			merged.template emplace_back(*iter1);
//			iter1++;
//		}
//		else {
//			merged.template emplace_back(*iter2);
//			iter2++;
//		}
//	}
//
//	if (iter1 != arr1.end()) {
//		for (; iter1 != arr1.end(); iter1++)
//			merged.template emplace_back(*iter1);
//	}
//	if (iter2 != arr2.end()) {
//		for (; iter2 != arr2.end(); iter2++)
//			merged.template emplace_back(*iter2);
//	}
//
//	return merged;
//}
//
//template<typename T>
//vector<T> merge_sort(vector<T> arr) {
//	if (arr.size() > 1) {
//		auto mid = size_t(arr.size() / 2);
//		auto left = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
//		auto right = merge_sort(vector<T>(arr.begin() + mid, arr.end()));
//
//		return merge<T>(left, right);
//	}
//	return arr;
//}
//
//template <typename T>
//void print_vector(vector<T> arr) {
//	for (auto i : arr)
//		cout << i << " ";
//	cout << endl;
//}
//
//void run_linear_select_test() {
//	vector<int> S1 {45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
//
//	cout << "입력 벡터:" << endl;
//	print_vector<int>(S1);
//
//	cout << "정렬된 벡터:" << endl;
//	print_vector<int>(merge_sort<int>(S1));
//
//	cout << "3번째 원소: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 3) << endl;
//	cout << "5번재 원소: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 5) << endl;
//	cout << "11번째 원소: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 11) << endl;
//}
//
//int main() {
//	run_linear_select_test();
//	return 0;
//}
//
// Created by Jay on 2022-02-15.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template<typename T>
auto compute_waiting_times(vector<T>& service_times) {
	vector<T> W(service_times.size());
	W[0] = 0;

	for (int i = 1; i < service_times.size(); i++) {
		W[i] = W[i - 1] + service_times[i - 1];
	}

	return W;
}

template<typename T>
void print_vector(vector<T>& v) {
	for (auto& i : v) {
		cout.width(2);
		cout << i << " ";
	}
	cout << endl;
}

template<typename T>
void compute_and_print_waiting_times(vector<T>& service_times) {
	auto waiting_times = compute_waiting_times<int>(service_times);
	cout << "- 처리 시간: ";
	print_vector(service_times);

	cout << "- 대기 시간: ";
	print_vector(waiting_times);

	auto ave_wating_times = accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
	cout << "- 평균 대기 시간: " << ave_wating_times << endl;
}

//int main(int argc, char* argv[]) {
//	vector<int> service_times {8,1, 2, 4, 9, 2, 3, 5};
//
//	cout << "[처음 일 처리 시간 & 대기 시간]" << endl;
//	compute_and_print_waiting_times(service_times);
//
//	sort(service_times.begin(), service_times.end());
//
//	cout << endl;
//	cout << "[정렬 후 일 처리 시간 & 대기 시간]" << endl;
//	compute_and_print_waiting_times(service_times);
//
//	return 0;
//}
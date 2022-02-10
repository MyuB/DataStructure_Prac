//
// Created by Jay on 2022-02-10.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Median {
public:
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<>> minHeap;

	void insert(int data) {
		if (maxHeap.size() == 0) {
			maxHeap.push(data);
			return;
		}
		if (maxHeap.size() == minHeap.size()) {
			if (data <= get()) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else maxHeap.push(data);
			return;
		}
		if (data < get()) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else minHeap.push(data);
	}

	double get() {
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		return maxHeap.top();
	}
};
//
//int main() {
//	Median med;
//
//	med.insert(1);
//	cout << "1 삽입 후 중앙값: " << med.get() << endl;
//
//	med.insert(5);
//	cout << "5 삽입 후 중앙값: " << med.get() << endl;
//
//	med.insert(2);
//	cout << "2 삽입 후 중앙값: " << med.get() << endl;
//
//	med.insert(10);
//	cout << "10 삽입 후 중앙값: " << med.get() << endl;
//
//	med.insert(40);
//	cout << "40 삽입 후 중앙값: " << med.get() << endl;
//
//  return 0;
//}
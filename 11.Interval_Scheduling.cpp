//
// Created by Jay on 2022-02-15.
//

//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//struct Task {
//	unsigned ID;
//	unsigned start_time;
//	unsigned end_time;
//};
//
//auto initialize_tasks(int num_tasks, int max_end_time) {
//	random_device rd;
//	mt19937 rand(rd());
//	uniform_int_distribution<mt19937::result_type> uniform_dist(1, max_end_time);
//
//	list<Task> tasks;
//
//	for (unsigned i = 0; i < num_tasks; i++) {
//		auto start_time = uniform_dist(rand);
//		auto end_time = uniform_dist(rand);
//
//		if (start_time == end_time) end_time++;
//		if (start_time > end_time) swap(start_time, end_time);
//
//		tasks.push_back({i + 1, start_time, end_time});
//	}
//
//	return tasks;
//}
//
//auto job_scheduling(list<Task> tasks) {
//	tasks.sort([](const auto& lhs, const auto& rhs) {
//		return lhs.end_time < rhs.end_time;
//	});
//
//	for (auto current_task = tasks.begin(); current_task != tasks.end(); current_task++) {
//		auto next_task = next(current_task, 1);
//		while(next_task != tasks.end() &&
//			next_task->start_time < current_task->end_time)
//			next_task = tasks.erase(next_task);
//	}
//
//	return tasks;
//}
//
//void print(list<Task>& tasks, int max_end_time) {
//	for (auto t : tasks) {
//		cout << "[" << t.ID << "] " << t.start_time << " -> " << t.end_time << "\t|";
//
//		int i = 0;
//		for (; i < t.start_time; i++) cout << " ";
//		for (; i < t.end_time; i++) cout << "*";
//		for (; i < max_end_time; i++) cout << " ";
//		cout << "|" << endl;
//	}
//}
//
//int main() {
//	int num_tasks = 10;
//	int max_end_time = 20;
//
//	auto tasks = initialize_tasks(num_tasks, max_end_time);
//	cout << "[전체 작업]" << endl;
//	print(tasks, max_end_time);
//
//	auto scheduled_tasks = job_scheduling(tasks);
//	cout << "\n[스케쥴 조정한 작업]" << endl;
//	print(scheduled_tasks, max_end_time);
//}
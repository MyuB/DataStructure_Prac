////
//// Created by Jay on 2022-02-23.
////
//
//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//const int UNKNOWN = INT_MAX;
//
//struct Edge {
//	int src;
//	int dst;
//	int weight;
//};
//
//vector<int> BellmanFord(vector<Edge> edges, int V, int start) {
//	vector<int> distance(V, UNKNOWN);
//	distance[start] = 0;
//
//	for (int i = 0; i < V - 1; i++) {
//		for (auto& e : edges) {
//			if (distance[e.src] == UNKNOWN) continue;
//
//			if (distance[e.dst] > distance[e.src] + e.weight) {
//				distance[e.dst] = distance[e.src] + e.weight;
//			}
//		}
//	}
//	return distance;
//}
//
//int main() {
//	int V = 5;              // 정점 개수
//	vector<Edge> edges;     // 에지 포인터의 벡터
//
//	vector<vector<int>> edge_map { // {시작 정점, 목표 정점, 가중치}
//			{0, 1, 3},
//			{1, 2, 5},
//			{1, 3, 10},
//			{3, 2, -7},
//			{2, 4, 2}
//	};
//
//	for (auto& e : edge_map)
//	{
//		edges.emplace_back(Edge {e[0], e[1], e[2]});
//	}
//
//	int start = 0;
//	vector<int> distance = BellmanFord(edges, V, start);
//
//	cout << "[" << start << "번 정점으로부터 최소 거리]" << endl;
//
//	for (int i = 0; i < distance.size(); i++)
//	{
//		if (distance[i] == UNKNOWN)
//			cout << i << "번 정점: 방문하지 않음!" << endl;
//		else
//			cout << i << "번 정점: " << distance[i] << endl;
//	}
//}
//
// Created by Jay on 2022-02-18.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template<typename T>
struct Edge {
	unsigned src;
	unsigned dst;
	T weight;
};

template<typename T>
class Graph {
private:
	unsigned V;
	vector<Edge<T>> edge_list;
public:
	Graph(unsigned N) {
		this->V = N;
	}

	auto vertices() const {
		return this->V;
	}

	auto& edges() const {
		return this->edge_list;
	}

	auto edges(unsigned v) const {
		vector<Edge<T>> edges_from_v;
		for (auto& e : edge_list) {
			if (e.src == v)
				edges_from_v.emplace_back(e);
		}
		return edges_from_v;
	}

	void add_edge(Edge<T>&& e) {
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V) edge_list.emplace_back(e);
		else cerr << "error: edge out of range" << endl;
	}

	template<typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);
};

template<typename U>
ostream& operator<< (ostream& os, const Graph<U>& G) {
	for (unsigned i = 1; i < G.vertices(); i++) {
		os << i << ":\t";

		auto edges = G.edges(i);
		for (auto& e : edges)
			os << "{" << e.dst << ": " << e.weight << "}, ";
		os << endl;
	}
	return os;
}

template<typename T>
auto create_reference_graph() {
	Graph<T> G(9);

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	for (auto& i : edge_map) {
		for (auto& j : i.second)
			G.add_edge(Edge<T>{i.first, j.first, j.second});
	}
	return G;
}

template<typename T>
auto BFS(const Graph<T>& G, unsigned start) {
	queue<unsigned> q;
	set<unsigned> visited;
	vector<unsigned> visit_order;
	q.push(start);

	while(!q.empty()) {
		auto current_vertex = q.front(); q.pop();

		if (visited.find(current_vertex) == visited.end()) {
			visited.insert(current_vertex);
			visit_order.push_back(current_vertex);

			for (auto& e: G.edges(current_vertex)) {
				if (visited.find(e.dst) == visited.end())
					q.push(e.dst);
			}
		}
	}
	return visit_order;
}

int main() {
	using T = unsigned;

	auto G = create_reference_graph<T>();
	cout << "[?????? ?????????]" << endl;
	cout << G << endl;

	cout << "[BFS ?????? ??????]" << endl;
	auto bfs_visit_order = BFS(G, 1);
	for (auto v : bfs_visit_order) cout << v << endl;
}
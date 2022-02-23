////
//// Created by Jay on 2022-02-23.
////
//
//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//template<typename T>
//struct Edge {
//	unsigned src;
//	unsigned dst;
//	T weight;
//};
//
//template<typename T>
//class Graph {
//private:
//	unsigned V;		// 정점 개수
//	vector<Edge<T>> edge_list;
//public:
//	Graph(unsigned  N) {
//		this->V = N;
//	}
//
//	auto vertices() const {
//		return this->V;
//	}
//
//	auto& edges() const {
//		return edge_list;
//	}
//
//	auto edges(unsigned v) const {
//		vector<Edge<T>> edges_from_v;
//		for (auto& e : edge_list) {
//			if (e.src == v)
//				edges_from_v.emplace_back(e);
//		}
//		return edges_from_v;
//	}
//
//	void add_edge(Edge<T>&& e) {
//		if (e.src >= 1 && e.src <= this->V && e.dst >= 1 && e.dst <= this->V)
//			edge_list.emplace_back(e);
//		else
//			cerr << "error: edge out of range" << endl;
//	}
//
//	template<typename U>
//	friend  ostream& operator<< (ostream& os, const Graph<U>& G);
//};
//
//template<typename U>
//ostream& operator<< (ostream& os, const Graph<U>& G) {
//	for (unsigned i = 1; i < G.vertices(); i++) {
//		os << i << ":\t";
//
//		auto edges = G.edges(i);
//		for (auto& e : edges)
//			os << "{" << e.dst << ": " << e.weight << "}, ";
//		os << endl;
//	}
//	return os;
//}
//
//template<typename T>
//auto read_graph_from_file() {
//	ifstream infile("USA-road-d.NY.gr.txt");
//	unsigned num_vertices, num_edges;
//
//	string line;
//
//	while(getline(infile, line)) {
//		if (line[0] == 'p') {
//			istringstream iss(line);
//			char p;
//			string sp;
//
//			iss >> p >> sp >> num_vertices >> num_edges;
//			cout << "정점 개수: " << num_vertices << endl;
//			cout << "에지 개수: " << num_edges << endl;
//			break;
//		}
//	}
//
//	Graph<T> G(num_vertices + 1);
//
//	while(getline(infile, line)) {
//		if (line[0] == 'a') {
//			istringstream iss(line);
//
//			char p;
//			unsigned source_vertex, dest_vertex;
//			T weight;
//			iss >> p >> source_vertex >> dest_vertex >> weight;
//
//			G.add_edge(Edge<T>{source_vertex, dest_vertex, weight});
//		}
//	}
//	infile.close();
//	return G;
//}
//
//template<typename T>
//struct Label {
//	unsigned ID;
//	T distance;
//
//	inline bool operator>(const Label<T> &l) const {
//		return this->distance > l.distance;
//	}
//};
//
//template<typename T>
//auto dijkstra_shortest_path(const Graph<T>& G, unsigned src, unsigned dst) {
//	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;
//
//	vector<T> distance(G.vertices(), numeric_limits<T>::max());
//	set<unsigned> visited;
//	vector<unsigned> parent(G.vertices());
//
//	heap.emplace(Label<T>{src, 0});
//	parent[src] = src;
//
//	while (!heap.empty()) {
//		auto current_vertex = heap.top();
//		heap.pop();
//
//		if (current_vertex.ID == dst) {
//			cout << current_vertex.ID << "번 정점(목적지)에 도착" << endl;
//			break;
//		}
//
//		if (visited.find(current_vertex.ID) == visited.end()) {
//			cout << current_vertex.ID << "번 정점에 안착" << endl;
//
//			for (auto &e: G.edges(current_vertex.ID)) {
//				auto neighbor = e.dst;
//				auto new_distance = current_vertex.distance + e.weight;
//
//				if (new_distance < distance[neighbor]) {
//					heap.emplace(Label<T>{neighbor, new_distance});
//
//					parent[neighbor] = current_vertex.ID;
//					distance[neighbor] = new_distance;
//				}
//			}
//			visited.insert(current_vertex.ID);
//		}
//	}
//	vector<unsigned> shortest_path;
//	auto current_vertex = dst;
//
//	while (current_vertex != src) {
//		shortest_path.push_back(current_vertex);
//		current_vertex = parent[current_vertex];
//	}
//	shortest_path.push_back(src);
//	reverse(shortest_path.begin(), shortest_path.end());
//
//	return shortest_path;
//}
//
//int main() {
//	using T = unsigned;
//
//	// 파일로부터 그래프 객체 생성
//	auto G = read_graph_from_file<T>();
//
//	unsigned src_id = 913;
//	unsigned dst_id = 542;
//	auto shortest_path = dijkstra_shortest_path<T>(G, src_id, dst_id);
//
//	cout << endl << "[" << src_id << " 정점에서 " << dst_id << " 정점까지의 최단 경로]" << endl;
//	for (auto v : shortest_path)
//		cout << v << " ";
//	cout << endl;
//}

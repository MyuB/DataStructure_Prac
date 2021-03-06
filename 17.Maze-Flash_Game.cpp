//
// Created by Jay on 2022-02-23.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Edge {
	int src;
	int dst;
	int weight;
};

const int UNKNOWN = INT_MAX;

bool ReadTestCase(const string& filename, int& V, vector<Edge>& edges) {
	ifstream infile(filename);

	if (!infile.is_open()) {
		cout << "cannot open testcase file" << endl;
		return false;
	}

	int E;
	infile >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		infile >> u >> v >> w;

		edges.push_back(Edge{u, v, w});
	}
	return true;
}

void FillStack(int node, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& st) {
	visited[node] = true;

	for (auto next : adj[node]) {
		if (!visited[next]) FillStack(next, visited, adj, st);
	}

	st.push(node);
}

vector<bool> isStuck;
vector<int> inComponent;
int componentIndex;

void CollectConnectedComponents(int node, vector<bool>& visited,
								vector<vector<int>>& adj, vector<int>& component) {
	visited[node] = true;
	component.push_back(node);

	inComponent[node] = componentIndex;

	for (auto next : adj[node]) {
		if (!visited[next]) CollectConnectedComponents(next, visited, adj, component);
		else if (inComponent[node] != inComponent[next])
			isStuck[inComponent[next]] = false;
	}
}

vector<vector<int>> Transpose(int V, vector<vector<int>> adj) {
	vector<vector<int>> transpose(V);
	for (int i = 0; i < V; i++) {
		for (auto next : adj[i]) transpose[next].push_back(i);
	}

	return transpose;
}

vector<vector<int>> Kosaraju(int V, vector<vector<int>> adj) {
	isStuck.resize(V, true);
	inComponent.resize(V, UNKNOWN);
	componentIndex = 0;

	vector<bool> visited(V, false);
	stack<int> st;

	for (int i = 0; i < V; i++) {
		if (!visited[i]) FillStack(i, visited, adj, st);
	}

	vector<vector<int>> transpose = Transpose(V, adj);
	fill(visited.begin(), visited.end(), false);
	vector<vector<int>> connectedComponents;

	while(!st.empty()) {
		int node = st.top(); st.pop();

		if (!visited[node]) {
			vector<int> component;

			CollectConnectedComponents(node, visited, transpose, component);
			connectedComponents.push_back(component);
			componentIndex++;
		}
	}
	return connectedComponents;
}

bool HasNegativeCycle(const vector<Edge>& edges, vector<int> distance) {
	for (auto& e : edges) {
		if (distance[e.src] == UNKNOWN) continue;
		if (distance[e.dst] > distance[e.src] + e.weight)
			return true;
	}
	return false;
}

int BellmanFord(vector<Edge>& edges, int V, int start) {
	vector<int> distance(V, UNKNOWN);
	distance[start] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (auto& e : edges) {
			if (distance[e.src] == UNKNOWN) continue;

			if (distance[e.dst] > distance[e.src] + e.weight)
				distance[e.dst] = distance[e.src] + e.weight;
		}
	}

	if (HasNegativeCycle(edges, distance)) return UNKNOWN;

	int result = UNKNOWN;

	for (int i = 0; i < V; i++) {
		if (i == start) continue;
		result = min(result, distance[i]);
	}
	return result;
}

int main() {
	int V;
	vector<Edge> edges;

	ReadTestCase("testcase7.txt", V, edges);

	vector<vector<int>> adj(V + 1);

	for (auto& e : edges) {
		adj[e.src].push_back(e.dst);
	}

	vector<int> results;

	for (int i = 0; i < V; i++) {
		if (adj[i].empty()) {
			results.push_back(UNKNOWN);
			continue;
		}

		int shortest = BellmanFord(edges, V, i);

		if (shortest == UNKNOWN) {
			cout << "???????????? ?????? ??????" << endl;
			return 0;
		}

		results.push_back(shortest);
	}

	for (int i = 0; i < V; i++) {
		if (results[i] == UNKNOWN)
			cout << i << ": ????????? ???" << endl;
		else
			cout << i << ": " << results[i] << endl;
	}

	auto components = Kosaraju(V, adj);

	for (int i = 0; i < components.size(); i++) {
		if (isStuck[i]) {
			for (auto node : components[i]) {
				cout << node << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
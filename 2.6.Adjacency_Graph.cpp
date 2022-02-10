//
// Created by Jay on 2022-02-10.
//

//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//enum class city : int {
//	MOSCOW,
//	LONDON,
//	SEOUL,
//	SEATTLE,
//	DUBAI,
//	SYDNEY
//};
//
//ostream& operator<<(ostream& os, const city c) {
//	switch (c) {
//		case city::LONDON:
//			os << "런던";
//			return os;
//		case city::MOSCOW:
//			os << "모스크바";
//			return os;
//		case city::SEOUL:
//			os << "서울";
//			return os;
//		case city::SEATTLE:
//			os << "시애틀";
//			return os;
//		case city::DUBAI:
//			os << "두바이";
//			return os;
//		case city::SYDNEY:
//			os << "시드니";
//			return os;
//		default:
//			return os;
//	}
//}
//
//class graph {
//public:
//	vector<vector<int>> data;
//
//	graph(int n) {
//		data.reserve(n);
//		vector<int> row(n);
//		fill(row.begin(), row.end(), -1);
//
//		for (int i = 0; i < n; i++) {
//			data.push_back(row);
//		}
//	}
//
//	void addEdge(const city c1, const city c2, int dis) {
//		cout << "엣지 추가: " << c1 << "-" << c2 << "=" << dis << endl;
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1][n2] = dis;
//		data[n2][n1] = dis;
//	}
//
//	void removeEdge(const city c1, const city c2) {
//		cout << "엣지 삭제: " << c1 << "-" << c2 << endl;
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1][n2] = -1;
//		data[n2][n1] = -1;
//	}
//};

//int main() {
//	graph g(6);
//	g.addEdge(city::LONDON, city::MOSCOW, 2500);
//	g.addEdge(city::LONDON, city::SEOUL, 9000);
//	g.addEdge(city::LONDON, city::DUBAI, 5500);
//	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
//	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
//	g.addEdge(city::SEOUL, city::DUBAI, 7000);
//	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
//	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
//	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
//	g.addEdge(city::DUBAI, city::SYDNEY, 1200);
//
//	g.addEdge(city::SEATTLE, city::LONDON, 8000);
//	g.removeEdge(city::SEATTLE, city::LONDON);
//
//	return 0;
//}
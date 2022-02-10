//
// Created by Jay on 2022-02-10.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class node {
public:
	string position;
	node* first;
	node* second;
};

class org_tree {
public:
	node* root;

	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node {pos, nullptr, nullptr};
		return tree;
	}

	static node* find(node* root, const string& value) {
		if (root == nullptr) return nullptr;
		if (root->position == value) return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != nullptr) return firstFound;

		return org_tree::find(root->second, value);
	}

	[[maybe_unused]]bool addSubordinate(const string& manager, const string& subordinate) const {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			cout << manager << "을 찾을 수 없습니다: " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) {
			cout << manager << " 아래에 " << subordinate << "을 추가할 수 없습니다" << endl;
			return false;
		}

		if (!managerNode->first) managerNode->first = new node{subordinate, nullptr, nullptr};
		else managerNode->second = new node{subordinate, nullptr, nullptr};

		cout << manager << " 아래에 " << subordinate << "을 추가했습니다." << endl;
		return true;
	}

	static void preOrder(node* start) {
		if (!start)
			return;

		cout << start->position << ", ";
		preOrder(start->first);
		preOrder(start->second);
	}

	static void inOrder(node* start) {
		if (!start) return;

		inOrder(start->first);
		cout << start->position << ", ";
		inOrder(start->second);
	}

	static void postOrder(node* start) {
		if (!start) return;

		inOrder(start->first);
		inOrder(start->second);
		cout << start->position << ", ";
	}

	static void levelOrder(node* start) {
		if (!start) return;

		queue<node*> q;
		q.push(start);

		while(!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto current = q.front(); q.pop();
				cout << current->position << ", ";
				if (current->first) q.push(current->first);
				if (current->second) q.push(current->second);
			}
			cout << endl;
		}
	}
};


//int main() {
//	auto tree= org_tree::create_org_structure("CEO");
//
//	tree.addSubordinate("CEO", "부사장");
//	tree.addSubordinate("부사장", "IT부장");
//	tree.addSubordinate("부사장", "마케팅부장");
//	tree.addSubordinate("IT부장", "보안팀장");
//	tree.addSubordinate("IT부장", "앱개발팀장");
//	tree.addSubordinate("마케팅부장", "물류팀장");
//	tree.addSubordinate("마케팅부장", "홍보팀장");
//	tree.addSubordinate("부사장", "재무부장");
//
//	org_tree::levelOrder(tree.root);
//
//	return 0;
//}

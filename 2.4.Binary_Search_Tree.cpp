//
// Created by Jay on 2022-02-10.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

class bst {
public:
	node* root = nullptr;

	node* find(int value) {
		return find_impl(root, value);
	}
private:
	node* find_impl(node* current, int value) {
		if (!current) {
			cout << endl;
			return nullptr;
		}

		if (current->data == value) {
			cout << value << "을 찾았습니다. " << endl;
			return current;
		}
		if (value < current->data) {
			cout << current->data << "에서 왼쪽으로 이동";
			return find_impl(current->left, value);
		}

		cout << current->data << "에서 오른쪽으로 이동";
		return find_impl(current->right, value);
	}
public:
	void insert(int value) {
		if (!root) root = new node{value, nullptr, nullptr};
		else insert_impl(root, value);
	}
private:
	void insert_impl(node* current, int value) {
		if (value < current->data) {
			if (!current->left) current->left = new node{value, nullptr, nullptr};
			else insert_impl(current->left, value);
		}
		else {
			if (!current->right) current->right = new node{value, nullptr, nullptr};
			else insert_impl(current->right, value);
		}
	}
public:
	void inorder() {
		inorder_impl(root);
	}
private:
	void inorder_impl(node* start) {
		if (!start) return;

		inorder_impl(start->left);
		cout << start->data << ", ";
		inorder_impl(start->right);
	}

public:
	node* successor(node* start) {
		auto current = start->right;
		while(current && current->left)
			current = current->left;
		return current;
	}

	void deleteValue(int value) {
		root = delete_impl(root, value);
	}
private:
	node* delete_impl(node* start, int value) {
		if (!start) return nullptr;
		if (value < start->data)
			start->left = delete_impl(start->left, value);
		else if (value < start->data)
			start->right = delete_impl(start->right, value);
		else {
			// 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
			if (!start->left) {
				auto tmp = start->right;
				delete start;
				return tmp;
			}
			// 오른쪽 자식 노드만 없는 경우
			if (!start->right) {
				auto tmp = start->left;
				delete start;
				return tmp;
			}
			//자식 노드가 둘 다 있는 경우
			auto succNode = successor(start);
			start->data = succNode->data;
			//오른쪽 서브 트리에서 후속 노드를 삭제 한다
			start->right = delete_impl(start->right, succNode->data);
		}
		return start;
	}
};
//
//int main()
//{
//	bst tree;
//	tree.insert(12);
//	tree.insert(10);
//	tree.insert(20);
//	tree.insert(8);
//	tree.insert(11);
//	tree.insert(15);
//	tree.insert(28);
//	tree.insert(4);
//	tree.insert(2);
//
//	cout << "중위 순회: ";
//	tree.inorder(); // BST의 모든 원소를 오름차순으로 출력합니다.
//	cout << endl;
//
//	tree.deleteValue(12);
//	cout << "12를 삭제한 후 중위 순회: ";
//	tree.inorder(); // BST의 모든 원소를 오름차순으로 출력합니다.
//	cout << endl;
//
//	if (tree.find(12))
//		std::cout << "원소 12는 트리에 있습니다." << endl;
//	else
//	std::cout << "원소 12는 트리에 없습니다." << endl;
//}

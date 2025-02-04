#include<iostream>
using namespace std;


class Binary_tree {
	int data;
	Binary_tree* left;
	Binary_tree* right;
public:
	Binary_tree() {
		this->data = 0;
		this->left = NULL;
		this->right = NULL;
	}
	Binary_tree(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	void insert(int data) {
		if (data < this->data) {
			if (this->left == NULL) {
				this->left = new Binary_tree(data);
			}
			else {
				this->left->insert(data);
			}
		}
		else {
			if (this->right == NULL) {
				this->right = new Binary_tree(data);
			}
			else {
				this->right->insert(data);
			}
		}
	}
	void display() {
		if (this->left != NULL) {
			this->left->display();
		}
		cout << this->data << " ";
		if (this->right != NULL) {
			this->right->display();
		}
	}
};
class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node() {
		this->value = 0;
		this->left = NULL;
		this->right = NULL;
	}
	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};
class binarytree {
	Node* root;
public:
	binarytree() {
		root = NULL;
	}
	void insert(int value) {
		if (root == NULL) {
			root = new Node(value);
		}
		else {
			Node* run = root;
			while (run != NULL) {
				if (run->value > value) {
					if (run->left == NULL) {
						run->left = new Node(value);
						return;
					}
					run = run->left;
				}
				else
				{
					if (run->right == NULL) {
						run->right = new Node(value);
						return;
					}
					run = run->right;
				}
			}
		}
	}
	void findNode(int value) {
		if (root == NULL) {
			cout << "Tree is empty" << endl;
		}
		else {
			Node* run = root;
			while (run != NULL) {
				if (run->value < value) {
					if (run->value == value)
						cout << "node " << run->value << " is found" << endl;
					run = run->right;
				}
				else {
					if (run->value == value)
						cout << "node " << run->value << " is found" << endl;
					run = run->left;
				}
			}
		}
	}
	void deleteNode(Node*&root,int value) {
		if (root != NULL) {
			Node* run = root;
			while (run != NULL) {
				
				if (run->value == value) {
					if (run->left == NULL) {
						Node* temp = run->right;
						delete run;
						root = temp;
					}
					else if (run->right == NULL) {
						Node* temp = run->left;
						delete run;
						root = temp;
					}
					else {
						Node* temp = run->right;
						while (temp->left != NULL) {
							temp = temp->left;
						}
						run->value = temp->value;
						deleteNode(run->right, temp->value);
					}
				}
				if (run->value < value)
					run = run->right;
				else
					run = run->left;
			}
		}
	}
};
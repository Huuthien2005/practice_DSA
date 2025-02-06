#include<iostream>
using namespace std;
#define M 7
class Node {
	int value;
	Node* next;
	Node() {
		this->value = 0;
		this->next = NULL;
	}
	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
	Node(int value, Node* next) {
		this->value = value;
		this->next = next;
	}
	void init(Node* head[]) {
		for (int i = 0; i < M; i++) {
			head[i] = NULL;
		}
	}
	static int hashFunction(int value) {
		return value % M;
	}
	void insert(Node* head[], int value) {
		int h = hashFunction(value);
		if (head[h] == NULL) {
			head[h] = new Node(value);
		}
		else {
			Node* run = head[h];
			while (run->next != NULL) {
				run = run->next;
			}
			run->next = new Node(value);
		}
	}
	void findNode(Node* head[], int value) {
		int h = hashFunction(value);
		if (head[h] == NULL) {
			cout << value << " is not exist" << endl;
		}
		else {
			Node* run = head[h];
			while (run != NULL) {
				if (run->value = value) {
					cout << value << " is found" << endl;
					return;
				}
				run = run->next;
			}
			cout << value << " is not exist" << endl;
		}
	}
	void display(Node* head[]) {
		for (int i = 0; i < M; i++) {
			cout << "======BUCKET " << i << " ==== = " << endl;
			if (head[i] != NULL) {
				Node* run = head[i];
				while (run != NULL) {
					cout << run->value << "\t";
					run = run->next;
				}
			}
		}
	}
	void displayEachHead(Node* head[],int i) {
		Node* run = head[i];
		cout << "======BUCKET " << i << " ==== = " << endl;
		if (head[i] != NULL) {
			while (run != NULL) {
				cout << run->value << "\t";
				run = run->next;
			}
		}
		else
		{
			cout << "======BUCKET " << i << " ===== EMPTY" << endl;
		}
	}
	void count_item_EachHead(Node* head[]) {
		for (int i = 0; i < M; i++) {
			cout << "======BUCKET "<<i<<" ==== = " << endl;
			int count = 0;
			if (head[i] != NULL) {
				Node* run = head[i];
				while (run != NULL) {
					count++;
					run = run->next;
				}
			}
		}
	}
	void delete_1Item(Node* head[], int value) {
		int h = hashFunction(value);
		if (head[h] != NULL) {
			Node* run = head[h];
			Node* prev = NULL;
			while (run != NULL && run->value != value) {
				prev = run;
				run = run->next;
			}
			if (prev == NULL) {
				head[h] = NULL;
				delete head[h];
			}
			else if (run != NULL) {
				prev->next = run->next;
				delete run;
			}
		}
	}
	void deleteAllHashTable(Node* head[]) {
		for (int i = 0; i < M; i++) {
			head[i] = NULL;
		}
		delete head;
	}
 };
 int main() {
 	
 }
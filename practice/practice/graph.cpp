#include<iostream>
using namespace std;

#define M 20

class SLLnode {
public:
	int value;
	SLLnode* next;

	SLLnode() {
		value = 0;
		next = NULL;
	}
	SLLnode(int value) {
		this->value = value;
		next = NULL;
	}
	SLLnode(int value, SLLnode* next) {
		this->value = value;
		this->next = next;
	}
};
class linklist {
	SLLnode* head;
public:
	linklist() {
		head = NULL;
	}
	bool isEmpty() {
		return head == NULL;
	}
	void insert(int value) {
		if (head != NULL) {
			head = new SLLnode(value);
		}
		else {
			SLLnode* run = head;
			while (run != NULL) {
				run = run->next;
			}
			run = new SLLnode(value);
		}
	}
	void deletenode(int value) {
		if (head == NULL) {
			cout << "list if empty" << endl;
		}
		else {
			SLLnode* run = head;
			SLLnode* prev = NULL;
			while (run != NULL&&run->value!=value) {
				prev = run;
				run = run->next;
			}
			if (prev == NULL) {
				head = run->next;
				run->next = NULL;
			}
			else if (run != NULL) {
				prev->next = run->next;
				run->next = NULL;
			}
			else {
				cout << "value is not found" << endl;
				return;
			}
			delete run;
		}
	}
	void display() {
		if (head != NULL) {
			SLLnode* run = head;
			while (run != NULL) {
				cout << run->value << "\t";
				run = run->next;
			}
		}
		else {
			cout << "list is empty" << endl;
		}
	}
};

class stack {
	SLLnode* head;
public:
	stack() {
		head =NULL;
	}
	bool isEmpty() {
		return head == NULL;
	}
	void push(int value) {
		if (head == NULL) {
			head = new SLLnode(value);
		}
		else {
			SLLnode* run = head;
			while (run != NULL) {
				run = run->next;
			}
			run = new SLLnode(value);
		}
	}
	int pop() {
		if (head == NULL) {
			cout << "stack is empty" << endl;
			return -1;
		}
		else {
			int temp = head->value;
			SLLnode* run = head;
			head = head->next;
			run->next = NULL;
			delete run;
			return temp;
		}
	}
	int peek() {
		if (head == NULL) {
			cout << "stack is empty" << endl;
		}
		else {
			return head->value;
		}
	}
};

class queue {
	SLLnode* head;
	SLLnode* tail;
public:
	queue() {
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() {
		return head == NULL;
	}
	void push(int value) {
		SLLnode* temp = new SLLnode(value);
		if (tail == NULL) {
			head = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
	}
	int pop() {
		int temp = head->value;
		SLLnode* run = head;
		head = head->next;
		run->next = NULL;
		delete run;
		return temp;
	}
	int peak() {
		if (head == NULL) {
			cout<<"queue is empty"<<endl;
		}
		else {
			return head->value;
		}
	}
};
class Adjmatrix {
	int** matrix;
	linklist* list;
	int m, n;
	bool* visited;
public:
	Adjmatrix(int m, int n) {
		this->m = m;
		this->n = n;
		list = NULL;
		matrix = new int*[m];
		visited = new bool[m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 0;
			}
			visited[i] = false;
		}
	}
	void input() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
	}
	void display() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout<<matrix[i][j]<<"\t";
			}
			cout << endl;
		}
	}
	void AdjList_Adjmatrix(SLLnode* head[]) {
		for (int i = 0; i < m; i++) {
			SLLnode* run = head[i];
			while (run != NULL) {
				matrix[i][run->value] =matrix[run->value][i] = 1;
			}
		}
	}
	void DFS_matrix(int value) {
		stack s;
		s.push(value);
		visited[value] = true;
		cout << value << "\t";
		int v = value;
		int i = -1;
		while (!s.isEmpty()) {
			if (v > n) {
				v = s.pop();
			}
			else {
				for (i = 0; i < n; i++) {
					if (matrix[v][i] == 1 && !visited[i]) {
						s.push(i);
						cout << i << "\t";
						visited[i] = true;
						v = i;
						break;
					}
				}
			}
		}
	}
	void BFS_matrix(int value) {
		queue q;
		q.push(value);
		visited[value] = true;
		cout << value << "\t";
		int v = value;
		int i = -1;
		while (!q.isEmpty()) {
			v = q.pop();
			cout << v << "\t";
			for (int i = 0; i < n; i++) {
				if (matrix[v][i] == 1 && !visited[i]) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}
};
class AdjList {
	SLLnode* head[M];
	bool* visited;
	int n, m;
	int** matrix;
	linklist* list;
public:
	AdjList(int m,int n) {
		this->m = m;
		this->n = n;
		visited = new bool[n];
		matrix = new int* [m];
		for (int i = 0; i < m; i++) {
			matrix[i] = new int[n];
			visited[i] = false;
			head[i] = NULL;
		}
	}
	void input_adjmatrix() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
	}
	void input() {
		int vertical;
		cout << "Enter vertical: ";
		cin >> vertical;
		for (int i = 0; i < m; i++) {
			cout << "Enter a number of AdjEdge:";
			int nEdge;
			cin >> nEdge;
			for (int j = 0; j < nEdge; j++) {
				cout << "Enter adjEdge: ";
				int adjEdge;
				cin >> adjEdge;
				list[vertical].insert( adjEdge);
			}
			
		}  
	}
	void Adjmatrix_adjList() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1) {
					list[i].insert(j);
					list[j].insert(i);
				}
			}
		}
	}
	void display_1item(SLLnode* run) {
		if(run!=NULL) {
			SLLnode* temp=run;
			while (temp != NULL) {
				cout << temp->value << "\t";
			}
		}
	}
	void display_All() {
		if (head == NULL) {
			cout << " graph is empty" << endl;
			return;
		}
		else {
			for (int i = 0; i < m; i++) {
				SLLnode* run = head[i];
				while (run != NULL) {
					display_1item(run);
				}
			}
		}

	}
	void DFS_recursive(int value) {
		visited[value] = true;
		cout << value << "\t";
		SLLnode* run = head[value];
		while (run != NULL) {
			if(!visited[run->value])
				DFS_recursive(run->value);
			run = run->next;
		}
	}
	void DFS_stack(int value) {
		stack s;
		s.push(value);
		visited[value] = true;
		cout << value << "\t";
		while (!s.isEmpty()) {
			int tmp = s.pop();
			SLLnode* run = head[tmp];
			while (run != NULL) {
				if (!visited[run->value]) {
					visited[run->value] = true;
					s.push(run->value);
					cout << run->value << "\t";
				}
			}
			run = run->next;
		}
	}
	void BFS_queue(int value) {
		queue q;
		visited[value] = true;
		q.push(value);
		cout << value << "\t";
		while (!q.isEmpty()) {
			int tmp = q.pop();
			cout << tmp << "\t";
			SLLnode* run = head[value];
			while (run != NULL) {
				if (!visited[run->value]) {
					visited[run->value] = true;
					q.push(run->value);
				}
				run = run->next;
			}
		}
	}
};
int main() {


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;



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
	void intsert(int value) {
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
int main() {


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

class SLLnode {
public:
	int value;
	SLLnode* next;
	SLLnode() {
		this->value = 0;
		this->next = NULL;
	}
	SLLnode(int value) {
		this->value = value;
		this->next = NULL;
	}
	SLLnode(int value,SLLnode*next) {
		this->value = value;
		this->next = next;
	}
};

class stack {
	SLLnode* top;
public:
	stack() {
		top = NULL;
	}
	void push(int value) {
		SLLnode* temp = new SLLnode(value);
		if (top == NULL) {
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
	}
	void pop() {
		if (top == NULL) {
			cout << "stack is NULL" << endl;
		}
		else {
			SLLnode* temp = top;
			top = top->next;
			temp->next = NULL;
			delete(temp);
		}
	}
	bool isEmpty() {
		return top == NULL;
	}
	void peak() {
		if (top == NULL) {
			cout << "stack is NULL" << endl;
		}
		else {
			cout << top->value << endl;
		}
	}
	void display() {
		SLLnode* temp = top;
		while (temp != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
class queue {
	SLLnode* front;
	SLLnode* rear;
public:
	queue() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int value) {
		SLLnode* newnode = new SLLnode(value);
		if (front == NULL) {
			front = newnode;
			rear = newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}
	}
	void dequeue() {
		if (front == NULL) {
			cout << "queue is empty" << endl;
		}
		else {
			cout << front->value << endl;
			SLLnode* temp = front;
			front = front->next;
			temp->next = NULL;
			delete(temp);
		}
	}
	bool isEmpty() {
		return front == NULL;
	}
	void peak() {
		if (front == NULL) {
			cout << "queue is empty" << endl;
		}
		else {
			cout << front->value << endl;
		}
	}
	void display() {
		SLLnode* temp = front;
		while (temp != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();
	s.pop();
	s.pop();
	s.display();
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();
	system("pause");
	return 0;
}
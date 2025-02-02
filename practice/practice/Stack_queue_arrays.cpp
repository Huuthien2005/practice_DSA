#include<iostream>
using namespace std;

class stack {
	int* arr;
	int opacity;
	int top;
public:
	stack(int size) {
		arr = new int[size];
		opacity = size;
		top = -1;
	}
	bool isEmpty() {
		return top == -1;
	}
	void peak() {
		if (top == -1) {
			cout << "stack is NULL" << endl;
		}
		else {
			cout << arr[top] << endl;
		}
	}
	void push(int value) {
		if (top == opacity - 1) {
			cout << "stack is full" << endl;
		}
		else {
			arr[++top] = value;
		}
	}
	void pop() {
		if (top == -1) {
			cout << "stack is NULL" << endl;
		}
		else {
			top--;
		}
	}
};
class queue {
	int front;
	int rear;
	int capacity;
	int* arr;
	public:
		queue(int size) {
			arr = new int[size];
			capacity = size;
			front = 0;
			rear = -1;
		}
		void enqueue(int value) {
			if (rear == capacity - 1) {
				cout << "queue is full" << endl;
			}
			else {
				arr[++rear] = value;
			}
		}
		void dequeue() {
			if (front > rear)
			{
				cout << "queue is empty" << endl;
			}
			else {
				front++;
			}
		}
		void frontElement() {
			if (front > rear) {
				cout << "queue is empty" << endl;
			}
			else {
				cout << arr[front] << endl;
			}
		}
		void rearElement() {
			if(front > rear) {
				cout << "queue is empty" << endl;
			}
			else {
				cout << arr[rear] << endl;
			}
		}
};
int main() {
	stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.peak();
	s.pop();
	s.peak();
	s.pop();
	s.peak();
	s.pop();
	s.peak();
	s.pop();
	s.peak();
	s.pop();
	s.peak();
	s.pop();
	queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.dequeue();
	q.frontElement();
	q.rearElement();
	cout << endl;
	q.dequeue();
	q.frontElement();
	q.rearElement();
	cout << endl;
	q.dequeue();
	q.frontElement();
	q.rearElement();
	system("pause");
	return 0;
}
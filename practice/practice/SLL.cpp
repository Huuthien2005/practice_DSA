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
	SLLnode(int value, SLLnode* next) {
		this->value = value;
		this->next = next;
	}
};

class headNode : public SLLnode {
private:
	SLLnode* head;
public:
	headNode() {
		head = NULL;
	}
	void add_first_Node(int value) {
		if (head == NULL)
			head = new SLLnode(value);
		else
		{
			SLLnode* run = head;
			while (run != NULL) {
				run = run->next;
			}
			run->next = new SLLnode(value);
		}
	}
	void add_middle_Node(int value, int key) {
		if (head == NULL) {
			head = new SLLnode(value);
		}
		else {
			SLLnode* run = head;
			SLLnode* prev = NULL;
			while (run != NULL && run->value != key) {
				prev = run;
				run = run->next;
			}
			if (prev == NULL) {
				prev = new SLLnode(value, run);
				run = prev;
			}
			else if (run == NULL)
				cout << "Not found" << endl;
			else {
				prev->next = new SLLnode(value, run);
			}
		}
	}
	void add_last_node(int value) {
		if (head == NULL)
			head = new SLLnode(value);
		else {
			SLLnode* run = head;
			while (run->next != NULL) {
				run = run->next;
			}
			run->next = new SLLnode(value);
		}
	}
	void delete_firstNode() {
		if (head != NULL) {
			SLLnode* temp = head;
			head = head->next;
			temp->next = NULL;
			delete(temp);
		}
	}
	void delete_lastNode() {
		if (head != NULL) {
			SLLnode* run = head;
			SLLnode* prev = NULL;
			while (run->next != NULL) {
				prev = run;
				run = run->next;
			}
			prev->next = NULL;
			delete(run);
		}
	}
	void delete_middleNode(int key) {
		if (head != NULL) {
			SLLnode* run = head;
			SLLnode* prev = NULL;
			while (run != NULL && run->value != key) {
				prev = run;
				run = run->next;
			}
			if (run->value == key) {
				prev->next = run->next;
				run->next = NULL;
				delete(run);
			}
			else
				cout << "Not found" << endl;
		}
	}
	void findNode(int key) {
		if (head == NULL)
			cout << "head is NULL" << endl;
		else
		{
			SLLnode* run = head;
			while (run != NULL) {
				if (run->value == key) {
					cout << key << " is existed" << endl;
					return;
				}
				run = run->next;
			}
			cout << "Not Found" << endl;
		}
	}
	/*void sortNode() {
		for (SLLnode* i = head; i->next != NULL; i = i->next) {
			for (SLLnode* j = i->next; j != NULL; j = j->next) {
				if (i->value > j->value) {
					SLLnode* temp = i;
					i = j;
					j = temp;
				}
			}
		}
	}*/
	void display() {
		for (SLLnode* i = head; i != NULL; i = i->next) {
			cout << i->value << "\t";
		}
		cout << endl;
	}
};
int main() {
	headNode h;
	h.add_first_Node(2);
	h.add_last_node(3);
	h.add_middle_Node(4,3);
	h.display();
	h.findNode(5);
	/*h.sortNode();*/
	h.display();
	system("pause");
	return 0;
}
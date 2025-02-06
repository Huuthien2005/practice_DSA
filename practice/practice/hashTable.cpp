#include<iostream>
using namespace std;
#define M 7
class Node {
public:
	int value;
	int next;
};
class hashtable {
	Node h[M];
	int r;
public:
	void init(hashtable& t) {
		for (int i = 0; i < M; i++) {
			t.h[i].value = -1;
			t.h[i].next = -1;
		}
		t.r = M - 1;
	}
	static int hashFunction(int value) {
		return value % M;
	}
	void insert(hashtable& t, int value) {
		if (t.r >= 0) {
			int h = hashFunction(value);
			if (t.h[h].value == -1) {
				t.h[h].value = value;
			}
			else {
				t.h[t.r].value = value;
				while (t.h[h].next != -1) {
					h = t.h[h].next;
				}
				t.h[h].next = t.r;
			}
			while (t.h[t.r].value >= 0 && t.r >= 0)
				t.r--;
		}
	}
	void find_item(hashtable t, int value) {
		int h = hashFunction(value);
		do {
			if (t.h[h].value == value) {
				cout << value << " is found" << endl;
				return;
			}
			else {
				h = t.h[h].next;
			}
		} while (h != -1);
		cout << value << " is not exist" << endl;
	}
	void deleteItem(hashtable& t, int value) {

	}
	void display(hashtable& t) {
		for (int i = 0; i < M; i++) {
			if (t.h[i].value != -1) {
				cout << t.h[i].value << "\t" << t.h[i].next << endl;
			}
		}
	}
};
int main() {
	hashtable t;
	t.init(t);
	t.insert(t, 12);
	t.insert(t, 1);
	t.insert(t, 8);
	t.insert(t, 15);
	t.insert(t, 14);
	t.insert(t, 21);
	t.insert(t, 35);
	t.insert(t, 63);
	t.display(t);
	t.find_item(t, 35);
	t.find_item(t, 63);

	system("pause");
	return 0;
}

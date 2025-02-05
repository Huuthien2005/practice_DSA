#include<iostream>
using namespace std;

class Node {
	int value;
	Node* left;
	Node* right;
public:
	//constructor
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
	Node(int value, Node* left, Node* right) {
		this->value = value;
		this->left = left;
		this->right = right;
	}
	//init head of tree
	void init(Node*& head) {
		head = NULL;
	}
	//insert node to tree
	void insert(Node*& head, int value) {
		if (head == NULL) {
			head = new Node(value);
		}
		else {
			Node* run = head;
			if (run->value < value)
				insert(run->right, value);
			else
				insert(run->left, value);
		}
	}
	//find node in tree
	void findNode(Node* head, int key) {
		if (head == NULL) {
			cout << "tree is empty" << endl;
		}
		else {
			Node* run = head;
			if (run->value == value) {
				cout << "value " << run->value << " is found" << endl;
			}
			else if (run->value < value)
				findNode(run->right, value);
			else
				findNode(run->left, value);
		}
	}
	//traverse tree
	void NLR(Node* head) {
		if (head != NULL) {
			cout<<head->value<<"\t";
			NLR(head->left);
			NLR(head->right);
			/*return;*/
		}
		//cout << "tree is empty" << endl;
	}
	void LNR(Node* head) {
		if (head != NULL) {
			LNR(head->left);
			cout<<head->value<<"\t";
			LNR(head->right);
			/*return;*/
		}
		/*cout<<"tree is empty"<<endl;*/
	}
	void LRN(Node* head) {
		if (head != NULL) {
			LRN(head->left);
			LRN(head->right);
			cout << head->value<<"\t";
			/*return;*/
		}
		/*cout<<"tree is empty"<<endl;*/
	}
	//count a number of node in tree
	void countNode(Node* head, int& count) {
		if (head != NULL) {
			countNode(head->left, count);
			countNode(head->right, count);
			count++;
		}
		cout << count << endl;
	}
	//calculate avaerage of tree
	void averageNode(Node*head,int & sum, int& count) {
		if (head != NULL) {
			averageNode(head->left, sum, count);
			averageNode(head->right, sum, count);
			sum += head->value;
			count++;
		}
		cout<<"average of tree is: "<<sum / count<<endl;
	}
	// check prime number
	static bool calculate_PrimeNumber(int n) {
		if(n<2)
			return false;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
	//find max value of tree
	void findMaxNode(Node* head, int& max) {
		if (head != NULL) {
			findMaxNode(head->left, max);
			findMaxNode(head->right, max);
			if (head->value > max)
				max = head->value;
		}
		cout<< "max value of tree is: " << max << endl;
	}
	//count a prime number in tree
	void count_primeNumber(Node* head, int& count) {
		if (head != NULL) {
			count_primeNumber(head->left, count);
			count_primeNumber(head->right, count);
			if (calculate_PrimeNumber(head->value))
				count++;
		}
		cout<<"number of prime number in tree is: "<<count<<endl;
	}
	//delete a node in tree
	void deleteNode(Node*& head, int value) {
		if (head == NULL) {
			cout << "tree is empty" << endl;
		}
		else {
			Node* run = head;
			if (run->value == value) {
				if (run->left == NULL && run->right == NULL) {
					delete run;
					run = NULL;
				}
				else if (run->left == NULL) {
					Node* temp = run;
					run = run->right;
					delete temp;
				}
				else if (run->right == NULL) {
					Node* temp = run;
					run = run->left;
					delete temp;
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
			else if (run->value < value)
				deleteNode(run->right, value);
			else
				deleteNode(run->left, value);
		}
	}
};
int main() {
	Node* root;
	root->init(root);
	root->insert(root, 10);
	root->insert(root, 5);
	root->insert(root, 15);
	root->insert(root, 3);
	root->insert(root, 7);
	root->insert(root, 12);
	root->insert(root, 17);
	root->insert(root, 1);
	root->insert(root, 4);
	root->insert(root, 6);
	root->insert(root, 8);
	root->insert(root, 11);
	root->insert(root, 13);
	root->insert(root, 16);
	root->insert(root, 18);
	root->insert(root, 2);
	root->insert(root, 9);
	root->findNode(root, 10);
	root->NLR(root);
	root->LNR(root);
	root->LRN(root);
	int count = 0;
	root->countNode(root, count);
	int sum = 0;
	root->averageNode(root, sum, count);
	int max = 0;
	root->findMaxNode(root, max);
	count = 0;
	root->count_primeNumber(root, count);
	root->deleteNode(root, 10);
	root->NLR(root);
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

class student {
	string id;
	string name;
	string sex;
	string address;
	string birthday;
	double score;
public:
	//constructor
	student() {
		this->id = "";
		this->name = "";
		this->sex = "";
		this->birthday = "";
		this->address = "";
		this->score = 0.0;
	}
	student(string id, string name, string sex,string address,string birthday,double score) {
		this->id = id;
		this->name = name;
		this->sex = sex;
		this->birthday = birthday;
		this->address = address;
		this->score = score;	
	}
	//dislay information of student
	void display() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Sex: " << sex << endl;
		cout << "Address: " << address << endl;
		cout << "Birthday: " << birthday << endl;
		cout << "Score: " << score << endl;
	}
	//setter and getter methods
	void setScore(double score) {
		this->score = score;
	}
	void setID(string Id) {
		this->id = Id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setSex(string sex) {
		this->sex = sex;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setBirthday(string birthday) {
		this->birthday = birthday;
	}
	string getID() {
		return id;
	}
	string getName() {
		return name;
	}
	string getSex() {
		return sex;
	}
	string getAddress() {
		return address;
	}
	string getBirthday() {
		return birthday;
	}
	double getScore() {
		return score;
	}
};

class SLLnode {
public:
	student stu;
	SLLnode* next;
	//constructor
	SLLnode(student stu) {
		this->stu = stu;
		next = NULL;
	}
	SLLnode(student stu,SLLnode* next) {
		this->stu = stu;
		this->next = next;
	}
	//setter and getter methods
	student getStudent() {
		return stu;
	}
	SLLnode* getNext() {
		return next;
	}
	void setNext(SLLnode* next) {
		this->next = next;
	}
};
class SLL {
	//innitalize list of student
	SLLnode* head;
public:
	//constructor
	SLL() {
		head = NULL;
	}
	//display all students in this list
	void display_all_student() {
		if (head == NULL)
		{
			cout << "List of Students is NULL" << endl;
			return;
		}
		else {
			SLLnode* run = head;
			while (run != NULL) {
				run->stu.display();
				run=run->next;
			}
		}
	}
	//delete student by id
	void delete_Student(string id) {
		if (head == NULL) {
			cout << "list of Students is empty" << endl;
		}
		else {
			SLLnode* run = head;
			SLLnode* prev = NULL;
			while (run != NULL) {
				if (run->stu.getID() == id) {
					if (prev == NULL) {
						head = run->next;
						run->next = NULL;
						delete run;
					}
					else {
						prev->next = run->next;
						run->next = NULL;
						delete run;
					}
					return;
				}
				prev = run;
				run = run->next;
			}
			cout << "Student with ID: " << id << " is not found" << endl;
		}
	}
	//count a number of student with score higher than 5
	int count_student_score_higher_than_5() {
		int count = 0;
		if (head == NULL) {
			cout << "List of Students is empty" << endl;
		}
		else {
			SLLnode* run = head;
			while (run != NULL) {
				if (run->stu.getScore() > 5) {
					count++;
				}
				run = run->next;
			}
		}
		return count;
	}
	//find student by id and display information of student
	void display_Student_byID(string id) {
		if (head == NULL) {
			cout << "list of students is empty" << endl;
		}
		else {
			SLLnode* run = head;
			while (run != NULL) {
				if (run->stu.getID() == id) {
					run->stu.display();
					run = run->next;
				}
			}
		}
	}
	//enter list of students
	void input_Student(int n ) {
		
		cout << "enter a number of Student: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			add_1student_tolist();
		}
	}
	//add a student to list
	void add_1student_tolist() {
		string id, name, sex, address, birthday;
		double score;
		cin.ignore();
		cout << "Enter ID: ";
		getline(cin, id);
		cout << "Enter Name: ";
		getline(cin, name);
		cout << "Enter sex: ";
		getline(cin, sex);
		cout << "Enter address: ";
		getline(cin, address);
		cout << "Enter birthday: ";
		getline(cin, birthday);
		cout << "Enter score: ";
		cin >> score;
		student stu(id, name, sex, address, birthday, score);
		addFirst(stu);
	}
	// add a student to the first of list method
	void addFirst(student stu) {
		head = new SLLnode(stu, head);
	}
	//change information of student in the list by id
	void fix_infor_student(string id) {
		if (head == NULL) {
			cout << "List of Students is empty" << endl;
		}
		else {
			SLLnode* run = head;
			while (run != NULL) {
				if (run->stu.getID() == id) {
					string id, name, sex, birthday, address;
					double score;
					cout << "Student with ID: " << id << " is found" << endl;
					cout<<"1. Fix ID"<<endl;
					cout<<"2. Fix Name"<<endl;
					cout << "3. Fix sex" << endl;
					cout << "4. Fix address" << endl;
					cout<<"5. Fix birthday"<<endl;
					cout<<"6. Fix score"<<endl;
					cout<<"7. Fix all information of student with ID: "<<id<<endl;
					cout<<"8. Exit"<<endl;
					cout << "Enter information you want to fix: " << endl;
					int key;
					cin >> key;
					switch (key) {
					case 1:
						cout<<"Enter new ID: ";
						getline(cin, id);
						run->stu.setID(id);
						break;
					case 2:
						cout << "Enter new Name: ";
						getline(cin, name);
						run->stu.setName(name);
						break;
					case 3:
						cout << "Enter new sex: ";
						getline(cin, sex);
						run->stu.setSex(sex);
						break;
					case 4:
						cout << "Enter new address: ";
						getline(cin, address);
						run->stu.setAddress(address);
						break;
					case 5:
						cout << "Enter new birthday: ";
						getline(cin, birthday);
						run->stu.setBirthday(birthday);
						break;
					case 6:
						cout << "Enter new score: ";
						cin >> score;
						run->stu.setScore(score);
						break;
					case 7:
						cout << "Enter new ID: ";
						getline(cin, id);
						run->stu.setID(id);
						cout << "Enter new Name: ";
						getline(cin, name);
						run->stu.setName(name);
						cout << "Enter new sex: ";
						getline(cin, sex);
						run->stu.setSex(sex);
						cout << "Enter new address: ";
						getline(cin, address);
						run->stu.setAddress(address);
						cout << "Enter new birthday: ";
						getline(cin, birthday);
						run->stu.setBirthday(birthday);
						cout << "Enter new score: ";
						cin >> score;
						run->stu.setScore(score);
						break;
					case 8:
						break;
					default:
						cout << "Invalid information" << endl;
						break;
					}
				}
				run = run->next;
			}
		}
	}
	// sort student by score with DESC
	void sort_student_byScore() {
		for(SLLnode* i=head;i!=NULL;i=i->next)
			for(SLLnode* j=i->next;j!=NULL;j=j->next)
				if(i->stu.getScore()>j->stu.getScore())
					swap(i->stu,j->stu);
	}
};
//main method and check function
int main() {
		SLL list;
	int n=4;
	list.input_Student(n);
	list.display_all_student();
	list.delete_Student("1");
	list.display_all_student();
	cout << "Number of student with score higher than 5: " << list.count_student_score_higher_than_5() << endl;
	list.display_Student_byID("2");
	list.fix_infor_student("3");
	list.display_all_student();
	list.sort_student_byScore();
	list.display_all_student();
	return 0;
}
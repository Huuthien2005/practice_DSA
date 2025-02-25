#include<iostream>
#include<map>
#include<set>
#include<Math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>

using namespace std;

void Exer1_map() {
	int n;
	cin >> n;
	
	map<int, bool> mp;
	while (n--) {
		int length;
		cin >> length;
		for (int i = 0; i < length; i++) {
			int x;
			cin >> x;
			mp[x] = true;
		}
		cout << mp.size() << endl;
	}
}
void Exer1_set() {
	int n;
	cin >> n;

	set<int> se;
	while (n--) {
		int length;
		cin >> length;
		for (int i = 0; i < length; i++) {
			int x;
			cin >> x;
			se.insert(x);
		}
		cout <<se.size() << endl;
	}
}
void Exer1_arr() {
	int n;
	cin >> n;
	int a[10001];
	
	while (n--) {
		int length;
		cin >> length;
		int ans = 1;
		for (int i = 0; i < length; i++) {
			int x;
			cin >> x;
			a[i] = x;
		}
		sort(a, a + length);
		for (int i = 1; i < length; i++) {
			if (a[i] != a[i - 1])
				ans++;
		}
		cout << ans << endl;
	}
}

void Exer2_map() {
	int n;
	cin >> n;
	map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >>x;
		mp[x] = true;
	}
	int t;
	cin >> t;
	while (t--) {
		int element;
		cin >> element;
		if (mp.find(element) != mp.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
void Exer2_set() {
	int n;
	cin >> n;
	set<int> se;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		se.insert(x);
	}
	int t;
	cin >> t;
	while (t--) {
		int element;
		cin >> element;
		if (se.find(element) != se.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
void Exer3_map() {
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	int* b = new int[m];
	map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		mp[b[i]] = true;
	}
	int tmp=-1;
	for (int i = 0; i < n; i++) {
		if (mp.find(a[i]) == mp.end())
		{
			tmp = a[i];
		}
	}
	if (tmp!=-1)
		cout << tmp << endl;
	else
		cout << "NOT FOUND" << endl;
}

void Exer3_set() {
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	int* b = new int[m];
	set<int> se;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		se.insert(b[i]);
	}
	int tmp = -1;
	for (int i = 0; i < n; i++) {
		if (se.find(a[i]) == se.end())
		{
			tmp = a[i];
		}
	}
	if (tmp != -1)
		cout << tmp << endl;
	else
		cout << "NOT FOUND" << endl;
}
void Exer4() {
	int n;
	cin >> n;
	map<int, int>mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x]++;
	}
	int freq = INT_MIN;
	int key;
	for (auto it : mp) {
		if (it.second > freq)
		{
			key = it.first;
			freq = it.second;
		}
	}
	cout << key << "\t" << freq << endl;
}
void Exer5_map() {
	string s;
	getline(cin, s);
	//cin.ignore();
	map<char, int> mp;
	for (int i = 0; i < s.length(); i++) {
		mp[s[i]]++;
	}
	int freq = INT_MIN;
	char c;
	for (auto it : mp) {
		if (freq < it.second) {
			freq = it.second;
			c = it.first;
		}
	}
	cout << c << endl;
}
void Exer6() {
	int testcase;
	cin >> testcase;
	cin.ignore();
	while (testcase--) {
		string s;
		set<char>se;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			se.insert(tolower(s[i]));
		}
		if (se.size() == 26)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
void Exer7_set() {
	int testcase;
	cin >> testcase;
	cin.ignore();
	while (testcase--) {
		string s;
		getline(cin, s);
		set<string> se;
		stringstream ss(s);
		string word;
		while (ss >> word) {
			se.insert(word);
		}
		cout << se.size() << endl;
	}
}
void Exer7_map() {
	int testcase;
	cin >> testcase;
	cin.ignore();
	while (testcase--) {
		string s;
		getline(cin, s);
		map<string, bool>mp;
		stringstream ss(s);
		string word;
		while (ss >> word) {
			mp[word] = true;
		}
		cout << mp.size() << endl;
	}
}
void Exer8() {
	int testcase;
	cin >> testcase;
	cin.ignore();
	while (testcase--) {
		string s;
		getline(cin, s);
		map<string, int> mp;
		stringstream ss(s);
		string word;
		while (ss >> word) {
			if (mp[word] == 1) {
				cout << word << endl;
				return;
			}
			mp[word]++;
		}
	}
}
void Exer9_map() {
	int testcase;
	cin >> testcase;
	//cin.ignore();
	while (testcase--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string word;
		map<string, int>mp;
		while (ss >> word) {
			if (mp.find(word) != mp.end()) {
				cout << word << "\t" << endl;
				return;
			}
			mp[word]++;
		}
	}
}
void Exer9_set() {
	int testcase;
	cin >> testcase;
	//cin.ignore();
	while (testcase--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string word;
		set<string> se;
		while (ss >> word) {
			if (se.find(word) != se.end()) {
				cout << word << "\t" << endl;
				return;
			}
			se.insert(word);
		}
	}
}
void Exer10() {
	int num_user;
	cin >> num_user;
	map<string, int>mp;	
	while (num_user--) {
		string word;
		getline(cin,word);
		if (mp.find(word) == mp.end())
			cout << word << endl;
		else
			cout << word << mp[word] << endl;
		mp[word]++;
	}
}

int main() {
	//Exer1_map();
	//Exer1_set();
	//Exer1_arr();
	//Exer2_map();
	//Exer2_set();
	//Exer3_map();
	//Exer3_set();
	//Exer4();
	//Exer5_map();
	//Exer6();
	//Exer7_set();
	//Exer7_map();
	//Exer8();
	Exer9_map();
	//Exer10();

	system("pause");
	return 0;
}
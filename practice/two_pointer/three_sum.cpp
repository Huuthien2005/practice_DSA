#include<iostream>
using namespace std;

void input(int a[],int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
//find three elements in the array that sum to the target, and print the index of the elements
void three_sum(int a[], int n, int target) {
	int i=0, j = i+1, k = n - 1;
	int sum = 0;
	while (i < n - 2) {
		sum= a[i] + a[j] + a[k];
		if (sum == target) {
			cout << i+1 << "\t" << j+1 << "\t" << k+1 << endl;
			return;
		}
		else {
			if (j+1 == k) {
				i++;
				j = i + 1;
			}
			++j;
		}
	}
}
//find four elements in the array that sum to the target, and print the index of the elements
void fourSum(int a[], int n, int target) {
	int i = 0, j = i + 1, l = j + 1, r = n - 1;
	int sum = 0;
	while (i < n - 3) {
		sum = a[i] + a[j] + a[l] + a[r];
		if (sum == target) {
			cout << i + 1 << "\t" << j + 1 << "\t" << l + 1 << "\t" << r + 1<<endl;
			return;
		}
		else {
			if (i + 2 == r) {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
			if (j + 1 == r) {
				i++;
				j = i + 1;
				l = j + 1;
			}
			if (l == r) {
				j++;
				l = j + 1;
			}
			j++;
		}
	}
}
//find the nearest smaller value of each element in the array, and print the left nearest index of the value
void nearestSmallValues(int a[], int n) {
	int i = 0;

	while (i < n) {
		int j = i - 1; // Start searching left

		while (j >= 0) { // Move leftward
			if (a[j] < a[i]) {
				cout << j + 1 << " "; // Print 1-based index
				break;
			}
			j--;
		}

		if (j < 0) {
			cout << "0 "; // No smaller value found
		}

		i++; // Move to the next element
	}

	cout << endl;
}
//find the number of subarrays that sum to the target
void subArraySumI(int a[], int n, int target) {
	int l=0, r = 0;
	int cnt = 0;
	int sum = 0;
	while(r<n) {
		sum += a[r++];
		while (sum > target&&l<r) {
			sum -= a[l++];
		}
		if (sum == target)
			++cnt;
	}
	cout << cnt<<endl;
}
//find the number of subarrays that sum to the target
void subArraySumII(int a[], int n, int target) {
	int l = 0;
	int cnt = 0;
	while (l < n) {
		int r = l;
		int sum = 0;
		while (r < n) {
			sum += a[r];
			if (sum == target) {
				++cnt;
			}
			r++;
		}
		l++;
	}
	cout << cnt<<endl;
}
//find the number of subarrays that have at most k distinct values9
void subArrayDistinctValues(int a[], int n, int target) {
	int l = 0, r = 0, distinct = 0;
	const int max = 100;
	int freq[max] = { 0 };
	long long cnt = 0;
	while (r < n) {
		if (freq[a[r]] == 0)
			++distinct;
		++freq[a[r]];
		while (distinct > target) {
			freq[a[l]]--;
			if (freq[a[l]] == 0)
				--distinct;
			l++;
		}
		cnt += r - l + 1;
		r++;
	}
	cout << cnt << endl;
}
int main() {
	int a[100];
	int n;
	int target;
	cin >> n;
	cin >> target;
	input(a, n);
	/*three_sum(a, n, target);
	fourSum(a, n, target);*/
	//nearestSmallValues(a, n);
	//subArraySumI(a, n, target);
	//subArraySumII(a, n, target);
	subArrayDistinctValues(a, n, target);
	
	
	system("pause");
	return 0;
}
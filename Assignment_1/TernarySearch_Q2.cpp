#include<iostream>
using namespace std;
int TernarySearchRecursive(int A[], int low, int high, int v);
int main()
{
	int n, A[1000], v;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	cout << " Enter the array values in sorted order" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	bool ans;
	do
	{
		cout << "Enter value to be searched" << endl;
		cin >> v;
		int loc = TernarySearchRecursive(A, 0, n - 1, v);
		if (loc == -1)
			cout << " ELement not present in the array" << endl;
		else
			cout << "Found at " << loc << " location in the array" << endl;
		cout << "Is there any other value to be searched[Enter 0(no) or 1(yes)]?" << endl;
		cin >> ans;
	} while (ans == true);
	return 0;
}
int TernarySearchRecursive(int A[], int low, int high, int v)
{
	if (low > high)
		return -1;
	int mid1 = low + (high - low) / 3;
	int mid2 = high - (high - low) / 3; 
	if (A[mid1] == v) return mid1;
	if (A[mid2] == v) return mid2;
	if (A[mid1] > v)
		return TernarySearchRecursive(A, low, mid1 - 1, v);
	else
	if (A[mid1] < v && A[mid2] > v)
		return TernarySearchRecursive(A, mid1 + 1, mid2 - 1, v);
	else
		return TernarySearchRecursive(A, mid2 + 1, high, v);
}

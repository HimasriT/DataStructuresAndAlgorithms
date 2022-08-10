#include<iostream>
using namespace std;
void Minheapify(int arr[], int i, int n)
{
	int lch = (2 * i);
	int rch = (2 * i + 1);
	int small = i;
	if (lch < n && arr[lch] < arr[i])
		small = lch;
	if (rch < n && arr[rch] < arr[small])
		small = rch;
	swap(arr[i], arr[small]);
	// if the root value is changed then again heapify with the changed value
	if (i != small)
	{
		Minheapify(arr, small, n);
	}
	return;
}
void HeapSort(int arr[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[1], arr[i]);
		Minheapify(arr, 1, i);
	}
	cout << "\nThe array after sorting is:" << endl;
	for (int i = 1; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}
void ConverttoHeap(int arr[], int len)
{
	for (int i = len / 2; i > 0; i--)
	{
		Minheapify(arr, i, len);
	}
}
int main()
{
	int arr[] = { 19,40,60,20,80,50,10,30,15,5,35,25,45,55,70,90,32,33,48,46 };
	int len = sizeof(arr) / sizeof(int);
	cout << "size of the array is" << arr[0] << endl;
	//Printing the array before converting to heap
	cout << "\nPrinting the array before converting to heap\n";
	for (int i = 1; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//Converting the arr into Minheap
	ConverttoHeap(arr, len);
	// Printing the array or heap after the Min heapify operation
	cout << "\n Printing the array after converting to heap\n";
	for (int i = 1; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	// Implementing the heapSort
	HeapSort(arr, len);
	return 0;
}
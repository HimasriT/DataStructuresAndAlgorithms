#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
// Adding a node in the linked list
void AddNode(Node** head, int a)
{
	Node* nextNode = new Node();
	Node* curr = *head;
	nextNode->data = a;
	nextNode->next = NULL;
	if (curr == NULL)
	{
		*head = nextNode;
		return;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = nextNode;
	return;
}
//Creating LinkedList
void create(Node** head)
{
	int n, a;
	cout << "Enter the number of nodes to be inserted" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the value of the node" << endl;
		cin >> a;
		AddNode(head, a);
	}
	return;
}
//Printing the LinkedList
void print(Node* head)
{
	Node* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
	return;
}
//BubbleSort with swapping values
void BubbleSort(Node** head)
{
	//Node* curr = *head;
	Node* curr, *curr2;
	bool swapped = true;
	while (swapped == true)
	{
		swapped = false;
		curr = *head;
		curr2 = curr->next;
		while (curr2 != NULL)
		{
			if (curr->data > curr2->data)
			{
				int tmp = curr->data;
				curr->data = curr2->data;
				curr2->data = tmp;
				swapped = true;
			}
			curr = curr2;
			curr2 = curr2->next;
		}
	}
	return;
}
//BubbleSort by swapping Nodes
void BubbleSortSwapNodes(Node** head)
{
	Node* curr, * curr2, * prev;
	bool swapped = true;
	while (swapped == true)
	{
		swapped = false;
		prev = NULL;
		curr = *head;
		curr2 = curr->next;
		while (curr2 != NULL)
		{
			if (curr->data > curr2->data)
			{
				if (prev == NULL)
				{
					*head = curr2;
				}
				else
				{
					prev->next = curr2;
				}
				Node* n2 = curr2->next;
				curr2->next = curr;
				curr->next = n2;
				swapped = true;
			}
			prev = curr;
			curr = curr2;
			curr2 = curr2->next;
		}
	}
	return;
}
int main()
{
	Node* head = NULL;
	create(&head);
	cout << "Original unsorted List is " << endl;
	print(head);
	//BubbleSortSwappingNodes
	BubbleSortSwapNodes(&head);
	cout << "Sorted List after swapping nodes is " << endl;
	print(head);
	return 0;
}

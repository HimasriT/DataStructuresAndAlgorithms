#include<iostream>
#include<queue>
using namespace std;
struct tree* pred = NULL;
struct tree
{
	int data;
	struct tree* parent;
	struct tree* lchild;
	struct tree* rchild;
};
struct tree* search(struct tree* root, int val)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == val)
		return root;
	if (root->data < val)
		return search(root->rchild, val);
	return search(root->lchild, val);
}
struct tree* insert(struct tree* root, int val,struct tree* par)
{
	if (root == NULL)
	{
		root = new struct tree();
		root->data = val;
		root->lchild = NULL;
		root->rchild = NULL;
		root->parent = par;
		return root;
	}
	if (val > root->data)
	{
		root->rchild = insert(root->rchild, val,root);
	}
	else
	{
		root->lchild = insert(root->lchild, val,root);
	}
	return root;
}
void inorder(struct tree* root)
{
	if (root == NULL)
		return;
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
	return;
}
void levelorder(struct tree* root)
{
	if (root == NULL)
		return;
	queue<struct tree*> que;
	que.push(root);
	while (!que.empty())
	{
		int cnt = que.size();
		while (cnt > 0)
		{
			struct tree* tmp = que.front();
			que.pop();
			cout << tmp->data<<" ";
			if (tmp->lchild != NULL)
				que.push(tmp->lchild);
			if (tmp->rchild != NULL)
				que.push(tmp->rchild);
			cnt--;
		}
		cout << endl;
	}
}
// Finding predecessor of a given node
struct tree* predecessor(struct tree* root, int val)
{
	if (root == NULL)
		return NULL;
	predecessor(root->lchild, val);
	if (root->data == val)
		return pred;
	pred = root;
	predecessor(root->rchild, val);
	return pred;
}
// Function to delete node of a tree
void deleteNode(struct tree* root, int val)
{
	struct tree* req_node = search(root,val);
	// for the leaf nodes
	if (req_node->lchild == NULL && req_node->rchild == NULL)
	{
	//	cout << "enter the leaf node case" << endl;
	//	cout << "the current node value is" << req_node->data << endl;
	//	cout << "parent is" << req_node->parent->data << endl;
		if (req_node->parent->lchild == req_node)
			req_node->parent->lchild = NULL;
		else
			req_node->parent->rchild = NULL;
	//	delete(req_node);
		return;
	}
	// for non-leaf nodes
	else
	if(req_node->lchild == NULL)
	{
		swap(req_node->data, req_node->rchild->data);
		req_node->rchild = NULL;
	}
	else
	if (req_node->rchild == NULL)
	{
		swap(req_node->data, req_node->lchild->data);
		req_node->lchild = NULL;
	}
	else
	{
		//choosing predecessor here
		struct tree* prede = predecessor(req_node, req_node->data);
		cout << "predecessor is" << prede->data;
		swap(req_node->data,prede->data);
		deleteNode(prede, prede->data);
	}
	return;
}
int main()
{
	struct tree* root = NULL;
	int arr[] = { 40,60,20,80,50,10,30,15,5,35,25,45,55,70,90,32,33,48,46 };
	int len = sizeof(arr)/sizeof(int);
	//Inserting into  a BST
	root = insert(root, arr[0],NULL);
	for (int i = 1; i < len; i++)
	{
		insert(root, arr[i], root);
	}
	cout << "\nThe inorder traversal of the given tree is" << endl;
	inorder(root);
	cout << "\nlevel order is" << endl;
	levelorder(root);
	int d;
	bool yes;
	do
	{
		cout << "\nEnter the value to be deleted" << endl;
		cin >> d;
		deleteNode(root, d);
		cout << "\nAfter delete, level order is:" << endl;
		levelorder(root);
		cout << "\nAfter deleting the " << d << " value, inorder is" << endl;
		inorder(root);
		cout << "\n Do you have more values to delete(enter 0 for no or 1 for yes)" << endl;
		cin >> yes;
	} while (yes == true);
	return 0;
}
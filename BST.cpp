#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class Node {
public:
	T val;
	Node<T>* BstRight;
	Node<T>* BstLeft;
	Node(T value)
	{
		this->val = value;
		BstLeft = nullptr;
		BstRight = nullptr;
	}
};
template <typename T>
class BST {
public:
	Node<T>* root;
	BST(){}
	BST(T val)
	{
		this->root = new Node<T>(val);
	}
	void insert(T val)
	{
		root = insertByRes(root, val);
	}
	Node<T>* insertByRes(Node<T>* node,T val)
	{
		if (node == nullptr)
		{
			return new Node<T>(val);
		}
		if (node->val > val)
		{
			node->BstLeft = insertByRes(node->BstLeft, val);
		}
		else if (root->val <= val)
		{
			node->BstRight = insertByRes(node->BstRight, val);
		}
		return node;
	}
	bool Search(T val)
	{
		Node<T>* cur = root;
		return SearchByRes(cur, val);
	}
	bool SearchByRes(Node<T>* node, T val)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->val == val)
		{
			return true;
		}
		else if (node->val > val)
		{
			SearchByRes(node->BstLeft, val);
		}
		else if (root->val <= val)
		{
			SearchByRes(node->BstRight, val);
		}
	}
	void Preorder(Node<T>* root)
	{
		if (root == nullptr)
			return;
		cout << root->val << ", ";
		Preorder(root->BstLeft);
		Preorder(root->BstRight);
		
	}
	void Preorder()
	{
		Preorder(root);
	}
	void End()
	{
		Node<T>* cur = root;
		while(cur->BstRight != nullptr)
		{
			cur = cur->BstRight;
		}
		cout << "END VALUEO IS: ";
		cout << cur->val << endl;
	}
	void Start()
	{
		cout <<"Start is " << root->val<< endl;
	}
	void levelOrderTraversal()
	{
		if (root == nullptr)
		{
			return;
		}
		queue<Node<T>*> tempQue;
		tempQue.push(root);
		while (!tempQue.empty())
		{
			Node<T>* current = tempQue.front();
			cout << current->val <<',';
			if (current->BstLeft != nullptr)
				tempQue.push(current->BstLeft);
			if (current->BstRight != nullptr)
				tempQue.push(current->BstRight);
			tempQue.pop();
		}
	}
};


int main()
{
	BST<int>* bst = new BST<int>(4);
	bst->insert(2);
	bst->insert(7);
	bst->insert(1);
	bst->insert(3);
	bst->insert(5);
	bst->End();
	bst->Start();
	cout << bst->Search(323)<<endl;
	bst->Preorder();
	bst->levelOrderTraversal();
}

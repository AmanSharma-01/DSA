// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int data;
	struct Node *left, *right;
};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	if(root == NULL) return;

    if(root->data == key)
    {
        if(root->left != NULL)
        {
            Node *temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }
        if(root->right != NULL)
        {
            Node *temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    if(root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else 
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

Node *newNode(int item)
{
	Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}

int main()
{
	int key = 65; //Key to be searched in BST

/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);


	Node* pre = NULL, *suc = NULL;

	findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << "Predecessor is " << pre->data << endl;
	else
	cout << "No Predecessor";

	if (suc != NULL)
	cout << "Successor is " << suc->data;
	else
	cout << "No Successor";
	return 0;
}

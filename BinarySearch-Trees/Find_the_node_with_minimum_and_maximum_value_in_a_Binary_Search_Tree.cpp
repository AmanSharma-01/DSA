//C++ program to find minimum value node in binary search Tree.
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
struct node* node = (struct node*)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

struct node* insert(struct node* node, int data)
{
if (node == NULL)
	return(newNode(data));
else
{
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}
}

int minValue(struct node* node)
{
    struct node *temp = node;

    while(temp->left != NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}

int maxValue(struct node* node)
{
    struct node *temp = node;

    while(temp->right != NULL)
    {
        temp=temp->right;
    }
    return temp->data;
}

int main()
{
struct node* root = NULL;
root = insert(root, 4);
insert(root, 2);
insert(root, 1);
insert(root, 3);
insert(root, 6);
insert(root, 5);

cout << "\n Minimum value in BST is " << minValue(root);
cout << "\n Maximum value in BST is " << maxValue(root);
return 0;
}
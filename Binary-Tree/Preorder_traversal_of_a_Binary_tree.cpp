#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 

void preorder(Node* root) // Recursive function to perform preorder traversal on the tree
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
 

void preorderIterative(Node* root) // Iterative function to perform preorder traversal on the tree
{
    if(root == NULL)
    {
        return;
    }
    stack<Node*>st;
    st.push(root);

    while(!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        cout<<temp->data<<" ";

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    preorderIterative(root);
 
    return 0;
}
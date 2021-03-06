// C++ implementation to sort a k sorted doubly
// linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct compare {
	bool operator()(struct Node* p1, struct Node* p2)
	{
		return p1->data > p2->data;
	}
};

struct Node* sortAKSortedDLL(struct Node* head, int k)
{
	if(head == NULL)
        return head;

    priority_queue<Node*,vector<Node*>, compare> pq;

    struct Node* newHead = NULL, *last;
    for(int i=0;i<=k&&head!=NULL;i++)
    {
        pq.push(head);
        head=head->next;
    }
    while(!pq.empty())
    {
        if(newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();
        if(head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }

        last->next = NULL;
        return newHead;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

void printList(struct Node* head)
{
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 8);
	push(&head, 56);
	push(&head, 12);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);

	int k = 2;

	cout << "Original Doubly linked list:\n";
	printList(head);

	head = sortAKSortedDLL(head, k);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}

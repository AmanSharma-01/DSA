// C++ program to reverse first k elements of a queue.
#include <bits/stdc++.h>
using namespace std;

void reverseQueueFirstKElements(int k, queue<int>& q)
{
	if (q.empty() == true || k > q.size())
        return;
    if (k <= 0)
        return;
    
    stack<int> st;
    for(int i=0;i<k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<q.size()-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void Print(queue<int>& Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

int main()
{
	queue<int> Queue;
	Queue.push(10);
	Queue.push(20);
	Queue.push(30);
	Queue.push(40);
	Queue.push(50);
	Queue.push(60);
	Queue.push(70);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);

	int k = 5;
	reverseQueueFirstKElements(k, Queue);
	Print(Queue);
}
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(int _data, node *_next)
	{
		data = _data;
		next = _next;
	}
};

struct linkedList
{
	node *head;

	linkedList()
	{
		head = NULL;
	}
	
	void deleteFirst()
	{
		if(!head) return;
		head = head->next;
	}

	void insertFirst(int data)
	{
		node *tmp = new node(data, head);
		head = tmp;
	}
    
};

struct mystack
{
	linkedList a;

	void push(int val)
	{
		a.insertFirst(val);
	}

	void pop()
	{
		a.deleteFirst();
	}

	int peek()
	{
		return a.head->data;
	}
};

int main(){
	mystack b;
	b.push(100);
	b.push(200);
	b.pop();
	printf("%d\n",b.peek() );
	return 0;
}
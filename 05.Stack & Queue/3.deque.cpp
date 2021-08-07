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

	void deleteLast()
	{
		if(!head) return;
		node *cur;

		for(cur=head;cur->next->next!=NULL;cur=cur->next);
		cur->next = NULL;
	}
	void insertFirst(int data)
	{
		node *tmp = new node(data, head);
		head = tmp;
	}

	void insertLast(int data)
	{
		node *tmp, *cur;

		if(!head) 
		{
			tmp = new node(data,head);
		    head = tmp;
			return;
		}
		
		for(cur=head;cur->next!=NULL;cur=cur->next);
		tmp = new node(data, NULL);
		cur->next=tmp;
		

	}
    
};

struct mydeque
{
	linkedList a;

	void push_front(int val)
	{
		a.insertFirst(val);
	}

	void push_back(int val)
	{
		a.insertLast(val);
	}

	void pop_front()
	{
		a.deleteFirst();
	}

	void pop_back()
	{
		a.deleteLast();
	}

	int peek()
	{
		return a.head->data;
	}
};

int main(){
	mydeque b;
	b.push_front(100);
	b.push_front(200);
	b.push_back(300);
	b.pop_front();
	b.pop_back();
	printf("%d\n",b.peek() );
	return 0;
}
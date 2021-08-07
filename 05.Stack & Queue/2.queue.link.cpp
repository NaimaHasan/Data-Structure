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
	
	void printList()
	{
		node *cur;
		if(!head) printf("The linked list is empty\n");
		else 
		{
			printf("%d", head->data);
			for(cur=head->next; cur!=NULL; cur=cur->next)
				printf(" -> %d", cur->data);
			puts("");
		}
	}

	void deleteFirst()
	{
		if(!head) return;
		head = head->next;
		
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

struct myqueue
{
	linkedList a;

	void push(int val)
	{
		a.insertLast(val);
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
	myqueue b;
	b.push(100);
	b.push(200);
	b.pop();
	printf("%d\n",b.peek());
	return 0;
}
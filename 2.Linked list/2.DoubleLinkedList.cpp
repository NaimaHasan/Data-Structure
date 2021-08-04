#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next, * prev;
	node()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}

	node(int _data, node *_next)
	{
		data = _data;
		next = _next;
		prev = NULL;
	}

	node(int _data, node * _next, node * _prev)
	{
		data = _data;
		next = _next;
		prev = _prev;
	}
};

struct doubleLinkedList
{

	node *head, *tail;

	doubleLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void printForward()
	{
		if(!head) printf("The linked list is empty\n");
		
		else
		{
			for(node * cur=head;cur!=NULL;cur=cur->next)
				printf("%d%s", cur->data, cur->next == NULL?"\n":" -> ");
		}
	}

	void printBackward()
	{
		if(!tail) printf("The linked list is empty\n");
		
		else
		{
			for(node * cur=tail;cur!=NULL;cur=cur->prev)
				printf("%d%s", cur->data, cur->prev == NULL?"\n":" -> ");
		}
	}

	node *search(int k)
	{
		for(node * cur = head; cur != NULL; cur = cur->next)
		{
			if(cur->data == k)
				return cur;
		}

		return NULL;
	}


	void insertFirst(int data)
	{
		node *tmp = new node(data, head);

		if(head) head->prev = tmp;
		head = tmp;

		if(!tail) tail = tmp;
	}

	void insertLast(int data)
	{
		node *tmp = new node( data, NULL, tail );
		if(tail) tail->next = tmp;
		tail = tmp;

		if(!head) head = tmp;
	}

	void insertBefore(int k, int data)
	{
		node *cur = head;

		if(!head) return;

		if(cur->data == k)
		{
			insertFirst(data);
			return;
		}

		for( ; cur->next != NULL; cur = cur->next){
			if(cur->next->data == k)
			{
				node *tmp = new node(data, cur->next, cur);
				cur->next->prev = tmp;
				cur->next = tmp;
				break;
			}
		}
	}

	void deleteFirst()
	{
		if(!head) return;
		if(head->next) head->next->prev = NULL;
		if(head == tail) tail = NULL;
		head = head->next;
	}

	void deleteLast()
	{
		if(!tail) return;
		if(tail->prev) tail->prev->next = NULL;
		if(head == tail) head = NULL;
		tail = tail->prev;
	}

	void deleteBefore(int k)
	{
		node *cur = head;

		if(!head) return;
		
		if(!(head->next)) return;

		if(cur->next->data == k)
		{
			deleteFirst();
			return;
		}

		for( ; cur->next->next != NULL; cur=cur->next )
		{
			if(cur->next->next->data == k){
				cur->next->next->prev = cur;
				cur->next = cur->next->next;
				break;
			}
		}
	}

	void reverse()
	{
		node *cur, *stored = head, *tmp;

		if(!head) return;
	
		cur = head->next;

		head->prev = head->next;
		head->next = NULL;

		for(; cur != NULL; ){
			tmp = cur->next;
			cur->next = stored;
			cur->prev = tmp;
			stored = cur;
			cur = tmp;
		}
		tail = head;
		head = stored;
	}
};

int main()
{
	doubleLinkedList a;

	a.insertFirst(3);
	a.insertFirst(4);
	a.insertFirst(5);
	a.insertLast(2);
	a.insertFirst(6);	
	a.insertLast(1);

	a.printForward();
	a.printBackward();

	return 0;
}

// Given N person, standing in circular order, you are playing the game of Josephus. The game is played like this. 
// Every time you start counting up to K persons in circle from the current position. 
// You discard the person after you finish counting. Then from that position you again start counting.
// This process ends, when there is only one person remaining. You start from person 1 at the beginning.
// For example, for N = 5, k = 3, the process will go like below:
// Begin: 1 2 3 4 5
// Step1: You start from 1. 1 2 3 4 5. So you discard 3.
// Step2: You start from 4 and circle back. 1 2 4 5. So you discard 1.
// Step3: You start from 2. 2 4 5. So you discard 5.
// Step4: You start from 2. 2 4. So you discard 2.
// So the last person remaining is 4.

//Josephus

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next, * prev;
	node(){
		data = 0;
		next = NULL;
		prev = NULL;
	}
	node(int _data, node *_next){
		data = _data;
		next = _next;
		prev = NULL;
	}
	node(int _data, node * _next, node * _prev){
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


	void insertFirst(int data)
	{
		node *tmp = new node( data, head );
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

struct mQueue{
        doubleLinkedList q;

        void enq(int val)
        {
                q.insertLast(val);
        }
        void deq()
        {
                q.deleteFirst();
        }
        int peek(){
                if(!q.head) return -1;
                return q.head->data;
        }
};

int main()
{
        mQueue persons;
        int n, k, i, last;

        scanf("%d %d", &n, &k);

        for(i = 1; i <= n; i++)
        {
                persons.enq(i);
        }

        while(persons.q.head)
        {
                for(i = 1; i < k; i++)
                {
                        persons.enq(persons.peek());
                        persons.deq();
                }
                last = persons.peek();
                persons.deq();
        }

        printf("%d\n", last);

        return 0;
}

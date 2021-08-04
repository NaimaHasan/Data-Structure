//15
#include<bits/stdc++.h>
using namespace std;
struct node{
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

struct doubleLinkedList{
	node *head, *tail;

	doubleLinkedList(){
		head = NULL;
		tail = NULL;
	}


	void insertFirst(int data){
		node *tmp = new node( data, head );
		if(head) head->prev = tmp;
		head = tmp;

		if(!tail) tail = tmp;
	}

	void insertLast(int data){
		node *tmp = new node( data, NULL, tail );
		if(tail) tail->next = tmp;
		tail = tmp;

		if(!head) head = tmp;
	}

	void deleteFirst(){
		if(!head) return;
		if(head->next) head->next->prev = NULL;
		if(head == tail) tail = NULL;
		head = head->next;
	}

	void deleteLast(){
		if(!tail) return;
		if(tail->prev) tail->prev->next = NULL;
		if(head == tail) head = NULL;
		tail = tail->prev;
	}

	void reverse(){
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

        void enq(int val){
                q.insertLast(val);
        }
        void deq(){
                q.deleteFirst();
        }
        int peek(){
                if(!q.head) return -1;
                return q.head->data;
        }
};

int main(){
        mQueue persons;
        int n, k, i, last;

        scanf("%d %d", &n, &k);

        for(i = 1; i <= n; i++){
                persons.enq(i);
        }

        while(persons.q.head){
                for(i = 1; i < k; i++){
                        persons.enq(persons.peek());
                        persons.deq();
                }
                last = persons.peek();
                persons.deq();
        }

        printf("%d\n", last);

        return 0;
}

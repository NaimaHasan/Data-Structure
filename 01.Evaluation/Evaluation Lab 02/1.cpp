// Design a singly linked list (on top of the given code) with the following methods:

// insertBefore(int k, int data): inserts a new node before the node with value k. 
// 	If there is no node in the linked list, then it simply returns.

// deleteBefore(int k): deletes the node before the node with value k. 
// 	If there is no such node in the linked list, then it simply returns.

// reverse(): reverses the linked list.

#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
	node(){
		data = 0;
		next = NULL;
	}
	node(int _data, node *_next){
		data = _data;
		next = _next;
	}
};
struct linkedList{
	node *head;
	linkedList(){
		head = NULL;
	}
	void printList(){
		if(!head) printf("The linked list is empty\n");
		else {
			printf("%d", head->data);
			for(node *cur = head->next; cur != NULL; cur = cur->next){
				printf(" -> %d", cur->data);
			}
			puts("");
		}
	}
	void deleteFirst(){
		if(!head) return;
		head = head->next;
	}
	void deleteLast(){
		if(!head) return;
		if(!head->next){
			head = NULL;
			return;
		}
		node *cur;
		for(cur = head; cur->next->next != NULL; cur = cur->next);
		cur->next = NULL;
	}
	node *searchKey(int key){
		for(node *cur = head; cur != NULL; cur = cur->next){
			if(cur->data == key){
				return cur;
			}
		}
		return NULL;
	}
	void insertAfterNode(node *cur, int data){
		if(!head && cur == head){
				insertFirst(data);
				return;
		}

		node *tmp = new node(data, NULL);
		tmp->next = cur->next;
		cur->next = tmp;
	}
	void insertLast(int data){
		if(!head) {
			insertFirst(data);
			return;
		}
		node *cur;
		for(cur = head; cur->next != NULL; cur = cur->next);
		insertAfterNode(cur, data);
	}
	void insertFirst(int data){
		node *tmp = new node(data, head);
		head = tmp;
	}
	
	void insertBefore(int k, int data){
		node * cur =  head, *tmp;
	
		if(!head) return;

		if(cur->data == k){
			insertFirst(data);
			return;
		}

		for( cur = head; cur->next != NULL; cur = cur->next ){
			if(cur->next->data == k){
				insertAfterNode(cur, data);
				break;
			}
		}
	}

	void deleteBefore(int k){
		node * cur = head;

		if(!head) return;

		if(!(head->next)) return;
	
		if(cur->next->data == k){
			deleteFirst();
			return;
		}

		for( cur = head; cur->next->next != NULL; cur = cur->next ){
				if(cur->next->next->data == k){
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
        head->next = NULL;

		while(cur != NULL)
		{
			tmp = cur->next;
			cur->next = stored;
			stored = cur;
			cur = tmp;
		}
		head = stored;
	}
};

int main(){
	linkedList a, b;

	a.insertFirst(1);
	a.insertFirst(2);
	a.insertFirst(3);
	
	a.printList();
	return 0;
}

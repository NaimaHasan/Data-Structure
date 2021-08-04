#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node * next;

	node(int _data, node * _next){
		data = _data;
		next = _next;
	}
	node(int _data){
		data = _data;
		next = NULL;
	}
};

struct List{
	node * head;

	List(int _data){
		head = new node(_data, NULL);
	}
	List(){
		head = NULL;
	}

	void deleteNodeAfter(node * target){
		if(target->next==NULL)
			printf("There exists no node after this");
		else 
			target->next = target->next->next;
	}

	void insertFirst(int _data){
		head = new node(_data, head);
	}

	void insertAfterNode(int _data, node * target){
		node * tmp = new node(_data, target->next);
		target->next = tmp;
	}

	void printList(){
		node * cur;
		for( cur = head; cur != NULL; cur = cur->next)
			printf("%d%s", cur->data, cur->next==NULL?"\n":" -> ");
	}

	void insertXAfterFirstK(int x, int k){
		node * cur;

		for(cur = head; cur != NULL; cur = cur->next){
			if(cur->data == k){
				insertAfterNode(x, cur);
				break;
			}
		}
	}

	void deleteXImmediatelyAfterK(int x, int k){
		node * cur;

		for(cur = head; cur!=NULL; cur = cur -> next){
			if(cur->data == k){
				if(cur->next == NULL);
				else{
					if(cur->next->data == x)
						deleteNodeAfter(cur);
				}
			}
		}
	}

	void deleteFirstXAfterK(int x, int k){
		node * cur;

		for(cur = head; cur!=NULL; cur = cur->next){
			if(cur->data == k)
				break;
		}
		for(cur = head; cur!=NULL;cur = cur->next){
			if(cur->next == NULL);
			else{
				if(cur->next->data == x){
					deleteNodeAfter(cur);
					break;
					}
			}
		}
	}

	int checkPalindrome(){
		int flag, size, left, right, i, j;
		node * cur;

		for( cur = head, size = 0; cur != NULL; cur = cur->next, size++);

		for(i = 0; i < size/2; i++){
			for( cur = head, j = 0; j < i; cur = cur->next, j++);
			left = cur->data;

			for( cur = head, j = 0; j < size - i - 1; cur = cur->next, j++);
			right = cur->data;

			if(left != right)
				return 0;
		}
		return 1;
	}
};

int main(){
	List a;
	int n, i, d, x, k;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &d);
		a.insertFirst(d);
	}

	a.printList();

	printf("Enter an X you wish to insert and a K: ");
	scanf("%d %d", &x, &k);
	a.insertXAfterFirstK(x, k);
	a.printList();

	printf("Enter an X you wish to delete and a K:");
	scanf("%d %d", &x, &k);
	a.deleteFirstXAfterK(x, k);
	a.printList();

	if(a.checkPalindrome())
		printf("Palindrome\n");
	else printf("Not Palindrome\n");
	
	return 0;
}

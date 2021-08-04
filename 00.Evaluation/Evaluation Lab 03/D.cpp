//15
//15
//15
//15
//15
//15
#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node * next;

	node(){
		data = 0;
		next = NULL;
	}

	node(char _data, node *_next){
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
		if(!head) return;

		printf("%c", head->data);

		for(node *cur = head->next; cur != NULL; cur = cur->next)
			printf("%c", cur->data);

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

	void deleteFirst(){
		if(!head) return;
		node *tmp = head;
		head = head->next;
		free(tmp);
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
	

	void reverse(){
		node * cur, * stored = head, * tmp;

		if(!head) return;

		cur = head->next;

		head->next = NULL;

		for( ; cur != NULL; ){
			tmp = cur->next;
			cur->next = stored;
			stored = cur;
			cur = tmp;
		}
		head = stored;
	}
};

struct mStack{
	linkedList list;

	void pop(){
		list.deleteFirst();
	}

	void push(int data){
		list.insertFirst(data);
	}
	char peek(){
		return list.head->data;
	}
};

bool isOperator(char ch){
	return (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int printPostfix(char s[]){
	mStack a, b;
	mStack opStack, opeStack;

	int precedence[256];

	memset(precedence, -1, sizeof(precedence) );

	precedence['^'] = 3;
        precedence['*'] = 2;
        precedence['/'] = 2;
        precedence['+'] = 1;
        precedence['-'] = 1;
        precedence['('] = 0;
        precedence[')'] = 0;

	for(int i = 0; s[i]; i++){
		if( !isOperator(s[i]) )
			a.push(s[i]);
		else{
			if(b.list.head == NULL)
				b.push(s[i]);

			else if(s[i] == '(')
				b.push(s[i]);

			else if(s[i] == ')'){
				while( b.peek() != '(' ){
					a.push( b.peek() );
					b.pop();
				}
				b.pop();
			}

			else{
				while( precedence[b.peek()] >= precedence[s[i]]){
					a.push( b.peek() );
					b.pop();
					if(b.list.head == NULL)
						break;
				}
				b.push(s[i]);
			}
		}
	}

	while(b.list.head != NULL){
		a.push( b.peek() );
		b.pop();
	}

	a.list.reverse();
	while( a.list.head != NULL ){
		if( !isOperator(a.peek()) ){
			opStack.push( a.peek() - '0');
			a.pop();
		}
		else{
			opeStack.push( a.peek() );
			a.pop();
		}
	}

	while(opeStack.list.head != NULL){
		int x, y;

		x = opStack.peek();
		opStack.pop();
		y = opStack.peek();
		opStack.pop();

		if( opeStack.peek() == '+' ){
			opStack.push( x+y );
			opeStack.pop();
		}
		else if( opeStack.peek() == '-'){
			opStack.push( x-y );
			opeStack.pop();
		}
		else if( opeStack.peek() == '*'){
			opStack.push( x*y );
			opeStack.pop();
		}
		else if( opeStack.peek() == '/'){
			opStack.push( x/y );
			opeStack.pop();
		}
	}

	return opStack.list.head->data;
}

int main(){
	char s[1000], infix[1000];
	int i, k;

	fgets(s, 1000, stdin);

	s[strlen(s) - 1] = 0;

	for(i = 0, k = 0; s[i]; i++){
		if(s[i] != ' '){
			infix[k] = s[i];
			k++;
		}
	}
	infix[k] = 0;

	printf("%d", printPostfix(infix));
	printf("\n");

	return 0;
}

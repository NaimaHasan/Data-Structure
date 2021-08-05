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

struct CircularlyLinkedList
{
	node *head;

	CircularlyLinkedList()
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
			for(cur=head->next; cur!=head; cur=cur->next)
				printf(" -> %d", cur->data);
			puts("");
		}
	}

	int len()
    {
        node *cur;
        int c = 0,i;
        if(!head) printf("The linked list is empty\n");
        else
        	for(cur = head, i = 0; cur!= head || i == 0; cur = cur->next, i++) c++;
        
        return c;
    }

	void deleteFirst()
	{
		node *cur;
		if(!head) return;
		if(head == head->next)
		{
			head = NULL;
			return;
		}

		for(cur = head; cur->next != head; cur = cur->next);
		cur->next = head->next;
		head = head->next;
	}

	void deleteLast()
	{
		node *cur;
		if(!head) return;
		if(head == head->next)
		{
			head = NULL;
			return;
		}

		for(cur = head; cur->next->next != head; cur = cur->next);
		cur->next = head;
	}

	void deleteAfterK(int k, int d)
    {
    	node *cur, *tmp;
    	int i;

    	for(cur = head, i = 0; cur!= head || i == 0; cur = cur->next, i++)
    		if(cur->data == k) 
    			break;
        
        for(tmp = cur; tmp->next!= head; tmp = tmp->next)
    	{
            if(tmp->next->data==d)
            	tmp->next=tmp->next->next; 
            
        }
    }

    void deleteBefore(int k)
    {
		node *cur = head;

		if(!head) return;

		if(head == head->next) return;
	
		for(cur = head; cur->next->next != head; cur = cur->next)
		{
			if(cur->next->next->data == k)
			{
				cur->next = cur->next->next;
				break;
			}
		}
	}
	
	node *searchKey(int key)
	{
		node *cur;
		int i;
		for(cur = head, i = 0; cur!= head || i == 0; cur = cur->next, i++)
		{
			if(cur->data == key)
			{
				return cur;
			}
		}
		return NULL;
	}

	void insertAfterNode(node *cur, int data)
	{
		if(!head)
		{
			insertFirst(data);
			return;
		}
  
		node *tmp = new node(data, cur->next);
		//tmp->next = cur->next;
		cur->next = tmp;
	}

	void insertAfterK(int k, int d)
    {
    	node *cur, *tmp;
    	int i;

    	for(cur = head, i = 0; cur!= head || i == 0; cur = cur->next, i++)
    	{
            if(cur->data == k)
            {
                tmp = new node(d, cur->next);
                //tmp->next = cur->next;
                cur->next = tmp;
            }
    	}

    }
    void insertBefore(int k, int data)
    {
		node *cur =  head, *tmp;
	
		if(!head) return;

		if(cur->data == k)
		{
			insertFirst(data);
			return;
		}

		for(cur = head; cur->next != head; cur = cur->next)
		{
			if(cur->next->data == k){
				insertAfterNode(cur, data);
				break;
			}
		}
	}

	void insertLast(int data)
	{
		if(!head)
		{
			insertFirst(data);
			return;
		}

		node *cur;
		for(cur = head; cur->next != head; cur = cur->next);
		insertAfterNode(cur, data);
	}
	
	void insertFirst(int data)
	{
		node *cur, *tmp;

		if(!head)
		{
			head = new node(data, NULL);
			head->next = head;
			return;
		}

		tmp = new node(data, head);
		
		for(cur = head; cur->next != head; cur = cur->next);
		cur->next = tmp;
		head = tmp;
	}
	
	void reverse()
	{
		node *cur, *stored, *tmp, *last;

		if(!head) return;

		for(cur = head; cur->next != head; cur = cur->next);
		last = cur;

		stored = head;
		cur = head->next;

        
        while(cur != head)
		{
			tmp = cur->next;
			cur->next = stored;
			stored = cur;
			cur = tmp;
		}

		head->next = last;
		head = stored;
	}
};

int main(){
	CircularlyLinkedList a;
	a.insertFirst(100);
	a.insertFirst(200);
	a.insertFirst(400);
	a.insertAfterNode(a.head,300);
	a.insertAfterK(100,95);
	a.insertLast(90);
	a.insertBefore(200,250);
	a.deleteLast();
	a.deleteFirst();
	a.deleteBefore(100);
	a.deleteAfterK(300,95);
	a.printList();
	a.reverse();
	a.printList();
	
	return 0;
}
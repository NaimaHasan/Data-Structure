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

	int len()
    {
        node *cur;
        int c=0;
        for(cur=head;cur!=NULL;cur=cur->next) c++;
        return c;
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

	void deleteAfterK(int k, int d)
    {
    	node *cur, *tmp;

    	for(cur=head;cur!=NULL;cur=cur->next)
    		if(cur->data==k) 
    			break;
        
        for(tmp=cur;tmp->next!=NULL;tmp=tmp->next)
    	{
            if(tmp->next->data==d)
            	tmp->next=tmp->next->next; 
            
        }
    }

    void deleteBefore(int k)
    {
		node *cur = head;

		if(!head) return;

		if(!(head->next)) return;
	
		if(cur->next->data == k){
			deleteFirst();
			return;
		}

		for(cur=head;cur->next->next!=NULL;cur=cur->next)
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
		for(node *cur=head;cur!=NULL;cur=cur->next)
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
		node *tmp = new node(data, cur->next);
		//tmp->next = cur->next;
		cur->next = tmp;
	}

	void insertAfterK(int k, int d)
    {
    	node *cur, *tmp;
    	for(cur=head;cur!=NULL;cur=cur->next)
    	{
            if(cur->data==k)
            {
                tmp= new node(d, cur->next);
                //tmp->next = cur->next;
                cur->next=tmp;
            }
    	}

    }
    void insertBefore(int k, int data)
    {
		node *cur =  head, *tmp;
	
		if(!head) return;

		if(cur->data == k){
			insertFirst(data);
			return;
		}

		for(cur=head;cur->next!=NULL;cur=cur->next )
		{
			if(cur->next->data == k){
				insertAfterNode(cur, data);
				break;
			}
		}
	}

	/*void insertLast(int data){
		if(!head) insertFirst(data);
		node *cur;
		for(cur = head; cur->next != NULL; cur = cur->next);
		insertAfterNode(cur, data);
	}*/
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
	

    bool palindrome()
    {
        node *cur, *tmp=head;
        int i,j,c=0,n=0;
        for(cur=head;cur!=NULL;cur=cur->next) n++;
        cur=head;
        for(i=1;i<=n/2;i++)
        {
        	cur=cur->next;
            for(j=1;j<=n-1-i;j++) tmp=tmp->next;
            if(cur->data==tmp->data) c++;
            tmp=head;
        }
        if(c==n/2) return true;
        return false;
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
	a.insertFirst(100);
	a.insertFirst(200);
	a.insertFirst(400);
	a.insertAfterNode(a.head,300);
	a.insertAfterK(100,95);
	a.insertLast(90);
	a.printList();
	a.reverse();
	a.printList();
	
	return 0;
}
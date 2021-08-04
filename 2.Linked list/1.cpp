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
		if(!head) printf("The linked list is empty\n");

		else 
		{
			printf("%d", head->data);
			for(node *cur = head->next; cur != NULL; cur = cur->next)
			{
				printf(" -> %d", cur->data);
			}
			puts("");
		}
	}

	void deleteFirst()
	{
		if(!head) return;
		head = head->next;
	}

	void deleteLast()
	{
		if(!head) return;

		if(!head->next)
		{
			head = NULL;
			return;
		}

		node *cur;
		for(cur = head; cur->next->next != NULL; cur = cur->next);

		cur->next = NULL;
	}

	node *searchKey(int key)
	{
		for(node *cur = head; cur != NULL; cur = cur->next)
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
		if(!head && cur == head)
		{
				insertFirst(data);
				return;
		}

		node *tmp = new node(data, NULL);
		tmp->next = cur->next;
		cur->next = tmp;
	}

	void insertLast(int data)
	{
		if(!head) 
		{
			insertFirst(data);
			return;
		}

		node *cur;
		for(cur = head; cur->next != NULL; cur = cur->next);

		insertAfterNode(cur, data);
	}

	void insertFirst(int data)
	{
		node *tmp = new node(data, head);
		head = tmp;
	}
	
	void insertBefore(int k, int data)
	{
		node * cur =  head, *tmp;
	
		if(!head) return;

		if(cur->data == k)
		{
			insertFirst(data);
			return;
		}

		for( cur = head; cur->next != NULL; cur = cur->next )
		{
			if(cur->next->data == k)
			{
				insertAfterNode(cur, data);
				break;
			}
		}
	}

	void deleteBefore(int k)
	{
		node * cur = head;

		if(!head) return;

		if(!(head->next)) return;
	
		if(cur->next->data == k)
		{
			deleteFirst();
			return;
		}

		for( cur = head; cur->next->next != NULL; cur = cur->next )
		{
				if(cur->next->next->data == k)
				{
					cur->next = cur->next->next;
					break;
				}
		}
	}

	void reverse()
	{
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

	void insertAfterK(int k, int d)
    {
    	node *cur, *tmp;
    	for(cur=head;cur!=NULL;cur=cur->next)
    	{
            if(cur->data==k)
            {
                tmp= new node(d,NULL);
                tmp->next = cur->next;
                cur->next=tmp;
            }
    	}

    }

    
    void deleteAfterK(int k, int d)
    {
    	node *cur, *tmp;
    	for(cur=head;cur!=NULL;cur=cur->next)
    	{
            if(cur->data==k) break;
        }
        for(tmp=cur;tmp!=NULL;tmp=tmp->next)
    	{
            if(tmp->next==NULL);
            else
            {
                if(tmp->next->data==d)
                tmp->next=tmp->next->next; 
            }
        }
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
};

int main(){
	linkedList a, b;

	a.insertFirst(1);
	a.insertFirst(2);
	a.insertFirst(3);
	
	a.printList();
	return 0;
}

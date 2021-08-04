#include<stdio.h>
struct node
{
	int data;
	node *next;
	node()
	{
		data=0;
		next= NULL;
    }

    node(int _data, node *_next)
    {
        data=_data;
        next=_next;
    }
 
};

struct Link
{
	node *head;

	void print()
	{
		for(node *cur=head; cur!=NULL; cur= cur->next) printf("%d ", cur->data);
        puts("");
	}

    int len()
    {
        node *cur;
        int c=0;
        for(cur=head;cur!=NULL;cur=cur->next) c++;
        return c;
    }

	void delfirst()
	{
		head= head->next;
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
	Link a;
	int n,d,i,x,k;
	bool m;
	scanf("%d",&n);
	
    for(i=1;i<=n;i++)
	{
		scanf("%d",&d);
		if(i==1) a.head= new node(d,NULL);
		else     a.head= new node(d,a.head);
	}

    scanf("%d%d",&x,&k);
    a.insertAfterK(x,k);
    a.print();
	a.deleteAfterK(x,k);
    a.print();
    
    m=a.palindrome();
    if(m)
    printf("palindrome\n");
    else printf("not palindrome\n");

}
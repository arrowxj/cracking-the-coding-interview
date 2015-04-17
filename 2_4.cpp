#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;
node* LinkList(int a[],int n)
{
	node *head,*p;
	for(int i=0;i<n;i++)
	{
		node *nd = new node();
		nd->data = a[i];
		if(i==0)
		{
			head = p = nd;
		}
		else
		{
			p->next = nd;
			p = nd;
		}
		nd->next = NULL;
	}
	return head;
}
void print(node *head)
{
	node *p = head;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
	return;
}

void sort(node *head, int k)
{
	if(!head)
		return;
	node *p = head;
	while(p->next)
	{
		if((p->data)>=k)
		{
			node *q = p->next;
			while(q && (q->data)>=k)
				q = q->next;
			if(q)
			{
				int temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
		p = p->next;
	}
	return;
}
int main()
{
	int a[] = {2,5,3,2,7};
	node *head = LinkList(a,5);
	print(head);
	sort(head,4);
	print(head);
	return 0;
}

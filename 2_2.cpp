#include<iostream>
#include<cstring>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* LinkListStruct(int a[],int n)
{
	node *head, *p;
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

void LastK(node *head,int k)
{
	if(head==NULL)
		return;
	node *first = head, *last = head;
	for(int i=1;i<k;++i)
	{
		last = last->next;		
	}
	if(!last)
	{
			cout<<"linklist size less than k"<<endl;
			return;
	}
	while(last->next)
	{
		first = first->next;
		last = last->next;
	}
	cout<<first->data<<endl;
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
}

int main()
{
	node *head;
	int a[]={5,3,6,1,9,0,2,7,2,8,3};
	head = LinkListStruct(a,11);
	print(head);
	LastK(head,3);
	return 0;
}

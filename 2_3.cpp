#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* LinkListStruct(int a[],int n)
{
	node *head,*p;
	if(n==0)
		return head;
	for(int i=0;i<n;++i)
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

void NodeDelete(node *nd)
{
	if(!(nd->next)|| !nd)
	{
		cout<<"can't delete the last node"<<endl;
		return;
	}
	node *nnd = nd->next;
	nd->data = nnd->data;
	nd->next = nnd->next;
	delete nnd;
	return;
	
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
int main()
{
	int a[]={1,2,3,4,5,6,7};	
	node* head = LinkListStruct(a,7);
	node* nd = head;
	for(int i=0;i<6;i++)
		nd = nd->next;
	NodeDelete(nd);	
	print(head);
	return 0;
}

#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

//构造循环链表
node* LinkList(int a[],int n, int k)
{
	node *head,*p,*temp;
	for(int i=0;i<n;i++)
	{
		node *nd = new node();
		nd->data = a[i];		
		if(i==k-1)
			temp = nd;
		if(i==0)
			head = p = nd;
		else
		{			
			p->next = nd;
			p = nd;
		}
		nd->next = NULL;
	}
	p->next = temp;
	return head;
}

void print(node *head,int n)
{
	node *p = head;
	for(int i=0;i<n+7;++i)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
	return;
}

node* StartRing(node *head)
{
	if(!head)
		return NULL;
	node *fast = head;
	node *slow = head;
	while(fast && fast->next)//不用while(slow!=fast)
	{	
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
			break;
	}
	if(!fast || !fast->next)
		return NULL;
	slow = head;
	while(fast!=slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	node *head = LinkList(a,7,3);
	print(head,7);
	node *ret = StartRing(head);
	cout<<ret->data<<endl;
	return 0;
}

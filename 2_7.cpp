#include<iostream>
#include<stack>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* LinkList(int a[],int n)
{
	if(n==0)
		return NULL;
	node *head,*p;
	for(int i=0;i!=n;++i)
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

node* Transpose(node* head)
{
	if(!head)
		return NULL;
	node *new_head, *p;
	p = head;
	while(p)
	{
		node *nd = new node();
		nd->data = p->data;
		if(!head)
		{
			new_head = nd;
			nd->next = NULL;
		}
		else
		{
			nd->next = new_head;
			new_head = nd;
		}
		p = p->next;
	}
	return new_head;
}
bool isPalindrome(node *head, node *new_head)
{
	if(!head)
		return false;
	node *p = head;
	node *q = new_head;
	while(p&&q)
	{
		if(p->data == q->data)
		{
			p = p->next;
			q = q->next;
		}
		else
			return false;
	}
	return true;
}

bool isPalindrome1(node *head)//栈
{
	if(!head)
		return false;
	node *slow = head;
	node *fast = head;
	stack<int> sta;
	while(fast && fast->next)
	{
		sta.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast)//奇数个节点
		slow = slow->next;
	while(slow)
	{
		if(slow->data!=sta.top())
			return false;
		sta.pop();
		slow = slow->next;
	}
	return true;
}
int main()
{
	//int a[]={1,2,3,4,5,4,3,2,1};
	//int a[]={1,2,3,4,5,4,7,2,0};
	//int a[]={1,2,3,4,5,4,7,2};
	//int a[]={1,2,3,4,4,3,2,1};
	int a[]={};
	node *head = LinkList(a,0);
	print(head);
	node *new_head = Transpose(head);
	print(new_head);
	cout<<isPalindrome(head,new_head);
	cout<<isPalindrome1(head);
	return 0;
}

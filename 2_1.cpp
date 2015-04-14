#include<iostream>
#include<cstring>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

bool hash[100];
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

void RemoveDuplicate(node *head)
{
	if(head==NULL)
		return;
	node *p = head;
	hash[head->data] = true;
	while(p && p->next)
	{
		if(hash[p->next->data])
		{
			node *temp = p->next;
			p->next = p->next->next;
			delete temp;			
		}
		else
		{
			hash[p->next->data] = true;
		}
		p = p->next;
	}
}

void RemoveDuplicate1(node *head) //不使用临时缓冲区
{
	if(head == NULL)
		return; 
	for(node *p=head;p;p=p->next)
	{
		node *prev = p;
		node *q = prev->next;
		while(q)
		{
			if(p->data == q->data)
			{
				node *temp = q;
				prev->next = q->next;
				q = q->next;
				delete temp;
			}
			else
			{
				prev = q;
				q = q->next;
			}
		}
	}
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
	memset(hash,false,sizeof(hash));
	head = LinkListStruct(a,11);
	RemoveDuplicate(head);
	print(head);
	RemoveDuplicate1(head);
	print(head);
	return 0;
}

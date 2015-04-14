#include<iostream>
using namespace std;

void ZeroClear(int *a,int m,int n)
{
	if(a==NULL)
		return;
	int row[m],coloumn[n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(*(a+i*n+j)==0)
			{
				row[i]=1;
				coloumn[j]=1;
			}
		}
	for(int i=0;i<m;i++)
	{
		if(row[i]==1)
		{
			for(int j=0;j<n;j++)
				*(a+i*n+j)=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(coloumn[i]==1)
		{
			for(int j=0;j<m;j++)
				*(a+j*n+i)=0;
		}
	}
}

void print(int *a,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<*(a+i*n+j)<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int a[3][4]={{0,1,2,3},{4,5,0,7},{8,9,10,11}};
	//int b[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	ZeroClear(&a[0][0],3,4);
	//ZeroClear(&b[0][0],3,3);
	print(&a[0][0],3,4);
	//print(&b[0][0],3,3);
	return 0;
}

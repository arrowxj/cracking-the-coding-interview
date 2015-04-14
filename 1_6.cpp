#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
//使用额外空间
void rotate1(int a[][4])
{
	//使用额外的空间
	int b[4][4];
	for(int i=0; i<4;i++)
		for(int j=0;j<4;j++)
			b[j][4-i-1] = a[i][j];
	for(int i=0; i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<b[i][j]<<' ';
		cout<<endl;
	}
}

//不使用额外空间
void rotate2(int a[][4])
{//右对角线交换 左右交换
	for(int i=0;i<4;i++)//右对角线交换
		for(int j=i;j<4;j++)
			swap(a[i][j],a[j][i]);
			
	for(int j=0;j<2;j++)//左右交换
		for(int i=0;i<4;i++)
			swap(a[i][j],a[i][4-j-1]);	
	for(int i=0; i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
}

int main()
{
	int a[4][4]={1,2,3,4,
			   5,6,7,8,
			   9,10,11,12,
			   13,14,15,16};
	//int b[3][3]={1,2,3,
	//		   4,5,6,
	//		   7,8,9};
	rotate1(a);
	//rotate1(b,3);
	rotate2(a);
	//rotate2(b,3);
	return 0;
}

#include<iostream>
using namespace std;

void reverse(char *str)
{
	int len=0;
	char temp;
	for(int i=0; str[i]; ++i)
		len++;
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		char temp =  str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

int main()
{
	char s1[] ="askfhkhg";
	char s2[] = "akhg ljlgoa jlgjo";
	reverse(s1);
	reverse(s2);
	cout<<s1<<endl;
	cout<<s2<<endl;
	return 0;
}

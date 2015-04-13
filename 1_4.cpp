#include<iostream>
#include<string>
using namespace std;

void ReplaceSpace(string &s)
{
	int space_num=0;
	int old_length = s.size();
	for(string::size_type i=0; i<old_length;++i)
	{
		if(s[i]==' ')
			space_num++;
	}
	int bias = 2*space_num;
	int new_length = old_length+bias;
	s.resize(new_length);
	
	for(int j=old_length-1;j>=0;--j)
	{
		if(s[j]!=' ')
		{
			s[j+bias]=s[j];			
		}
		else
		{
			s[j+bias] = '0';
			--bias;
			s[j+bias] = '2';
			--bias;
			s[j+bias] = '%';
		}
	}
}

int main()
{
	//string s="Mr John Smith";
	//string s=" Mr John Smith ";
	//string s="MrJohnSmith";
	//string s="   ";
	string s="";
	ReplaceSpace(s);
	cout<<s<<endl;
	return 0;
}

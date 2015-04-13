#include<iostream>
#include<string>
using namespace std;

string StringCompression(string s)
{	
	if(s=="")
		return s;
	string ret="";
	int count=0;
	for(string::size_type i=0,j=0;i!=s.size()&&j!=s.size();)
	{
		if(s[i]==s[j])
		{
			count++;
			if(count==1)
				ret+=s[i];
			j++;
		}
		else
		{			
			if(count>1)
				ret+=count+'0';
			i = j;
			count=0;
		}
		
	}
	if(count>1)
			ret+=count+'0';
	if(ret.size()>=s.size())
		return s;
	return ret;
}

int main()
{
	string s1="a";
	string s2="aabcccccaa";
	string s3="aaaaa";
	string s4="abcdef";
	cout<<StringCompression(s1)<<endl;
	cout<<StringCompression(s2)<<endl;
	cout<<StringCompression(s3)<<endl;
	cout<<StringCompression(s4)<<endl;
	return 0;
}

#include<iostream>
#include<cstring>

using namespace std;

bool IsSame(string s1, string s2)
{
	if(s1=="" || s2=="") //不能用s1==NULL
		return false;
	if(s1.size()!=s2.size())
		return false;
	int hash[256];
	memset(hash,0,sizeof(hash));
	int len = s1.size();
	for(int i=0;i<len;++i)
	{
		hash[(int)s1[i]]++;
		hash[(int)s2[i]]--;
	}
	for(int j=0;j<256;++j)
	{
		if(hash[j])
			return false;
	}
	return true;
}

int main()
{
	//string s1="dajogjoajgl";
	//string s2="shojaot nosdg";
	string s1="dddassad";
	string s2="sdasdadd";
	cout<<IsSame(s1,s2)<<endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

class solution{
	public:
		bool IsStringSame(string &s){
			if(s.empty())
				return false;
			int table[256];
			for(int i=0;i<256;++i)
				table[i]=0;
			for(string::size_type j=0; j<s.size();++j)
			{
				int t = s[j]%256;
				table[t]++;
				if(table[t]>1)
					return false;
			}
			return true;
		}
};

bool IsStringSame(string &s)
{
	if(s.empty())
		return false;
	int table[256];
	for(int i=0;i<256;++i)
		table[i]=0;
	for(string::size_type j=0; j<s.size();++j)
	{
		int t = s[j]%256;			
		table[t]++;
		if(table[t]>1)
		return false;
	}
	return true;
}
		
int main()
{
	string s1 = "";
	string s2 = "abcdefg";
	string s3 = "abcdefgajhik";
	string s4 = "a bcdefg";
	string s5 = "1bc def12345";
	string s6 = "1234567890";
	cout<<IsStringSame(s1)<<" "<<IsStringSame(s2)<<" "<<IsStringSame(s3)<<endl;	
	cout<<IsStringSame(s4)<<" "<<IsStringSame(s5)<<" "<<IsStringSame(s6)<<endl;
	return 0;
}

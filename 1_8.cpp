//若s2由s1旋转而来，则s2一定是s1s1的子串
//s1=xy; s2=yx; s1s1 = xyxy
bool IsRotation(string s1,string s2)
{
	if(s1.size()==s2.size() && s1.size()>0)
	{
		string s1s1 = s1+s1;
		return isSubstring(s1s1,s2);
	}
	return false;
}

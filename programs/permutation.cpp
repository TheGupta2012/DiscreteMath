#include<bits/stdc++.h>
using namespace std;
void permute(string s)
{	int m,index;
	int min=INT_MAX;
	for(int i=s.size()-1;i>=1;i-=1)
	{
		if(s[i-1]<s[i])
		{ m=i-1;
		  break;
		}
	}
	for(int i=m+1;i<s.size();i+=1)
	{
		if(s[i]>s[m])
		{ if(s[i]<min) 
			{min=s[i];
			index=i;} // finding the smallest element amongst a(m+1) to a(n) that is larger than a(m)
		}
	}
	char temp;
	temp=s[m]; //swapping the element with the smallest element greater than it
	s[m]=s[index];
	s[index]=temp;
	sort(s.begin()+m+1,s.end()); //arranging the elements ahead of a(m)
	cout<<endl<<s;
}
int main()
{
	cout<<"\nGENERATING THE LEXICOGRAPHICALLY NEXT PREMUTATION...";
	string s;
	cout<<"\nEnter the string:";
	cin>>s;
	cout<<"\nThe next permutation of the string is:";
	permute(s);
	return 0;
}

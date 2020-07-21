#include<bits/stdc++.h>
#define For(i,n) for(int i=0;i<n;i+=1)
using namespace std;
void combo(string set, int n,int k)
{	int j=0;
	int m=-1;
	for(int i=k-1;i>=0;i-=1)
	{
		if((set[i]-'0')!=(n-j))
			{ m=i;
			  break;
			}
		else j++;
	}
	if(m==-1)
		{
		cout<<"\nMaximal subset.";
		return;}
	set[m]=(set[m]+1);
	for(int i=m+1;i<k;i+=1)
		set[i]=(set[i-1]+1);
	for(int i=0;i<k;i++)
	{ cout<<set[i];
	}
}
int main()
{
	cout<<"\n\t\tFinding the next k-subset combination from the given subset.\n";
	cout<<"\nEnter the size of set (1-n) :";
	int n;
	cin>>n;
	cout<<"Your set is : {";
	For(i,n)
	{	if(i!=n-1) cout<<i+1<<",";
		else cout<<i+1<<"}";
	}
	int k;
	x:cout<<"\nEnter k:";
	cin>>k;
	if(k>n)
		{ cout<<"\nInvalid k\nEnter again.";
		goto x;}
	string set;
	y:cout<<"\nEnter the subset:";
	cin>>set;
	For(i,k)
		{if(set[i]-'0'>n) 
			{ cout<<"\nInvalid subset\nEnter within bounds";
			goto y;}
	}
	cout<<"\nThe next combination is :";
	combo(set,n,k);
	return 0;
}

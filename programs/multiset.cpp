#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FOR(i,n) for(int i=0;i!=n;i++)
using namespace std;
void add(map <string,int> a, map<string,int> b)
{	cout<<"\nThe addition of multisets is:";
	tr(a,it1) // to print the common and non-common values in a that are not in b 
	{
		map <string,int>::iterator it2 = b.find(it1->first);
		if(it2!=b.end())
			{FOR(i,it1->second+it2->second)
				cout<<(it1->first)<<" ";
			}
		else
		{
			FOR(i,it1->second)
				cout<<it1->first<<" ";
		}
	}
	tr(b,it1) // to find the values in b that are not in a
	{
		if(a.find(it1->first)==a.end())
		{
			FOR(i,it1->second)
				cout<<it1->first<<" ";
		}
	}
}
void subtract(map <string,int> a, map<string,int> b)
{	int flag=0;
	cout<<"\nThe difference of sets is:";
	tr(a,it1) // finding if the element of a present in b or not.
	{ if(b.find(it1->first)==b.end())
			{flag=1; 
			FOR(i,it1->second)
				cout<<it1->first<<" ";
		    }
	else 	
	{
		map<string,int>::iterator it2 = b.find(it1->first);
		int diff= (it1->second)-(it2->second);
		if(diff>0)
			{	flag=1; 
			FOR(i,diff)
				cout<<(it1->first)<<" ";}
		else 
			continue;
	}
	}
	if(flag==0)
	 cout<<"NULL SET";
}
void Union(map<string,int> a, map<string,int> b)
{
	cout<<"\nThe union is:";
	tr(a,it1)
	{
		if(b.find(it1->first)==b.end())
		{
			FOR(i,it1->second)
				cout<<it1->first<<" ";//printing elements of a which are not common with b
		}
		else
		{
			map<string,int>::iterator it2=b.find(it1->first);
			if(it1->second>=it2->second)
				{
					FOR(i,it1->second)
						cout<<it1->first<<" ";// printing common elements
				}
			else
			  {
			  	FOR(i,it2->second)
			  		cout<<it2->first<<" ";
			  }
		}
	}
	tr(b,it2)
	{
		if(a.find(it2->first)==a.end())
		{
			FOR(i,it2->second)
				cout<<it2->first<<" ";//printing the left out elements of the b multiset
		}
	}
}
void intersect(map<string,int> a, map<string,int> b)
{	cout<<"\nIntersection of sets is:";
	int flag=0;
	tr(a,it1)
	{		if(b.find(it1->first)!=b.end())
			{	flag=1;
			map<string,int>::iterator it2=b.find(it1->first);
			if(it1->second<=it2->second)
				{
					FOR(i,it1->second)
						cout<<it1->first<<" ";// printing common elements
				}
			else
			  {
			  	FOR(i,it2->second)
			  		cout<<it2->first<<" ";
			  }
		}
	
	}
	if(flag==0)
		cout<<"\nNULL SET.";
}
int main()
{	vector < string > set1,set2;
	map <string,int> m1,m2;
	int n1,n2,ch;
	string ele;
	cout<<"************************************************************************************************************************";
	cout<<"\t\t\t\t\t\tOPERATIONS ON MULTI-SETS.\n************************************************************************************************************************";
	cout<<"\nEnter size of MULTISET1:";
	cin>>n1;
	cout<<"\nEnter elements:";
	FOR(i,n1)
	{	cin>>ele;
		set1.push_back(ele);
		m1[ele]+=1;
	}
	cout<<"\nEnter size of MULTISET2:";
	cin>>n2;
	cout<<"\nEnter elements:";
	FOR(i,n2)
	{	cin>>ele;
		set2.push_back(ele);
		m2[ele]+=1;
	}
	cout<<"\nMULTISET 1:";
	tr(set1,it)
		cout<<*it<<",";
	cout<<"\nMULTISET 2:";
	tr(set2,it)
		cout<<*it<<",";
	cout<<"\nOperations...";
	cout<<"\nADDITION-1 , DIFFERENCE-2 , UNION-3 , INTERSECTION-4 ";
	while(true)
	{cout<<"\nEnter the choice (-1 for exit):";
	cin>>ch;
	if(ch==-1)
		break;
	switch(ch)
	{
		case 1:{ add(m1,m2);
				 break;
				}
		case 2:{cout<<"\n Press 1 for SET1-SET2\n Press 2 for SET2-SET1";
				x:cout<<"\nEnter choice:";
				int choice;
				cin>>choice;
				if(choice==1) subtract(m1,m2);
				else if (choice==2) subtract(m2,m1);				
				else 
				{ cout<<"\nWrong choice.\nEnter again.";
					goto x;
					}	
				break;
				}
		case 3:{
				Union(m1,m2);
				break;
		    	}
		case 4:{
				intersect(m1,m2);
				break;
				}
		default:cout<<"\nWrong choice.\nEnter again." ;
				break;
		
	}
				
	}
	return 0;
}

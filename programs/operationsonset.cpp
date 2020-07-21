#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FOR(i,n) for(int i=0;i!=n;i++)
using namespace std;
void add(set<int> a, set<int> b)
{	set<int> set3;	
cout<<"\nAddition is:";
	tr(a,it1)
	{
		tr(b,it2)
		{ 	 
			set3.insert(*it1+*it2);
		}
	}
	tr(set3,it)
		cout<<*it<<",";
}
void subtract(set<int> a,set<int>b)
{
	cout<<"\nThe difference of sets is:";
	tr(a,it1)
	{ if(b.find(*it1)==b.end())
		cout<<*it1<<",";
	else 	
		continue;
	}
}
void Union(set<int> a, set<int> b)
{
	cout<<"\nThe union is:";
	tr(a,it)
		cout<<*it<<",";
	tr(b,it)
		{
			if(a.find(*it)==a.end())
				cout<<*it<<",";
			else 
				continue;
		}
}
void intersect(set<int> a, set<int> b)
{	cout<<"\nIntersection of sets is:";
	int flag=0;
	tr(a,it)
	{
		if(b.find(*it)!=b.end())
			{
			cout<<*it<<",";
			flag=1;}
	}
	if(flag==0)
		cout<<"\nNULL SET.";
}
void symmetric(set<int> a,set<int> b)
{	cout<<"\nSymmetric dfifference of sets is:";
	tr(a,it)
	{
		if(b.find(*it)!=b.end())
			continue;
		else
			cout<<*it<<",";
	}
	tr(b,it)
	{
		if(a.find(*it)!=a.end())
			continue;
		else
			cout<<*it<<",";
	}
}
int main()
{	set < int > set1,set2;
	int n1,n2,ele,ch;
	cout<<"************************************************************************************************************************";
	cout<<"\n\t\t\t\t\t\tOPERATIONS ON SETS.\n************************************************************************************************************************";
	cout<<"\nEnter size of SET1:";
	cin>>n1;
	cout<<"\nEnter elements:";
	FOR(i,n1)
	{	cin>>ele;
		set1.insert(ele);
	}
	cout<<"\nEnter size of SET2:";
	cin>>n2;
	cout<<"\nEnter elements:";
	FOR(i,n2)
	{	cin>>ele;
		set2.insert(ele);
	}
	cout<<"SET 1:";
	tr(set1,it)
		cout<<*it<<",";
	cout<<"\nSET 2:";
	tr(set2,it)
		cout<<*it<<",";
	cout<<"\nOperations...";
	cout<<"\nADDITION-1 , DIFFERENCE-2 , UNION-3 , INTERSECTION-4 ,SYMMETRIC DIFFERENCE-5 ";
	while(true)
	{cout<<"\nEnter the choice (-1 for exit):";
	cin>>ch;
	if(ch==-1)
		break;
	switch(ch)
	{
		case 1:{ add(set1,set2);
				 break;
				}
		case 2:{cout<<"\n Press 1 for SET1-SET2\n Press 2 for SET2-SET1";
				x:cout<<"\nEnter choice:";
				int choice;
				cin>>choice;
				if(choice==1) subtract(set1,set2);
				else if (choice==2) subtract(set2,set1);				
				else 
				{ cout<<"\nWrong choice.\nEnter again.";
					goto x;
					}	
				break;
				}
		case 3:{
				Union(set1,set2);
				break;
		    	}
		case 4:{
				intersect(set1,set2);
				break;
				}
		case 5:{ symmetric(set1,set2);
				break;
				}
		default:cout<<"\nWrong choice.\nEnter again." ;
				break;
		
	}
				
	}
	return 0;
}

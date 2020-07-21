#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it = v.begin();it!=v.end();it++)
#define FOR(i,n) for(int i=0;i<n;i+=1)
using namespace std;
set <string> intersect (set <string> a, set<string> b)
{	set<string> ITRS;
	tr(a,it)
	{
		if(b.find(*it)!=b.end())
			ITRS.insert(*it);
	}
	return ITRS;
}
set <string> Union (set<string> a,set<string> b)
{	set<string> U(a.begin(),a.end());
	tr(b,it)
	{
		if(a.find(*it)==a.end())
			U.insert(*it);
	}
	return U;
	
} 
int main()
{
	cout<<"\n\t\t\t\tPRINCIPLE OF INCLUSION AND EXCLUSION FOR THREE SETS...";
	cout<<"\nEnter the elements of sets...";
	set <string> s1,s2,s3;
	string ele;
	int i=1;
	cout<<"\nSET 1(-1 for exit)\n";
	while(true)
	{	cout<<"Element "<<i<<":";
		cin>>ele;
		if(ele=="-1") break;
		s1.insert(ele);
		i+=1;
	}
	i=1;
	cout<<"\nSET 2(-1 for exit)\n";
	while(true)
	{	cout<<"Element "<<i<<":";
		cin>>ele;
		if(ele=="-1") break;
		s2.insert(ele);
		i+=1;
	}
	i=1;
	cout<<"\nSET 3(-1 for exit)\n";
	while(true)
	{	cout<<"Element "<<i<<":";
		cin>>ele;
		if(ele=="-1") break;
		s3.insert(ele);
		i+=1;
	}
	cout<<"\nThe sets are -\n";
	cout<<"SET1 :";
	tr(s1,it) cout<<*it<<" ";
	cout<<"\nSET2 :";
	tr(s2,it) cout<<*it<<" ";
	cout<<"\nSET3 :";
	tr(s3,it) cout<<*it<<" ";
	cout<<"\nThe principle of inclusion exclusion states that the union of three sets is given by the formula -\n";
	cout<<"S1 U S2 U S3 = S1 + S2 + S3 - S1^S2 - S2^S3 - S2^S3 +S1^S2^S3\n\t\t\t\t\t\t where U denoted the union and ^ denotes the intersection.";
	cout<<"\nThe formula is true for the cardinalities of the sets S1,S2,S3 also.";
	int cardinality= s1.size()+s2.size()+s3.size()- intersect(s1,s2).size()-intersect(s2,s3).size()-intersect(s1,s3).size() + intersect(intersect(s1,s2),s3).size();
	cout<<"\nThe resulting cardinality of the set (S1 U S2 U S3) is: "<<cardinality;
	cout<<"\nThe result of your union is :";
	set<string> s4= Union(Union(s1,s2),s3);
	tr(s4,it)
	{
		cout<<*it<<" ";
	}
	return 0;
}

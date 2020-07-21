#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it= v.begin();it!=v.end();it++)
using namespace std;
float discri;
int main()
{	int k;
	cout<<"\nProgran to solve the linear recurrence relation of order 2.";
	float arr[3];
	for(int i=2;i>=0;i--)
	{	if(i==2)
		{
		cout<<"\nEnter the coefficient of the (r)th term:";
		cin>>arr[2];}
		else 
		{
		  cout<<"Enter the coefficient of the (r-"<<2-i<<")th term:";
		  cin>>arr[i];
		}
	}
	vector<float> Coef(arr,arr+3);
	cout<<"\nThe recurrence relation is:";
	int i=2;
	tr(Coef,it)
		{
			if(i!=0)
			cout<<"("<<*it<<"*A(r-"<<i<<")) + ";
			else
			cout<<"("<<*it<<"*A(r))";
			i-=1;
		}
	cout<<"\n The characteristic equation is:\n";
	int j=0;
	tr(Coef,it)
	{
		if(j==0)
			cout<<*it<<" +";
		else
		{	if(j!=1)
			{if(j!=2)
			cout<<"("<<*it<<"*M^"<<j<<") +";
			else
			cout<<"("<<*it<<"*M^"<<j<<") ";
		    }
			else 
			cout<<"("<<*it<<"*M"<<") +";
        	
		}
		j+=1;
	}
	//arr[0] is my c arr[2] is my a
	vector< pair < float,float> > roots;
	
	discri=arr[1]*arr[1]-4*arr[0]*arr[2];
	if(discri>0)
	{
		roots.push_back(make_pair(((-arr[1]+sqrt(discri))/(2*arr[2])),0));
		roots.push_back(make_pair(((-arr[1]-sqrt(discri))/(2*arr[2])),0));
	
	}
	else if(discri<0)
	{
		roots.push_back(make_pair((-arr[1]/(2*arr[2])),-(sqrt(-discri)/(2*arr[2]))));
		roots.push_back(make_pair((-arr[1]/(2*arr[2])),sqrt(-discri)/(2*arr[2])));
		
	}
	else
	{
		roots.push_back(make_pair((-arr[1]/(2*arr[2])),0));
		roots.push_back(make_pair((-arr[1]/(2*arr[2])),0));
	
	}
	cout<<"\nThe roots are:";

		if(discri==0)
		{
			cout<<"\nThe roots are repeated-"<<roots[0].first<<","<<roots[0].first;
			cout<<"\nThe homogeneous solution is: \n A(r)=(C1*r + C2)*("<<roots[0].first<<")^r";

		}
		else 
		{
			if(discri>0)
			{
				cout<<"\nRoot 1 is-  "<<roots[0].first;
				cout<<"\nRoot 2 is-  "<<roots[1].first;
				cout<<"\nThe homogeneous solution is: C1*("<<roots[0].first<<")^r + C2*("<<roots[1].first<<")^r";
				
			}
			else
			{
				cout<<"\nRoot 1 is-  "<<roots[0].first<<" + ("<<roots[0].second<<")*i ";
				cout<<"\nRoot 2 is-  "<<roots[1].first<<" + ("<<roots[1].second<<")*i ";
				cout<<"\nThe homogeneous solution is: C1*("<<roots[0].first<<" + ("<<roots[0].second<<")*i"<<")^r + C2*("<<roots[1].first<<" + ("<<roots[1].second<<")*i )"<<")^r";
				
				
			}
		}
		// to completely solve recurrence
	if(discri>=0)
	{
	cout<<"\nEnter two consecutive values to completely solve this recurrence relation:";
	u:cout<<"\nEnter the index of one - ";
	pair<int, int > indices;
	cin>>indices.first;
	cout<<"Enter the index of two - ";
	cin>>indices.second;
	if(indices.second-indices.first!=1)
		{cout<<"\nInvaid values.\nEnter again.";
		goto u;}
	else
	{	float a1,a2;
		cout<<"\nEnter value of A"<<indices.first<<" :";
		cin>>a1;
		cout<<"Enter value of A"<<indices.second<<" :";
		cin>>a2;
		if(discri>0)
		{
			float c1,c2;
			c1=(a2-(roots[1].first)*a1)/(pow(roots[0].first,indices.second)-pow(roots[0].first,indices.first)*roots[1].first);
			c2=(a2-(roots[0].first)*a1)/(pow(roots[1].first,indices.second)-pow(roots[1].first,indices.first)*roots[0].first);
			cout<<"\nThe homogeneous solution is: A(r)="<<c1<<"*("<<roots[0].first<<")^r + "<<c2<<"*("<<roots[1].first<<")^r";
				
		}
		else if(discri==0)
		{
			float c1,c2;
			c1=(roots[0].first*a1-a2)/(pow(roots[0].first,indices.second));
			c2=((roots[0].first*a1*(1-indices.first))+a2*indices.first)/(pow(roots[0].first,indices.second));
			cout<<"\nThe homogeneous solution is: \n A(r)=("<<c1<<"*r + "<<c2<<")*("<<roots[0].first<<")^r";

		}
	}	
}
	return 0;
	
}








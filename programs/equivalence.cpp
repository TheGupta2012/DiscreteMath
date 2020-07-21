#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
bool TR( int A,int B, int Relate[][100],int dCount,int distinct[]);
bool transitive(int Square[100][100], int Relate[100][100], int n)
{
	for(int i=0;i<n;i+=1)
	{
		for(int j=0;j<n;j+=1)
		{
			if(Square[i][j]>=1 && Relate[i][j]==0)
				return false;
		}
	}
	return true;
}
bool symmetric(int Relate[100][100], int n)
{
	for(int i=0;i<n;i+=1)
	{
		for(int j=i+1;j<n;j+=1)
		{
			if(Relate[i][j]!=Relate[j][i])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{	int n;
	cout<<"\nTO CHECK FOR EQUIVALENCE OF THE GIVEN BINARY RELATION.";
	cout<<"\nEnter the number of elements :";
	cin>>n;
	string ele;
	vector <string> V;
	map <int, int> m;
	int distinct[n];//to send as a parameter.
	cout<<"\nEnter the name of elements:\n";
	for(int i=0;i<n;i++)
	{	cout<<"Element "<<i+1<<":";
		cin>>ele;
		V.push_back(ele);
		m[i]=0;// making map with index
	} 
	cout<<"\nYour elements are:\n";
	tr(V,it)
	{cout<<it-V.begin()<<":"<<*it<<endl;
	}
	cout<<"\nEnter the element pairs:";
	int Relate[100][100];
	int copy[100][100];
	for(int q=0;q<n;q++)
	{	for(int w=0;w<n;w++)
		  Relate[q][w]=copy[q][w]=0;
		 
	}
	string v1,v2;
	int count=0;
	int i,j;
	while(true)
	{	if(count==n*n)
	  		{cout<<"Max element pairs reached.";
	  		break;}
		s:cout<<"\nName of E1:";
		cin>>v1;
		cout<<"Name of E2:";
		cin>>v2;
		i=find(V.begin(),V.end(),v1)-V.begin();
		j=find(V.begin(),V.end(),v2)-V.begin();
		if (i==n || j==n)
			{cout<<"\nNo such vertex pair exists.\nEnter again.";
			goto s;}
		count+=1;
		m[i]+=1;
		m[j]+=1;
		Relate[i][j]=1;
		copy[i][j]=1;
		cout<<"\nEnter 1 for more pairs or -1 for exit:";
		int ch1;
		cin>>ch1;
		if(ch1==-1) break;	
	}
	cout<<"\nThe Relation matrix is:\n";
	for(int f=0;f<n;f++)
	{    for(int g=0;g<n;g++)
			{cout<<Relate[f][g]<<" ";}
		cout<<endl;
	}
	int dCount=0;
	tr(m,it)
	{ if(it->second!=0)
			{ distinct[i]=it->first;
			  dCount+=1;}
	}
	int flag=0;
	cout<<"\nCHECKING FOR EQUIVALENCE OF THE RELATION...\n";
	if(TR(n,n,Relate,dCount,distinct)==false) 
	{flag=1;
	cout<<"\nRelation is not Reflexive.";}
	if(symmetric(Relate,n) == false)
	{ flag+=1;
	  cout<<"\nRelation is not Symmetric.";
    }
    int elem;
	for (int i=0;i<n;i+=1) // calculating the square of the matrix...
			{	for(int j=0;j<n;j+=1)
				{ elem=0;
					for(int k=0;k<n;k+=1)
					{ elem+=copy[i][k]*copy[k][j];
					}
					Relate[i][j]=elem;
				}
			}
	if(transitive(Relate,copy,n)==false)
	{ flag+=1;
	  cout<<"\nRelation is not Transitive.";}
	if(flag==0)
		cout<<"\nYOUR RELATION IS AN EQUIVALENCE RELATION!";
	return 0;
}
bool TR ( int A, int B, int Relate[][100],int dCount,int distinct[])
{
	int trace=0;
	for(int i=0;i<dCount;i+=1)
	{
		if(Relate[i][i]!=1)
			return false;
	}
	return true;
}

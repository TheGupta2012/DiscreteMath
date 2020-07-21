#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
void copied(int (&ADMnew)[100][100], int (&ADM)[100][100], int len);
int TR( int A,int B, int ADM[][100]);
bool path(int i,int j, int ADM[100][100], int n)
{	queue <int> Q;
	Q.push(i);
	bool visited[n]={false};
	visited[i]=true;
	while(visited[j]!=true && !Q.empty())
	{
		int current= Q.front();
		for(int m=0;m<n;m+=1)
		{
			if(ADM[current][m]==1) 
			{    Q.push(m);
				 visited[m]=true;
			}	 
		}
		Q.pop();
	}
	return (visited[j]);
}
int main()
{	ios::sync_with_stdio(false);
	//making graphs->
	cout<<"\nGRAPHS...\nImplementing paths and cycles...";
	
	cout<<"\nEnter the no. of vertices:";
	int n;
	cin>>n;
	string ele;
	vector <string> V;
	cout<<"\nEnter the name of node:\n";
	for(int i=0;i<n;i++)
	{	cout<<"Vertex "<<i+1<<":";
		cin>>ele;
		V.push_back(ele);
	} 
	cout<<"\nYour vertices are:\n";
	tr(V,it)
	{cout<<it-V.begin()<<":"<<*it<<endl;
	}
	char type;
	y:cout<<"\nEnter D for directed graph and U for undirected graph:";
	cin>>type;
	if( type!='D' && type!='U' ) 
		{cout<<"Invalid.\nEnter again.";
		goto y;}
	cout<<"\nEnter the relation between the vertices:";
	int ADM[100][100];
	int copy[100][100];
	for(int q=0;q<n;q++)
	{	for(int w=0;w<n;w++)
		  ADM[q][w]=copy[q][w]=0;
		 
	}
	string v1,v2;
	int count=0;
	int i,j;
	while(true)
	{	if((type=='U' && count==n*(n-1)/2) ||(type=='D' && count==(n)*(n-1)))
	  		{cout<<"Max edges are reached.";
	  		break;}
		s:cout<<"\nName of V1:";
		cin>>v1;
		cout<<"Name of V2:";
		cin>>v2;
		count+=1;
		i=find(V.begin(),V.end(),v1)-V.begin();
		j=find(V.begin(),V.end(),v2)-V.begin();
		if (i==n || j==n)
			{cout<<"\nNo such vertex pair exists.\nEnter again.";
			goto s;}
		ADM[i][j]=1;
		copy[i][j]=1;
		if(type=='U') 
			{ADM[j][i]=1;
			copy[j][i]=1;}
		cout<<"\nEnter 1 for more edges or -1 for exit:";
		int ch1;
		cin>>ch1;
		if(ch1==-1) break;	
	}
	cout<<"\nThe adjacency matrix is:\n";
	for(int f=0;f<n;f++)
	{    for(int g=0;g<n;g++)
			{cout<<ADM[f][g]<<" ";}
		cout<<endl;
	}
	cout<<"\nFINDING PATHS AND CYCLES-\n	1. TO FIND PATH BETWEEN TWO VERTICES\n	2. TO FIND NO. OF CYCLES\n";
	p:cout<<"Enter choice:";
	int ch2;
	cin>>ch2;
	if(ch2!=1 && ch2!=2)
		{cout<<"\nInvalid choice.Enter again.";
		goto p;
		 } 
	if(ch2==1)
	{	
		v:cout<<"\nEnter the start vertex V1:";
		cin>>v1;
		cout<<"\nEnter the end vertex V2:";
		cin>>v2;
		i=find(V.begin(),V.end(),v1)-V.begin();
		j=find(V.begin(),V.end(),v2)-V.begin();
		if (i==n || j==n)
			{cout<<"\nNo such vertex pair exists.\nEnter again.";
			goto v;}
		if(path(i,j,ADM,n)==true)
			cout<<"\nPath exists.";
		else 
			cout<<"\nPath not found.";
	}
	if(ch2==2)
	{	
		if(n==1 || n==2)
			cout<<"\nNumber of vertices-"<<n<<".\nCycles not possible.\n";
		else
		{cout<<"\nFINDING OUT CYCLES:";
		int elem;
		for (int i=0;i<n;i+=1) // calculating the square of the matrix...
			{	for(int j=0;j<n;j+=1)
				{ elem=0;
					for(int k=0;k<n;k+=1)
					{ elem+=copy[i][k]*copy[k][j];
					}
					ADM[i][j]=elem;
				}
			}	
		for(int m=3;m<=n;m++)
		{	int ADMnew[100][100]={0};
		for (int i=0;i<n;i+=1)
			{	for(int j=0;j<n;j+=1)
				{	int elem=0;
					for(int k=0;k<n;k+=1)
					{ ADMnew[i][j]+=ADM[i][k]*copy[k][j];
					}
				}
			}
		cout<<"\nNo. of cycles of length "<<m<<" are:";
		int trace=TR(n,n,ADMnew);
		if(type=='U')	cout<<(trace/(2*m));
		else 	cout<<trace;
		copied(ADMnew,ADM,n);
		
	}
}
}
	return 0;
}
void copied(int (&ADMnew)[100][100], int (&ADM)[100][100], int len)
{
	for(int i=0;i<len;i+=1)
	{
		for(int j=0;j<len;j+=1)
			ADM[i][j]=ADMnew[i][j];
	}
}
int TR ( int A, int B, int ADM[][100])
{
	int trace=0;
	for(int i=0;i<A;i+=1)
	{
		for(int j=0;j<B;j+=1)
		{if(i==j) trace+=ADM[i][j];
	}
	}
	return trace;
}

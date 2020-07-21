#include<bits/stdc++.h>
using namespace std;
int dp[7][6];
int identities[6];
void func()
{
for(int i=0;i<7;i++)
{
for(int j=6;j<6;j++)
dp[i][j]=0;
}
dp[2][0]=1;
dp[3][0]=1;
dp[5][0]=1;
dp[7][0]=1;
identities[0]=0;
identities[1]=1;
identities[2]=-1;
identities[3]=0;
identities[4]=-1;
identities[5]=1;
}

bool check(int preset, int op)
{
if(op!=1){
//cout&lt;&lt;&quot;Not a Group&quot;;
return false;
}
if(preset==3||preset==4||preset==6||preset==7){
//cout&lt;&lt;&quot;A group&quot;;
return true;
}
return false;
}
bool check(vector<float> set, int op)
{
if(op==1)
{
if(find(set.begin(),set.end(),0)==set.end())
{
cout<<"Identity Element '0' not present for operator 1\n";

return false;
}
for(int i=0;i<set.size();i++)
{
for(int j=i+1;j<set.size();j++)
{
if(find(set.begin(),set.end(),(set[i]+set[j]))==set.end())
{
cout<<"Result of "<<set[i]<<" and "<<set[j]<<" doesn't exist for operator 1.\n";
return false;
}
}
}
for(int i=0;i<set.size();i++)
{
if(find(set.begin(),set.end(),(-1*(set[i])))==set.end())
{
cout<<"Inverse of"<<set[i]<<" doesn't exist for operator 1\n";
return false;
}
}
cout<<"A group\n";
return true;
}
if(op==2)
{

if(find(set.begin(),set.end(),1)==set.end())
{
cout<<"Identity element '1' doesn't exist for operator 1\n";
return false;
}
for(int i=0;i<set.size();i++)
{
for(int j=i+1;j<set.size();j++)
{
if(find(set.begin(),set.end(),(set[i]*set[j]))==set.end())
{
cout<<"Result of "<<set[i]<<" and "<<set[j]<<" doesn't exist for operator 1\n";
return false;
}
}
}
for(int i=0;i<set.size();i++)
{
if(find(set.begin(),set.end(),(1/set[i]))==set.end())
{
cout<<"The inverse of "<<set[i]<<" doesn't exist for operator 1\n";
return false;
}
}
}
//cout<<"The operator is not associative\nNot a group&quot;;

return false;
}
//1. N 2. W 3. Z 4.EN 5.ON 6.Real 7.CUSTOM
//1. + 2. * 3. - 4. / 5. % 6. ^
bool semigroupPre(int PDset, int op2)
{	// only checking for predefined sets.
	if(op2==3 || op2==4 || op2==5 || op2==6)
		return false; // not associative
	else
	{ 	// + and * are associative.
		if(op2==1)
		{
			if(PDset==5)	return false; // odd numbers under addition are not closed.
			else return true;	
		}
		else
		{
			return true;
		}
	}
}
bool semigroupUser(vector<float> UDset, int op2)
{
	if(op2==3 || op2==4 || op2==5 || op2==6)
		return false; // not associative
	else
	{
		if(op2==1)
		{
			for(int i=0;i<UDset.size()-1;i+=1)
			{
				for(int j=i+1;j<UDset.size();j+=1)
				{
					if(find(UDset.begin(),UDset.end(),UDset[i]+UDset[j])==UDset.end())
						{ cout<<"The result of"<<UDset[i]<<" and "<<UDset[j]<<" doesn't exist for operator 2.";
						  cout<<"\nHence set is not closed.";
					      return false;
						} // set is not closed under addition as result is not found.
				}
			}
			return true;
		}
		if(op2==2)
		{	for(int i=0;i<UDset.size()-1;i+=1)
			{
				for(int j=i+1;j<UDset.size();j+=1)
				{
					if(find(UDset.begin(),UDset.end(),UDset[i]*UDset[j])==UDset.end())
						{ cout<<"The result of"<<UDset[i]<<" and "<<UDset[j]<<" doesn't exist for operator 2.";
						  cout<<"\nHence set is not closed.";
						return false;
						} // set is not closed under multiplication as result is not found.
				}
			}
			return true;	
		}
	}
}
bool abelian(int op1)
{
	if(op1==1 || op1==2) return true;
	else return false;
}
bool distribute(int op1,int op2)
{
	if (op1==op2)	return false; //same operators don't distribute over themselves.
	else
	{if(op2==2 && op1==1) return true;
	 else return false;
	}
}
int main()
{	int setno,op1,op2;
	vector<float> UDset;
	float ele;
	cout<<"\nPROGRAM TO FIND IF THE GIVEN SET AND THE OPERATIONS FORM A RING OR NOT.";
	cout<<"\nCHOOSE SET->\n ";
	cout<<"\n1. Natural Numbers\n2. Whole Numbers\n3. Integers\n4. EvenNumbers\n5. Odd numbers\n6. Real numbers\n7.CUSTOM SET(input by user)";
	cin>>setno;
	if(setno==7)
	{ cout<<"Enter the elements in the set (end by -1) -> ";
		while(true)
		{cin>>ele;
		 if(ele==-1) break;
		 UDset.push_back(ele);
		}
	}
	cout<<"**********************************************************"<<endl<<endl;
	cout<<"1. +(addition)\n2. *(multiplication)\n3. -(subtraction)\n4. /(division)\n5. %(modulous)\n6. ^(power)";
	cout<<"Enter the two operators->> \nOPERATOR 1:";
	cin>>op1;
	cout<<"\nOPERATOR 2:";
	cin>>op2;
	if(setno<7)
	{
		if(check(setno,op1) && abelian(op1) && semigroupPre(setno,op2) && distribute(op1,op2))
			cout<<"\nThe selected set and the operators form a RING.";
		else
			cout<<"\nThe selected set and the operators don't form a RING.";
	}
	else
	{
		if(check(UDset,op1) && abelian(op1) && semigroupUser(UDset,op2) && distribute(op1,op2))
			cout<<"\nThe input set and the operators form a RING.";
		else
			cout<<"\nThe input set and the operators don't form a RING.";
	}
	return 0;
}




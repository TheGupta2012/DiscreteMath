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
cout<<"Identity Element '0' not present";

return false;
}
for(int i=0;i<set.size();i++)
{
for(int j=i+1;j<set.size();j++)
{
if(find(set.begin(),set.end(),(set[i]+set[j]))==set.end())
{
cout<<"Result of "<<set[i]<<" and "<<set[j]<<"doesn't exist.";
return false;
}
}
}
for(int i=0;i<set.size();i++)
{
if(find(set.begin(),set.end(),(-1*(set[i])))==set.end())
{
cout<<"Inverse of"<<set[i]<<" doesn't exist";
return false;
}
}
cout<<"A group";
return true;
}
if(op==2)
{

if(find(set.begin(),set.end(),1)==set.end())
{
cout<<"Identity element '1' doesn't exist";
return false;
}
for(int i=0;i<set.size();i++)
{
for(int j=i+1;j<set.size();j++)
{
if(find(set.begin(),set.end(),(set[i]*set[j]))==set.end())
{
cout<<"Result of "<<set[i]<<" and "<<set[j]<<" doesn't exist";
return false;
}
}
}
for(int i=0;i<set.size();i++)
{
if(find(set.begin(),set.end(),(1/set[i]))==set.end())
{
cout<<"The inverse of "<<set[i]<<" doesn't exist";
return false;
}
}
}
//cout<<"The operator is not associative\nNot a group&quot;;

return false;
}
int main()
{
vector<float> set;

cout<<"\n1. Natural Numbers\n2. Whole Numbers\n3. Integers\n4. EvenNumbers\n5. Odd numbers\n6. Real numbers\n7. Matrix\n8.CUSTOM SET(input by user)";
int preset;
cout<<endl;
cout<<endl;
cout<<"**********************************************************"<<endl<<endl;
cout<<"1. +(addition)\n2. *(multiplication)\n3. -(subtraction)\n4. /(division)\n5. %(modulous)\n6. ^(power)";
int op;
cout<<endl<<endl;
while(1)
{
cout<<"Enter the choice of set->";
cin>>preset;
if(preset==8)
{
float data;
cout<<"Enter the elements in the set (end by -1) -> ";
while(data!=-1){

cin>>data;
set.push_back(data);
}
}
cout<<"Enter the choice of operator->> ";
cin>>op;

if(preset==8)
{
bool val=check(set,op);
if(val)
{
cout<<"\nA GROUP";
}
else
cout<<"\nNOT A GROUP";
}
else
{
bool val=check(preset,op);
if(val)
cout<<"A GROUP";
else
cout<<"NOT A GROUP";
}
cout<<endl;

int choice;
cout<<"1. Test Another Pair\n2. Exit\nEnter choice";
cin>>choice;
if(choice!=1)
break;
}
return 0;
}


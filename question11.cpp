#include<iostream>
using namespace std;
int identity;
bool linearSearch(int*a,int n,int key)
{
  for(int i=0;i<n;i++)
  {
    if(a[i]==key)
    {
      return true;
    }
  }
  return false;
}
int operation(int p,int q,char ch)
{
  switch (ch)
  {
    case '+': return p+q;
    break;
    case '*': return p*q;
    break;
    case '-': return p-q;
    break;
    default: return p/q;
  }
}
bool isClosure(int*s,int n,char ch)
{
  int result=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      result=operation(s[i],s[j],ch);
      if(!linearSearch(s,n,result)) return false;
    }
  }
  return true;
}
bool isAssociative(int*s,int n,char ch)
{
  for(int i=0;i<n-2;i++)
  {
    for(int j=i+1;j<n-1;j++)
    {
      for(int k=j+1;k<n;k++)
      {
        if(operation(operation(s[i],s[j],ch),s[k],ch)!=operation(operation(s[j],s[k],ch),s[i],ch))
        {
          return false;
        }
      }
    }
  }
  return true;
}
bool isIdentity(int*s,int n,char ch)
{
  int j;
  for(int i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(operation(s[i],s[j],ch)!=s[j])
      {
        break;
      }
    }
    if(j==n)
    {
      identity=s[i];
      return true;
    }
  }
  return false;
}
bool isInverse(int*s,int n,char ch)
{
  int j;
  for(int i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(operation(s[i],s[j],ch)==identity)
      {
        break;
      }
    }
    if(j==n) return false;
  }
  return true;
}
bool isGroup(int*s,int n,char ch)
{
  if(isClosure(s,n,ch)&&isAssociative(s,n,ch)&&isIdentity(s,n,ch)&&isInverse(s,n,ch)) return true;
  else return false;
}
bool isCommutative(int*s,int n,char ch)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(operation(s[i],s[j],ch)!=operation(s[j],s[i],ch))
      {
        return false;
      }
    }
  }
  return true;
}
bool isDistributive(int*s,int n,char ch1,char ch2)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      for(int k=j+1;k<n;k++)
      {
        if(operation(s[i],operation(s[j],s[k],ch1),ch2)!=operation(operation(s[i],s[j],ch2),operation(s[i],s[k],ch2),ch1))
        {
          return false;
        }
      }
    }
  }
  return true;
}
bool isRing(int*s,int n,char ch1,char ch2)
{
  if(isGroup(s,n,ch1)&&isCommutative(s,n,ch1)&&isClosure(s,n,ch2)&&isAssociative(s,n,ch2)&&isDistributive(s,n,ch1,ch2)) return true;
  else return false;

}
int main()
{
  int n;char ch1,ch2;
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter the number of elements in the set:\n";
  cin>>n;
  cout<<"Enter the elements of the set:\n";
  int s[1000];
  for(int i=0;i<n;i++)
  {
    cin>>s[i];
  }
  cout<<"Enter the first binary operation:\n";
  cin>>ch1;
  cout<<"Enter the second binary operation:\n";
  cin>>ch2;
  if(isRing(s,n,ch1,ch2)) cout<<"It's a ring!"<<endl;
  else cout<<"It's not a ring!";
  return 0;
}

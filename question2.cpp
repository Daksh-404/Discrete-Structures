#include<iostream>
using namespace std;
typedef pair<int,int>p;
void print(p*a,int n)
{
  for(int i=0;i<n;i++)
  {
    if(a[i].second>0)
    {
      for(int j=0;j<a[i].second;j++)
      {
        cout<<a[i].first<<" ";
      }
    }
  }
  cout<<endl;
}
void shiftForward(p*a,int n,int i)
{
  //for shifting the elemets back to
  //delete an element
  for(int j=n;j>i;j--)
  {
    a[j].first=a[j-1].first;
    a[j].second=a[j-1].second;
  }
}
int additionSet(p*a1,p*a2,int n1,int n2,p*add)
{
  for(int i=0;i<n1;i++)
  {
    add[i].first=a1[i].first;
    add[i].second=a1[i].second+a2[i].second;
  }
}
int subtractionSet(p*a1,p*a2,int n1,int n2,p*sub)
{
  for(int i=0;i<n1;i++)
  {
    sub[i].first=a1[i].first;
    sub[i].second=a1[i].second-a2[i].second;
  }
}
int unionSetReturn(p*a1,p*a2,int n1,int n2,p*u)
{
  for(int i=0;i<n1;i++)
  {
    if(a1[i].second>=a2[i].second)
    {
      u[i].first=a1[i].first;
      u[i].second=a1[i].second;
    }
    else
    {
      u[i].first=a2[i].first;
      u[i].second=a2[i].second;
    }
  }
}
int intersectionSetArrayChangeReturn(p*a1,p*a2,p*intersection,int n1,int n2)
{
  for(int i=0;i<n1;i++)
  {
    if(a1[i].second>=a2[i].second)
    {
      intersection[i].first=a2[i].first;
      intersection[i].second=a2[i].second;
    }
    else
    {
      intersection[i].first=a1[i].first;
      intersection[i].second=a1[i].second;
    }
  }
}
void correctingOrder(p*a1,p*a2,int n1,int n2)
{
  int i,j;
  for(i=0,j=0;i<n1&&j<n2;i++,j++)
  {
    if(a1[i].first!=a2[j].first)
    {
      shiftForward(a2,n2,j);
      n2++;
      a2[j].first=a1[i].first;
      a2[j].second=0;
    }
  }
  if(n1>n2)
  {
    while(i<n1)
    {
      a2[j].first=a1[i].first;
      a2[j].second=0;
      i++;j++;
      n2++;
    }
  }
  else if(n2>n1)
  {
    while(j<n2)
    {
      a1[i].first=a2[j].first;
      a1[i].second=0;
      i++;j++;
      n1++;
    }
  }
  p add[10000];p sub[10000];
  p u[10000];p intersection[10000];
  int n=n1;
  additionSet(a1,a2,n1,n2,add);
  cout<<"Addition: ";print(add,n);
  subtractionSet(a1,a2,n1,n2,sub);
  cout<<"Subtraction: ";print(sub,n);
  unionSetReturn(a1,a2,n1,n2,u);
  cout<<"Union: ";print(u,n);
  intersectionSetArrayChangeReturn(a1,a2,intersection,n1,n2);
  cout<<"Intersection: ";print(intersection,n);
}
int main()
{
  int n1,n2;
  p a1[10000];p a2[10000];
  cout<<"Enter the number of elements of set 1:\n";
  cin>>n1;
  cout<<"Enter the elemets of set 1:\n";
  int x;
  cin>>x;
  int prev=x;
  int index=0;
  a1[0].first=x;a1[0].second=1;
  for(int i=1;i<n1;i++)
  {
    cin>>x;
    if(prev!=x)
    {
      index++;
      a1[index].first=x;a1[index].second=1;
      prev=x;
    }
    else
    {
      a1[index].second+=1;
    }
  }
  n1=index+1;
  cout<<"Enter the number of elements of set 2:\n";
  cin>>n2;
  //if(n1==0&&n2==0) cout<<"No Possible Operation\n";
  cout<<"Enter the elemets of set 2:\n";
  cin>>x;index=0;prev=x;
  a2[0].first=x;a2[0].second=1;
  for(int i=1;i<n2;i++)
  {
    cin>>x;
    if(prev!=x)
    {
      index++;
      a2[index].first=x;a2[index].second=1;
      prev=x;
    }
    else
    {
      a2[index].second+=1;
    }
  }
  n2=index+1;
  correctingOrder(a1,a2,n1,n2);
  return 0;
}

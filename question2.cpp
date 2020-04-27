#include<iostream>
using namespace std;
typedef pair<int,int>p;
void print(p*a,int n)
{
  int count=0;
    for(int i=0;i<n;i++)
    {
      if(a[i].second>0)
      {
        for(int j=0;j<a[i].second;j++)
        {
          cout<<a[i].first<<" ";
        }
      }
      else
      {
        count++;
      }
    }
    if(count==n) cout<<"Empty!";
  cout<<endl;
}
int partition(int*a,int s,int e)
{
  int i=s-1;
  for(int j=s;j<=e-1;j++)
  {
    if(a[e]>=a[j])
    {
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[e],a[i+1]);
  return i+1;
}
void quickSort(int*a,int s,int e)
{
  if(s>=e)
  {
    return;
  }
  int p=partition(a,s,e);
  quickSort(a,s,p-1);
  quickSort(a,p+1,e);
}
void shiftForward(p*a,int n,int i)
{
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
      if(a1[i].first>a2[j].second)
      {
        shiftForward(a1,n1,i);
        n1++;
        a1[i].first=a2[j].first;
        a1[i].second=0;
      }
      else
      {
        shiftForward(a2,n2,j);
        n2++;
        a2[j].first=a1[i].first;
        a2[j].second=0;
      }
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
  int temp1[10000];int temp2[10000];
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter the number of elements of set 1:\n";
  cin>>n1;
  cout<<"Enter the elemets of set 1:\n";
  for(int i=0;i<n1;i++)
  {
    cin>>temp1[i];
  }
  quickSort(temp1,0,n1-1);
  int x=temp1[0];int index=0;
  int prev=x;
  a1[0].first=x;a1[0].second=1;
  for(int i=1;i<n1;i++)
  {
    x=temp1[i];
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
  cout<<"Enter the elemets of set 2:\n";
  for(int i=0;i<n2;i++)
  {
    cin>>temp2[i];
  }
  quickSort(temp2,0,n2-1);
  x=temp2[0];
  index=0;prev=x;
  a2[0].first=x;a2[0].second=1;
  for(int i=1;i<n2;i++)
  {
    x=temp2[i];
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

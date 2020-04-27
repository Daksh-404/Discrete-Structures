#include<iostream>
using namespace std;
typedef pair<int,int>p;
bool isReflexive(p*r,int n,int m)
{
  int count=0;
  for(int i=0;i<m;i++)
  {
    if(r[i].first==r[i].second)
    {
      count++;
    }
  }
  if(count==n)
  {
    return true;
  }
  return false;
}
bool isSymmetric(p*r,int m)
{
  int j;
  if(m<=1) return true;
  for(int i=0;i<m;i++)
  {
    if(r[i].first!=r[i].second)
    {
      for(j=0;j<m;j++)
      {
        if(r[j].first!=r[j].second&&r[i].second==r[j].first&&r[i].first==r[j].second)
        {
          break;
        }
      }
      if(j==m)
      {
        return false;
      }
    }
  }
  return true;
}
bool isTransitive(p*r,int m)
{
  if(m<=2) return true;
  int j,k;
  for(int i=0;i<m;i++)
  {
    if(r[i].first!=r[i].second)
    {
      for(j=0;j<m;j++)
      {
        if(r[j].first==r[i].second)
        {
          for(k=0;k<m;k++)
          {
            if(r[j].second==r[k].second&&r[i].first==r[k].first)
            {
              break;
            }
          }
          if(k==m)
          {
            return false;
          }
        }
      }
    }
  }
  return true;
}
bool ifEquivalence(p*r,int n,int m)
{
  if(isReflexive(r,n,m)&&isSymmetric(r,m)&&isTransitive(r,m))
  {
    return true;
  }
  return false;
}
int main()
{
  p relation[10000];
  int n,m;
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter number of elements of your set:\n";
  cin>>n;
  cout<<"Enter number of elements of your relation:\n";
  cin>>m;
  if(n==0||m==0) cout<<"Cannot be determined!\n";
  cout<<"\nEnter the pairs of the relation:\n";
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    relation[i].first=x;
    relation[i].second=y;
  }
  if(ifEquivalence(relation,n,m)) cout<<"The given relation is an equivalence relation!\n";
  else cout<<"The given relation is not an equivalence relation\n";
  return 0;
}

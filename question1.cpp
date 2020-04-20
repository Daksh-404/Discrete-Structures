#include<iostream>
using namespace std;
void shiftBack(int*a,int n,int i)
{
  //for shifting the elemets back to
  //delete an element
  for(int j=i;j<n-1;j++)
  {
    a[j]=a[j+1];
  }
}
int removeDuplicates(int*a3,int n)
{
  int r[10000]={0};
  int size=n;
  for(int i=0;i<size;i++)
  {
    //for numbers less than 0
    if(a3[i]<0)
    {
      if(r[(10000+a3[i])]!=0)
      {
        shiftBack(a3,size,i);
        size--;
        i--;
        continue;
      }
      r[10000+a3[i]]+=1;
    }
    //for positive numbers
    else
    {
      if(r[a3[i]]!=0)
      {
        shiftBack(a3,size,i);
        size--;
        i--;
        continue;
      }
      r[a3[i]]+=1;
    }
  }
  return size;
}
void hashFunction(int*a,int*m,int n)
{
  for(int i=0;i<n;i++)
  {
    if(a[i]<0)
    {
      m[10000+a[i]]+=1;
    }
    else
    {
      m[a[i]]+=1;
    }
  }
}
int additionSet(int*a1,int*a2,int n1,int n2,int*a3)
{
  //new array for storing the sums
  //int a3[10000];
  //the counter for storing the indicies of a3
  int netIndex=0;
  //loop for adding
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
    {
      a3[netIndex]=a1[i]+a2[j];
      netIndex++;
    }
  }
  //removing the duplicates
  return removeDuplicates(a3,netIndex);
}
int subtractionSet(int*a1,int*a2,int n1,int n2,int*a3)
{
  //new array for storing the sums
  //int a3[10000];
  int netIndex=0;
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
    {
      a3[netIndex]=a1[i]-a2[j];
      netIndex++;
    }
  }
  //removing duplicates
  return removeDuplicates(a3,netIndex);
}
int unionSetReturn(int*a1,int*a2,int n1,int n2,int*a3)
{
  int netIndex=0;
  for(int i=0;i<n1;i++)
  {
    a3[netIndex]=a1[i];
    netIndex++;
  }
  for(int i=0;i<n2;i++)
  {
    a3[netIndex]=a2[i];
    netIndex++;
  }
  return removeDuplicates(a3,netIndex);

}
int intersectionSetArrayChangeReturn(int*a1,int*a2,int*a3,int n1,int n2)
{
  int hashMap[10000]={0};
  int index=0;
  hashFunction(a1,hashMap,n1);
  for(int j=0;j<n2;j++)
  {
    if(hashMap[a2[j]]==1)
    {
      a3[index]=a2[j];
      index++;
      continue;
    }
  }
  return index;
}
int differenceSetReturn(int*a1,int*a2,int n1,int n2,int*diff)
{
  int netIndex=0;
  int intersectionArray[10000];
  int size=intersectionSetArrayChangeReturn(a1,a2,intersectionArray,n1,n2);
  for(int i=0;i<n1;i++)
  {
    int j;
    for(j=0;j<size;j++)
    {
      if(a1[i]==intersectionArray[j])
      {
        break;
      }
    }
    if(j==size)
    {
      diff[netIndex]=a1[i];
      netIndex++;
    }
  }
  return netIndex;
}
int symmetricDifferenceSet(int*a1,int*a2,int n1,int n2,int*a3)
{
//  int a3[10000];
  int diff1[10000];
  int diff2[10000];
  int u[10000];
  int size1=differenceSetReturn(a1,a2,n1,n2,diff1);
  int size2=differenceSetReturn(a2,a1,n2,n1,diff2);
  return unionSetReturn(diff1,diff2,size1,size2,a3);
}
void print(int*a,int n)
{
  if(n==0)
  {
    cout<<"Empty!";
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
  }
  cout<<endl;
}
int main()
{
  int a1[1000];
  int a2[1000];
  int n1,n2;
  cout<<"Enter the number of elements of set 1:\n";
  cin>>n1;
  cout<<"Enter the elemets of set 1:\n";
  for(int i=0;i<n1;i++)
  {
    cin>>a1[i];
  }
  cout<<"Enter the number of elements of set 2:\n";
  cin>>n2;
  if(n1==0&&n2==0) cout<<"No Possible Operation\n";
  cout<<"Enter the elemets of set 2:\n";
  for(int i=0;i<n2;i++)
  {
    cin>>a2[i];
  }
  int add[10000];int sub[10000];
  int u[10000];int intersection[10000];
  int diff[10000];int symmDiff[10000];
  int n;
  n=additionSet(a1,a2,n1,n2,add);
  cout<<"Addition: ";print(add,n);
  n=subtractionSet(a1,a2,n1,n2,sub);
  cout<<"Subtraction: ";print(sub,n);
  n=unionSetReturn(a1,a2,n1,n2,u);
  cout<<"Union: ";print(u,n);
  n=intersectionSetArrayChangeReturn(a1,a2,intersection,n1,n2);
  cout<<"Intersection: ";print(intersection,n);
  n=differenceSetReturn(a1,a2,n1,n2,diff);
  cout<<"Difference: ";print(diff,n);
  n=symmetricDifferenceSet(a1,a2,n1,n2,symmDiff);
  cout<<"Symmetric Difference: ";print(symmDiff,n);
  return 0;
}

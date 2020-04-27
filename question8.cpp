#include<iostream>
using namespace std;
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
    if(a2[j]>=0)
    {
      if(hashMap[a2[j]]==1)
      {
        a3[index]=a2[j];
        index++;
        continue;
      }
    }
    else
    {
      if(hashMap[10000+a2[j]]==1)
      {
        a3[index]=a2[j];
        index++;
        continue;
      }
    }
  }
  return index;
}
int main()
{
  int a1[1000];
  int a2[1000];
  int a3[1000];
  int n1,n2,n3;int choice;
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Specify the number of sets:\n";
  cin>>choice;
  cout<<"Enter the number of elements of set 1:\n";
  cin>>n1;
  cout<<"Enter the elemets of set 1:\n";
  for(int i=0;i<n1;i++)
  {
    cin>>a1[i];
  }
  cout<<"Enter the number of elements of set 2:\n";
  cin>>n2;
//  if(n1==0&&n2==0&&choice==2) cout<<"Invalid input\n";
  cout<<"Enter the elemets of set 2:\n";
  for(int i=0;i<n2;i++)
  {
    cin>>a2[i];
  }
  if(choice==3)
  {
    cout<<"Enter the number of elements of set 3:\n";
    cin>>n3;
    if(n1==0&&n2==0&&n3==0) cout<<"Invalid input\n";
    cout<<"Enter the elemets of set 3:\n";
    for(int i=0;i<n3;i++)
    {
      cin>>a3[i];
    }
  }
  int x1,x2,a,b,c;
  int u[1000];int intersection1[1000];
  int intersection2[1000];int intersection3[1000];
  int intersection4[10000];
  x1=unionSetReturn(a1,a2,n1,n2,u);
  x2=intersectionSetArrayChangeReturn(a1,a2,intersection1,n1,n2);
  if(choice==3)
  {
    x1=unionSetReturn(u,a3,x1,n3,u);
    c=intersectionSetArrayChangeReturn(a3,intersection1,intersection4,n3,x2);
    a=intersectionSetArrayChangeReturn(a1,a3,intersection2,n1,n3);
    b=intersectionSetArrayChangeReturn(a2,a3,intersection3,n2,n3);
  }
  if(choice==2)
  {
    cout<<endl;
    cout<<"A U B = ";print(u,x1);
    cout<<"n(A U B)= "<<x1<<endl;
    cout<<"A intersection B = ";print(intersection1,x2);
    cout<<"n(A intersection B)= "<<x2<<endl;
    cout<<"n(A)= "<<n1<<endl;
    cout<<"n(B)= "<<n2<<endl;
    int rhs=n1+n2-x2;
    cout<<"RHS = n(A)+n(B)-n(A intersection B)= "<<rhs<<endl;
    cout<<"LHS =n(A U B)= "<<x1<<endl;
    cout<<"We see LHS and RHS are equal, thus\nn(A U B)=n(A)+n(B)-n(A intersection B)\nThus principle of Inclusion-Exclusion is Verified\n";
  }
  else if(choice==3)
  {
    cout<<endl;
    cout<<"A U B U C = ";print(u,x1);
    cout<<"n(A U B U C)= "<<x1<<endl;
    cout<<"A intersection B = ";print(intersection1,x2);
    cout<<"n(A intersection B)= "<<x2<<endl;
    cout<<"B intersection C = ";print(intersection3,b);
    cout<<"n(B intersection C)= "<<b<<endl;
    cout<<"A intersection C = ";print(intersection2,a);
    cout<<"n(A intersection C)= "<<a<<endl;
    cout<<"n(A)= "<<n1<<endl;
    cout<<"n(B)= "<<n2<<endl;
    cout<<"n(C)= "<<n3<<endl;
    cout<<"A intersection B intersection C = ";print(intersection4,c);
    cout<<"n(A intersection B intersection C)= "<<c<<endl;
    int rhs=n1+n2+n3+c-x2-a-b;
    cout<<"RHS = n(A)+n(B)+n(C)-n(A intersection B)-n(B intersection C)-n(C intersection A)+n(A intersection B intersection C)= "<<rhs<<endl;
    cout<<"LHS =n(A U B)= "<<x1<<endl;
    cout<<"We see LHS and RHS are equal, thus\nn(A U B U C)=n(A)+n(B)+n(C)-n(A intersection B)-n(B intersection C)-n(C intersection A)+n(A intersection B intersection C)\nThus principle of Inclusion-Exclusion is Verified\n";
  }
  return 0;
}

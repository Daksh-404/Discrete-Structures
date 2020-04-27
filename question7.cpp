#include<iostream>
using namespace std;
bool checkLattice(int*poset,int n)
{
  int k;
  for(k=0;k<n;k++)
  {
    if(poset[n-1]%poset[k]!=0||poset[k]%poset[0]!=0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int n;
  int poset[1000];
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter number of elements in the POSET:\n";
  cin>>n;
  cout<<"Enter the elements of the POSET(in the order of divisibility):\n";
  for(int i=0;i<n;i++)
  {
    cin>>poset[i];
  }
  if(checkLattice(poset,n)) cout<<"It is a Lattice"<<endl;
  else cout<<"It's not a Lattice!";
  return 0;
}

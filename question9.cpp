#include<iostream>
using namespace std;
float sqrt(int number)
{
    float ans=0;
    float inc=1.0;
    for(int i=0;i<=3;i++)
    {
      while(ans*ans<=number)
      {
        ans=ans+inc;
      }
      ans=ans-inc;
      inc=inc/10;
    }
    return ans;
}
void expressionRecurrence(int k1,int k2,int k3,int b1,int b2,int ans1,int ans2)
{
  float c1;float c2;
  float r1=float(((-k2)+sqrt(k2*k2-4*k1*k3)))/float(2*k1);
  float r2=float(((-k2)-sqrt(k2*k2-4*k1*k3)))/float(2*k1);
  if(int(r1)==int(r2))
  {
    c1=(ans1);
    c2=float(((-r1)*ans1+ans2))/float(r2);
    cout<<"T(n) = "<<c1<<"("<<r1<<")"<<"^n + "<<"( "<<c2<<")"<<"n("<<r2<<")"<<"^n";
  }
  else
  {
    c1=float((ans1*r2-ans2))/float((r2-r1));
    c2=float(((-r1)*ans1+ans2))/float(r2-r1);
    cout<<"T(n) = "<<c1<<"("<<r1<<")"<<"^n + "<<"( "<<c2<<")"<<"("<<r2<<")"<<"^n";
  }
}
int main()
{
  int k1,k2,k3,b1,b2,ans1,ans2;
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
    cout<<"Enter the coefficients of T(n),T(n-1) and T(n-2):\n";
    cin>>k1>>k2>>k3;
    k2=(-k2);
    k3=(-k3);
    cout<<"Enter the two base case and it's output:\n";
    cin>>b1>>ans1;
    cin>>b2>>ans2;
    expressionRecurrence(k1,k2,k3,b1,b2,ans1,ans2);
  return 0;
}

#include<iostream>
using namespace std;
int ix=0;
int s;
void printNextPermute(string list[10000],int idx)
{
  for(int i=0;i<idx-1;i++)
  {
    for(int j=0;j<idx-i-1;j++)
    {
      if(list[j]>list[j+1])
      {
        string t=list[j];
        list[j]=list[j+1];
        list[j+1]=t;
      }
    }
  }
  for(int i=0;i<idx;i++)
  {
    if(list[i].length()==0)
    {
      continue;
    }
    cout<<list[i]<<endl;
  }
  return;
}
void permute(string str,int start,string list[10000])
{
  if(str[start]=='\0')
  {
    list[ix]=str;
    ix++;
    return;
  }
  for(int i=start;i<str.length();i++)
  {
    swap(str[i],str[start]);
    permute(str,start+1,list);
    swap(str[i],str[start]);
  }
  return;
}
void combination(string key,string output,string list[10000])
{
    if(key.length()==0)
    {
      permute(output,0,list);
      return;
    }
    combination(key.substr(1),output,list);
    combination(key.substr(1),output+key[0],list);
    return;
}
int main()
{
  string key;
  string output;
  string list[10000];
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter the keyword:\n";
  cin>>key;
  combination(key,output,list);
  cout<<"All the possible combinations are:\n";
  printNextPermute(list,ix);
  return 0;
}

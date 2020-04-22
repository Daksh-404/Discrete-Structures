#include<iostream>
using namespace std;
int index=0;
int s;
void printNextPermute(string list[100],int idx)
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
  //printing the list
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
void permute(string str,int start,string list[100])
{
  //base case
  if(str[start]=='\0')
  {
    list[index]=str;
    index++;
    return;
  }
  //recursive case
  for(int i=start;i<str.length();i++)
  {
    swap(str[i],str[start]);
    permute(str,start+1,list);
    swap(str[i],str[start]);
  }
  return;
}
void combination(string key,string output,string list[1000])
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
//  string list[100];
  string output;
  string list[1000];
  cout<<"Enter the keyword:\n";
  cin>>key;
  combination(key,output,list);
  printNextPermute(list,index);
  return 0;
}

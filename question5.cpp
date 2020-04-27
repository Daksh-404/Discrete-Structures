#include<iostream>
using namespace std;
int index=0;
void printNextPermute(string list[10000],int idx,string key)
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
    if(list[i]==key)
    {
      cout<<list[i+1]<<endl;
      break;
    }
  }
  return;
}
void permute(string str,int start,string list[10000])
{
  if(str[start]=='\0')
  {
    list[index]=str;
    index++;
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
int main()
{
  string key;
  string list[10000];
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter the keyword:\n";
  getline(cin,key);
  permute(key,0,list);
  cout<<"The next permutation of the above key word: ";
  printNextPermute(list,index,key);
  return 0;
}

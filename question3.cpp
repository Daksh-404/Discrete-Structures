#include<iostream>
using namespace std;
void exchangingTerms(char*inp,int count)
{
  int hash[200];
  for(int k=0;k<200;k++)
  {
    hash[k]=-1;
  }
  for(int i=0;inp[i]!='\0';i++)
  {
    char ch=inp[i];
    if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
    {
      if(hash[ch]!=-1)
      {
        inp[i]=hash[ch]+'0';
      }
      else
      {
        int x=count&1;
        count=count>>1;
        inp[i]=x+'0';
        hash[ch]=x;
      }
    }
  }
}
int invert(int a)
{
  if(a==0) return 1;
  else return 0;
}
int operation(int p,int q,char op)
{
  //int t;
  if(op=='&') return p&q;
  if(op=='|') return p|q;
  if(op=='-')
  {
      if(q==0&&p==1) return 0;
      else return 1;
  }
  if(op=='#') return invert(p^q);
  return -1;
}
void logicalDetermination(char*in,int n)
{
  int no=0;
  char temp[100];
  int m;
  for(m=0;in[m]!='\0';m++)
  {
      temp[m]=in[m];
  }
  temp[m]='\0';
  char check[100];
  char c,prev;
  for(int i=0;i<(1<<n);i++)
  {
    for(m=0;temp[m]!='\0';m++)
    {
        in[m]=temp[m];
    }
    in[m]='\0';
    exchangingTerms(in,i);
    char s[100];int f=0;char ch;
    int x,p,q;
    for(int j=0;in[j]!='\0';)
    {
      ch=in[j];
      if(ch=='('||ch=='0'||ch=='1')
      {
        s[f]=ch;f++;j++;continue;
      }
      if(ch=='&'||ch=='|'||ch=='!'||ch=='-'||ch=='#')
      {
          if(in[j+1]=='0'||in[j+1]=='1')
          {
            q=in[j+1]-'0';
            if(ch=='!')
            {
              x=invert(q);
            }
            if(ch=='&'||ch=='|'||ch=='-'||ch=='#')
            {
              if(in[j-1]==')')
              {
                  p=s[f-1]-'0';
              }
              else
              {
                  p=in[j-1]-'0';
              }
            }
          }

          if(in[j+1]=='(')
          {
            s[f]=ch;f++;
            s[f]='(';f++;j+=2;
            continue;
          }
          if(in[j+2]==')')
          {
            if(ch=='!')
            {
              f--;
              s[f]=x+'0';
            }
            if(ch=='&'||ch=='|'||ch=='-'||ch=='#')
            {
              f-=2;
              s[f]=operation(p,q,ch)+'0';
            }
            if(f==0)
            {
              break;
            }
            if((s[f-1]=='&'||s[f-1]=='|'||s[f-1]=='!'||s[f-1]=='-'||s[f-1]=='#')&&f>0)
            {
              q=s[f]-'0';
              if(s[f-1]=='!')
              {
                x=invert(q);
                s[f-1]=x+'0';
              }
              if(s[f-1]=='&'||s[f-1]=='|'||s[f-1]=='-'||s[f-1]=='#')
              {
                p=s[f-2]-'0';
                s[f-2]=operation(p,q,s[f-1])+'0';f--;
              }
              j+=3;
            }
            else
            {
                j+=3;f++;
            }
          }
      }
      if(ch==')')
      {
        if(s[f-2]=='(')
        {
            s[f-2]=s[f-1];f--;
        }
        else
        {
              q=s[f-1]-'0';
              if(s[f-2]=='!')
              {
                x=invert(q);
                s[f-3]=x+'0';f-=2;
              }
              if(s[f-2]=='&'||s[f-2]=='|'||s[f-2]=='-'||s[f-2]=='#')
              {
                p=s[f-3]-'0';
                s[f-4]=operation(p,q,s[f-2])+'0';f-=3;
              }
        }
        j++;
      }
    }
    c=s[0];
    if(no==0)
    {
      check[no]=c;
      prev=c;no++;
    }
    else
    {
      if(prev!=c)
      {
        cout<<"Contingency!";return;
      }
      check[no]=c;no++;
    }
  }
  if(check[no-1]=='0') cout<<"Contradiction!";
  if(check[no-1]=='1') cout<<"Tautology!";
}
int main()
{
  char inp[100];
  int n;
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter the number of variables:\n";
  cin>>n;
  cout<<"Enter the expression to be evaluated:\n";
  cin>>inp;
  logicalDetermination(inp,n);
  return 0;
}

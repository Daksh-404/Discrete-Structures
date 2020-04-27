#include<iostream>
using namespace std;
int graph[100][100]={0};
int track[100]={0};
int track3[100];
int visited[100]={0};
int parent[100];int color[100][100];
int son[100];
int no=0;int idx=0;int sc=0;
int FLAG=0;
void createGraph()
{
  int element,neighbour;int i=0;
  cin>>element;
  if(element==-1)
  {
    cout<<"No graph formed!";
    return;
  }
  else cin>>neighbour;
  while(1)
  {
    graph[track[element]][element]=neighbour;
    track[element]++;
    graph[track[neighbour]][neighbour]=element;
    track[neighbour]++;
    no++;
    cin>>element;
    if(element==-1) break;
    cin>>neighbour;
  }
}
void bubbleSort(int*a,int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        swap(a[j],a[j+1]);
      }
    }
  }
  return;
}
void backPrinting(int*parent,int dest)
{
  while(dest!=sc)
  {
    cout<<dest<<"<-";
    //visited[dest]=false;
    dest=parent[dest];
  }
  cout<<dest<<endl;
  return;
}
void backCyclePrinting(int dest,int final)
{
  int k=dest;int t;
  while(dest!=final)
  {
    cout<<dest<<"<-";
    visited[dest]=0;
    t=parent[dest];
    //parent[dest]=100000;
    dest=t;
  }
  visited[dest]=0;
  //parent[dest]=100000;
  cout<<dest<<"<-"<<k<<endl;
  return;
}
void colorFunction(int src,int dest)
{
  int s=src;int d=dest;
  int temp[100];int i=0;
  while(s!=d)
  {
    temp[i]=s;i++;
    s=parent[s];
  }
  temp[i]=s;i++;
  int flag=0;int k,l;
  bubbleSort(temp,i);
  int len=i;
  if(idx==0) flag=1;
  if(idx>0)
  {
    for(k=0;k<idx;k++)
    {
      if(temp[0]==color[k][0])
      {
        break;flag=0;
      }
    }
    if(k==idx) flag=1;
    if(track3[k]!=len) flag=1;
    if(!flag)
    {
      for(l=1;l<track3[k];l++)
      {
        if(temp[l]!=color[k][l])
        {
          flag=1;break;
        }
      }
      if(l==track3[k])
      {
        flag=0;
        FLAG=0;
        int st=src;int f=dest;int t;
        while(st!=dest)
        {
          t=parent[st];
          visited[st]=0;
          //parent[st]=100000;
          st=t;
        }
        visited[st]=0;
        //parent[st]=100000;
      }
    }
  }
  if(flag)
  {
    FLAG=1;
    for(int m=0;m<len;m++)
    {
      color[idx][m]=temp[m];
    }
    track3[idx]=len;
    idx++;
  }
  return;
}
void printingPath(int src,int dest)
{
  if(src==dest)
  {
    parent[dest]==100000;
    backPrinting(parent,dest);
    return;
  }
  for(int i=0;i<track[src];i++)
  {
    int neighbour=graph[i][src];
    if(!visited[neighbour])
    {
      parent[neighbour]=src;
      visited[src]=1;
      printingPath(neighbour,dest);
    }
  }
  visited[src]=0;
  parent[src]=100000;
  return;
}
void cyclePrinting(int src)
{
  int prev;
  for(int i=0;i<track[src];i++)
  {
    int neighbour=graph[i][src];
    if(!visited[neighbour]&&parent[src]!=neighbour&&son[neighbour]!=src)
    {
      parent[neighbour]=src;
      son[src]=neighbour;
      visited[src]=1;
      cyclePrinting(neighbour);
    }
    else
    {
      if(parent[src]!=neighbour&&son[neighbour]!=src)
      {
        colorFunction(src,neighbour);
        if(FLAG)
        {
          if(i>0)
          {
            int prev=graph[i-1][src];
            parent[prev]=100000;
            son[prev]=100000;
          }
          backCyclePrinting(src,neighbour);
        }

      }
    }
  }
  return;
}
int main()
{
  int s,d;
  cout<<endl<<"Name - Daksh Gupta"<<endl;
  cout<<"Roll no. - 2019UCO1669"<<endl<<endl;
  cout<<"Enter the vertices of all the edges(add -1 at the end):\n";
  createGraph();
  cout<<"Enter the source and destination for the path:\n";
  cin>>s>>d;
  for(int i=0;i<100;i++)
  {
    parent[i]=100000;
  }
  parent[s]=s;sc=s;
  cout<<"All the paths from source to destination are:\n";
  printingPath(s,d);
  cout<<"All the cycles in the graph:\n";
  cyclePrinting(s);
  return 0;
}

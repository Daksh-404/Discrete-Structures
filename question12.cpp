#include<iostream>
using namespace std;
int graph[100][100]={0};
int track[100]={0};
int track3[100];
int visited[100]={0};
int parent[100];int color[100][100];
int idx=0;int sc=0;
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
    dest=parent[dest];
  }
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
  int flag=0;int k,x,l;
  bubbleSort(temp,i);
  int len=i;
  if(idx==0) flag=1;
  if(idx>0)
  {
      for(x=0;x<idx;x++)
      {
          if(track3[x]==len)
          {
              flag=0;break;
          }
      }
      if(x==idx) flag=1;
      if(!flag)
      {
          for(k=x;k<idx;k++)
          {
              for(l=0;l<track3[k]&&track3[k]==len;l++)
              {
                  if(temp[l]!=color[k][l])
                  {
                      break;
                  }
              }
              if(l==track3[k])
              {
                  flag=0;FLAG=0;return;
              }
          }
          if(k==idx) flag=1;
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
    backPrinting(parent,dest);
    parent[src]=100000;
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
  for(int i=0;i<track[src];i++)
  {
    int neighbour=graph[i][src];
    if(!visited[neighbour])
    {
      parent[neighbour]=src;
      visited[src]=1;
      cyclePrinting(neighbour);
    }
    else
    {
      if(parent[src]!=neighbour)
      {
        colorFunction(src,neighbour);
        if(FLAG)
        {
          backCyclePrinting(src,neighbour);
        }

      }
    }
  }
  visited[src]=0;
  parent[src]=100000;
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

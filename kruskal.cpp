#include<bits/stdc++.h>
using namespace std;


int findp(int p[],int v)
{
    while(p[v]!=v)
        v=p[v];
    return v;
}

int kruskal(int a[20][20],int n)
{
  int parent[20],i,j,u,v;
  int min,mincost=0;
  for(i=0;i<n;i++)
    parent[i]=i;
  for(int k=0;k<n-1;k++)
    { min=INT_MAX;
     for(i=0;i<n;i++)
           for(j=0;j<n;j++)
             {
               if(a[i][j]<min)
               {
                   min=a[i][j];
                   u=i;
                   v=j;
               }
             }

      int parent1=findp(parent,u);
      int parent2=findp(parent,v);


      if(parent1==parent2)
        {k--;
        a[u][v]=a[v][u]=INT_MAX;
        }

      else
    {
       mincost+=a[u][v];
       a[u][v]=a[v][u]=INT_MAX;
       cout<<u<<"-->"<<v<<"-->";
     if(parent1>parent2)
        parent[parent1]=parent2;
     else
        parent[parent2]=parent1;
    }

}
return mincost;
}
int main()
{
int a[20][20],n,i,j,wt;
    cout<<"Enter the no of nodes : "<<endl;
    cin>>n;
    char ch;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        a[i][j]=INT_MAX;
    do
    {
        cout<<"\n enter the edge <v1,v2,wt> : ";
        cin>>i>>j>>wt;
        a[i][j]=a[j][i]=wt;
        cout<<"\n more edges ? (y/n) :";
        cin>>ch;
    }while(ch=='y');

 int cost=kruskal(a,n);
 cout<<"mini cost"<<cost<<endl;
}

#include<bits/stdc++.h>
using namespace std;

class Topo
{
    int n,a[10][10],i,j,indeg[10];

   int stck[10],t[10];
public:
    void get_data();
    void indegree();
    void Tsort();
    //void put_data();
};

void Topo::get_data()
{
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

void Topo::indegree()
{
    for(j=0;j<n;j++)
    {
        int sum=0;
        for(i=0;i<n;i++)
          {
            sum=sum+a[i][j];
          }
        indeg[j]=sum;
    }

}


void Topo:: indegree()
{
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i][j];
        }
        indegree[j]=sum;
    }
}
void Topo::Tsort()
{
   int top=-1;
   int k=0;
   indegree();
   for(i=0;i<n;i++)
   {
       if(indeg[i]==0)
        stck[++top]=i;
   }

   while(top!=-1)
   {
       int u=stck[top--];
       t[k++]=u;
       for(int v=0;v<n;v++)
       {
           if(a[u][v]==1)
           {
               indeg[v]--;
               if(indeg[v]==0)
                stck[++top]=v;
           }
       }
   }
cout<<"topo order\n";
   for(i=0;i<n;i++)
       cout<<t[i]<<"-->";

}
int main()
{
    Topo T;
   clock_t start,stop;
    T.get_data();
    start=clock();
   // T.indegree();
    T.Tsort();
    stop=clock();
    cout<<"Time taken:"<<(stop-start)<<"millisecs\n";
   getchar();

}

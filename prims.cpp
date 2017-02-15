#include<bits/stdc++.h>
using namespace std;
//int source;
class Prims
{
    int n,a[10][10],visited[10],parent[10],d[10],t[10][2],mini;
    int k=0;
    int sum=0;

public:
    void getdata();
    void prim_algo();
   // void print_data();

};

void Prims:: getdata()

{
    int i,j;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"enter the cost matrix\n";
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

void Prims::prim_algo()
{
    int i,j,v,u;
    sum=0;
    mini=999;
    int source=0;

    for(i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
    {
        if(a[i][j]!=0 && a[i][j]<mini)
        {
            mini=a[i][j];
            source=i;
        }
    }
    }

    for(i=0;i<n;i++)
    {
        visited[i]=0;
        parent[i]=source;
        d[i]=a[source][i];
    }

    visited[source]=1;
    for(i=1;i<n;i++)
    {
       int mini=999,u=-1;
       for( j=0;j<n;j++)
       {
           if(visited[j]==0 && d[j]<=mini)
           {
               mini=d[j];
               u=j;
           }
       }


    visited[u]=1;
    t[k][0]=u;
    t[k][1]=parent[u];
    k++;
    sum=sum+a[u][parent[u]];

    for(v=0;v<n;v++)
    {
        if(visited[v]==0 && a[u][v]<d[v])
        {
            d[v]=a[u][v];
            parent[v]=u;
        }
    }
}

if(sum>=999)
    cout<<"Spanning tree doesn't exist\n";
else
{
    cout<<"min spanning tree\n";
    for( i=0;i<n;i++)
    {
        cout<<t[i][0]<<"  "<<t[i][1]<<endl;

    }
    cout<<"The cost of spanning tree"<<sum;
}
}



int main()
{
    Prims P;
    P.getdata();
    P.prim_algo();

}


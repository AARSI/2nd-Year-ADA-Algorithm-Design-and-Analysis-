#include<bits/stdc++.h>
using namespace std;
//int source;
class Dijkstra
{
    int n,a[10][10],visited[10],parent[10],d[10],u,v,source;

public:
    void getdata();
    void dij_algo();
    void print_data();

};

void Dijkstra:: getdata()

{
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"enter the cost matrix\n";
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

void Dijkstra::dij_algo()
{
    cout<<"enter the source\n";
    cin>>source;

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        parent[i]=source;
        d[i]=a[source][i];
    }

    visited[source]=1;
    for(int i=1;i<n;i++)
    {
       int mini=999,u=0;
       for(int j=0;j<n;j++)
       {
           if(visited[j]==0 && d[j]<mini)
           {
               mini=d[j];
               u=j;
           }
       }


    visited[u]=1;

    for(v=0;v<n;v++)
    {
        if(visited[v]==0 && (d[u]+a[u][v]<d[v]))
        {
            d[v]=d[u]+a[u][v];
            parent[v]=u;
            //visited[v]=1;
        }
    }
}
}

void Dijkstra::print_data()
{
    for(int i=0;i<n;i++)
    {
        if(i==source)
            continue;
        cout<<"The shortest path from"<<source<<"to"<<i<<endl;

        int k=i;
        cout<<i<<"<--";
        while(parent[k]!=source)
        {
            cout<<parent[k]<<"<--";
            k=parent[k];
        }
        cout<<source<<endl;
        cout<<"Total cost:"<<d[i];
    }
}

int main()
{
    Dijkstra D;
    //int source;
    D.getdata();
    //cout<<"Enter the source node\n";
    //cin>>source;
    D.dij_algo();
    D.print_data();
}

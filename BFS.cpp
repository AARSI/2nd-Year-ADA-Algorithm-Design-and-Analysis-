#include<bits/stdc++.h>
using namespace std;

class BFS
{
    int n,a[10][10],source,visited[10],q[10];
public:
    void get_data();
    void print_data();
    void algo();

};


void BFS::get_data()
{
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the adjacency matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>> a[i][j];
        }
    }
    cout<<"Enter the source node\n";
    cin>>source;

}


void BFS::algo()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    visited[source]=1;
    int f,r;
    f=r=0;
    q[r]=source;
    while(f<=r)
    {
        int u=q[f];
       // cout<<u<<"-->";

        f++;
        for(int v=0;v<n;v++)
        {
            if(visited[v]==0 && a[u][v]==1)
                {
                    visited[v]=1;
                    q[++r]=v;
                }
        }
    }
}


void BFS::print_data()
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            cout<<"The node"<<i<<"is not reachable\n";
        else
            cout<<i<<"-->";
    }
}




int main()
{
    BFS B;
    clock_t start,stop;
    B.get_data();
    start=clock();
    B.algo();
    stop=clock();
    B.print_data();
    cout<<"Time taken:"<<(stop-start)<<"mscs\n";

}

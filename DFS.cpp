#include<bits/stdc++.h>
using namespace std;

class DFS
{
    int n,a[10][10],visited[10],source;
public:
    void get_data();
    void algo(int);
};

void DFS::get_data()
{
    clock_t start;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the adjacency matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<"Enter the source node\n";
    cin>>source;
    for(int i=0;i<n;i++)
        visited[i]=0;
     start=clock();
    algo(source);
}

void DFS::algo(int u)
{
   visited[u]=1;
   cout<<u<<"-->";
   for(int v=0;v<n;v++)
   {
       if(visited[v]==0 && a[u][v]==1)
       {
           algo(v);
       }
   }
}




int main()
{
    DFS D;
    clock_t start,stop;
    D.get_data();
    stop=clock();


    cout<<"Time taken"<<(stop-start)<<"mscs\n";


}

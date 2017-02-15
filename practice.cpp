#include<bits/stdc++.h>
using namespace std;


class TSP
{
    int n,i,j,visited[10],a[10][10],mini,nc,nextcity;

public:

  int source;
    int cost=0;
    void get_data();
    int next_city(int);
    void printpath(int);
};

void TSP::get_data()
{
    cout<<"Enter the number of cities\n";
    cin>>n;
    cout<<"Enter the cost matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

int TSP::next_city(int c)
{
    mini=999;nc=999;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && a[c][i]!=0 && a[c][i]!=999)
        {
            if(a[c][i]<=mini)
            {
                mini=a[c][i];
                nc=i;
            }
        }
    }

    if(mini!=999)
        cost=cost+mini;
 return nc;

}

void TSP::printpath(int city)
{
    visited[city]=1;
    cout<<city;
    cout<<"-->";
     nextcity=next_city(city);
    if(nextcity==999)
    {
        cout<<source;
        cost=cost+a[city][source];
    }
   else
    printpath(nextcity);
}
int main()
{
    TSP T;

    T.get_data();
    cout<<"Enter the source\n";
    cin>>T.source;
    T.printpath(T.source);

    cout<<"min cost:"<<T.cost;

}

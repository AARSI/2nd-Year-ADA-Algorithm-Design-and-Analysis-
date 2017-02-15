#include<bits/stdc++.h>
using namespace std;
int source;
class Salesman
{
    int visited[10],n,next_city,a[10][10];

public:
    int cost=0;
    void get_data();
    void min_cost(int);
    int next_city_algo(int);
};

void Salesman::get_data()
{
    cout<<"Enter the number of cities\n";
    cin>>n;
    for(int i=0;i<n;i++)
        visited[i]=0;
    cout<<"Enter the dist matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
}


int Salesman::next_city_algo(int c)
{
    int mini=999,nc=999;
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
void Salesman::min_cost(int city)
{
    visited[city]=1;
    cout<<city<<"-->";
    next_city=next_city_algo(city);
    if(next_city==999)
    {
       // next_city=source;
        cout<<source;
        cost=cost+a[city][source];
        return;
    }

    min_cost(next_city);
}
int main()
{
    Salesman S;
    int source;
    S.get_data();
   cout<<"Enter the source city\n";
    cin>>source;
    cout<<"The order of visiting cities\n";
    S.min_cost(source);
    cout<<"the min cost is:"<<S.cost;
}

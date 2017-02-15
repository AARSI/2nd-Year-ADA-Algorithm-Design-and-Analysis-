#include<bits/stdc++.h>
using namespace std;

class Knapsack
{
    int M,n,w[10],p[10],v[10][10],x[10];
public:
    void get_data();
    void Knapsack_algo();
    void print_data();
    int max_of(int,int);
};



void Knapsack::get_data()
{
    cout<<"Enter the capacity of knapsack\n";
    cin>>M;
    cout<<"enter the number of objects\n";
    cin>>n;
    cout<<"Enter the weights\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<".";
        cin>>w[i];
        cout<<endl;
    }

    cout<<"Enter the profits\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<".";
        cin>>p[i];
        cout<<endl;
    }


}


void Knapsack::Knapsack_algo()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i==0||j==0)
            {
                v[i][j]=0;
            }
            else if(w[i]>j)
            {
                v[i][j]=v[i-1][j];
            }
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
        }
    }
}


void Knapsack::print_data()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=M;j++)
        {
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }


    cout<<"Max profit\n";
    cout<<v[n][M];

    cout<<"weights chosen\n";
    for(int i=1;i<=n;i++)
    {
        x[i]=0;
    }
    int i=n;int j=M;

    while(i!=0&& j!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }

for(int i=1;i<=n;i++)
    cout<<"x["<<i<<"]"<<"="<<x[i]<<endl;
}


int main()
{
    Knapsack K;
    K.get_data();
    K.Knapsack_algo();
    K.print_data();
}

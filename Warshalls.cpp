#include<bits/stdc++.h>
using namespace std;

class Warshall
{
public:
    void algo(int a[][100],int n)
    {

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {

                if(a[i][k]==1 && a[k][j]==1)
                      a[i][j]=1;

                }
            }
        }

    }
};


int main()
{

    int n, a[100][100];
    Warshall W;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the adjacency matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];

        }

    }

    W.algo(a,n);
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
            cout<<"\t";
        }
        cout<<"\n";

    }


}

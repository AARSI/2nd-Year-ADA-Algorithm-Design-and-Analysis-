#include<bits/stdc++.h>
using namespace std;

class Floyd
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

                if(a[i][k]+a[k][j]<a[i][j])
                      a[i][j]=a[i][k]+a[k][j];

                }
            }
        }

    }
};


int main()
{

    int n, a[100][100];
    Floyd F;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the cost matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];

        }

    }

    F.algo(a,n);
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


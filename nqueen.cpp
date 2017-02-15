#include<bits/stdc++.h>
using namespace std;
int n;

class nqueen
{
    int x[10];
public:
    void print_res(int n,int x[]);
    void nqueens(int n);

    int place(int x[],int k)
{
    for(int i=0;i<k;i++)

        if(x[i]==x[k]|| k-x[k]==i-x[i]||k+x[k]==i+x[i])
            return 0;
    return 1;

}
};

void nqueen::print_res(int n,int x[])
{
    char a[10][10];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
         a[i][j]='X';
        }
    }

    for(int i=1;i<=n;i++)
    {
        a[i][x[i]]='Q';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}


void nqueen::nqueens(int n)
{
    int x[10];
    int counter=0;
    int k=1;

    x[k]=0;
    while(k!=0)
    {
        x[k]=x[k]+1;

        while((x[k]<=n) && (!place(x,k)))
               x[k]=x[k]+1;


        if(x[k]<=n)
           {
             if(k==n)
                {
                    counter++;
                    cout<<"solution"<<counter<<"is:\n";
                    print_res(n,x);
                }
                else
                {
                    k++;
                    x[k]=0;
                }
           }
        else
                k--;
    }
}


int main()
{
    cout<<"enter the num of queens\n";
    cin>>n;
    nqueen Q;
    Q.nqueens(n);
}

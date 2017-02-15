#include<bits/stdc++.h>
using namespace std;

class selection
{
    int pos,temp;
public:
    void sort_algo (int a[],int n)
    {
        for(int l=0;l<n;l++)
         {
            pos=l;
          for(int j=l+1;j<n;j++)
            {
                if (a[j]<a[pos])
                {
                    temp=a[pos];
                    a[pos]=a[j];
                    a[j]=temp;
                }

              }

         }
    }
};

int main()
{
    int n,a[1000];
    clock_t start,stop;
    selection S;
    cout<<"Enter the number of ele\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }

    start=clock();
    S.sort_algo(a,n);
    stop=clock();
    cout<<"The sorted array looks like this\n";
    for(int k=0;k<n;k++)
        cout<<a[k]<<"\n";
    cout<<"Time taken"<<(stop-start)/CLK_TCK<<"seconds\n";

}


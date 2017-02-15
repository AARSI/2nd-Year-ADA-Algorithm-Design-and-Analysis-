#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

class Merge
{
    int low,high;
public:
    void m_sort(int a[],int low, int high)
    {
        if(low<high)
        {
           int mid=(low+high)/2;
           m_sort(a,low,mid);
           m_sort(a,mid+1,high);
           sort_algo(a,low,mid,high);
        }
    }

    void sort_algo(int a[],int low, int mid, int high)
    {
       int i=low;
        int j=mid+1;
       int k=low;
        int c[MAX];

        while(i<=mid && j<=high)
        {
            if(a[i]<a[j])
            {
                c[k]=a[i];
                i++;
                k++;
            }
            else
            {
                c[k]=a[j];
                j++;
                k++;
            }
        }
            while(i<=mid)
            {
                c[k++]=a[i++];
            }
            while(j<=high)
            {
                c[k++]=a[j++];
            }

        for(i=low;i<=high;i++)
        {
            a[i]=c[i];
        }
    }
};


int main()
{
    int a[MAX];
    Merge M;
    clock_t start,stop;

    cout<<"Enter the no of elements to be sorted\n";
    int n;
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<endl;
    }

    cout<<"The sorted array looks like \n";
    start=clock();
    M.m_sort(a,0,n-1);
    stop=clock();
    for(int m=0;m<n;m++)
    {
        cout<<a[m]<<endl;
    }

    cout<<"Time taken:"<<(stop-start)<<"msecs\n";




}

#include<bits/stdc++.h>
#include<time.h>
using namespace std;

class quick
{
    int i,j,pivot,temp;
public:
    int partition_algo(int a[],int low, int high)
    {
        i=low+1;
        j=high;
        pivot=a[low];
        while(i<=j)
        {
            while(i<=high && a[i]<=pivot)
                i++;
            while(j>=low && a[j]>pivot)
                j--;

            if(i<j)
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

            }
                temp=a[low];
                a[low]=a[j];
                a[j]=temp;
                return j;

    }

    void quicksort(int a[],int low,int high)
    {
        if(low<high)
        {
        int j=partition_algo(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
        }
    }

};


int main()
{
    int n,a[100];
    quick Q;
    clock_t start, stop;
    cout<<"Enter the num of elements to be sorted\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
       // cin>>a[i];
       a[i]=rand()%100;
       cout<<a[i]<<endl;
    }

    start=clock();

    Q.quicksort(a,0,n-1);

    stop=clock();
    cout<<"sorted array\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"Time taken is"<<(stop-start)<<"secs\n";

}




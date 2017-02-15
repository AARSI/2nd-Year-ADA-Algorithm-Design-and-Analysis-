#include<bits/stdc++.h>
using namespace std;

class binary
{

    int low,mid,high;
    int flag=0;
    public:
    void algo(int a[],int n, int key)
    {
       low=0;
       high=n-1;

       while(low<=high)
       {
            mid=(low+high)/2;
           if(a[mid]==key)
           {
               cout<<"ele found at pos"<<mid+1;
               flag=1;
               break;
           }
           if(key>a[mid])
           {
               low=mid+1;
           }
           else
             high=mid-1;
       }
       if(flag==0)

        cout<<"Ele not found\n";


    }
};

int main()
{
    int n,key,a[10000];
    clock_t start,stop;
    binary B;
    cout<<"Enter the no of ele\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i]=(2*i)+7;
        cout<<a[i]<<endl;
    }
    cout<<"Enter key\n";
    cin>>key;


    start=clock();
    +1000;
    B.algo(a,n,key);
    stop=clock();

    cout<<"Total time taken"<<(stop-start)<<"secs\n";


}

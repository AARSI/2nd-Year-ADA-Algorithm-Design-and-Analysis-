#include<bits/stdc++.h>
using namespace std;

class Insertion
{
    int n, a[1000], j;
public:
    void get_data();
    void Isort();
    void put_data();
};

void Insertion::get_data()
{
    cout<<"Enter the number of elements\n";
    cin>>n;
    //cout<<"Enter the ele\n";
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
}

void Insertion::Isort()
{
    for(int i=1;i<n;i++)
    {
        int num=a[i];
        for( j=i-1;j>=0 && a[j]>num;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=num;
    }
}

void Insertion::put_data()
{
    cout<<"the sorted array looks like this\n";
    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<endl;
    }
}

int main()
{
    clock_t start,stop;
    Insertion I;
    I.get_data();
    start=clock();
    I.Isort();
    stop=clock();
    I.put_data();

    cout<<"Time taken:"<<(stop-start)<<"milliseconds\n";

}

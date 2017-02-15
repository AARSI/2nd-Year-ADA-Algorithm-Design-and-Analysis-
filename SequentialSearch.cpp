//#include<iostream>
//#include<stdlib.h>
//#include<dos.h>
//#include<time.h>
//#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
class linear
{
    int flag=0;
public:
      void search_algo(int a[],int n,int key)
      {
          for (int i=0;i<n;i++)
          {
              if(a[i]==key)
              {
                  cout<<"Element found at"<<i+1<<"pos\n";

                  flag=1;
                   break;
              }

          }
          if(flag==0)
            cout<<"Element not found\n";
      }
};
int main()
{
    int n,key,a[1000];
    clock_t start,stop;
    linear L;
    for(int i=0;i<1000;i++)
    {
        a[i]=rand()%100;
        //cout<<a[i]<<endl;
    }
      cout<<"Enter the ele to b searched\n";
    cin>>key;
    start=clock();
    L.search_algo(a,n,key);
    stop=clock();
    cout<<"Time taken"<<(stop-start)/CLK_TCK<<"seconds\n";

}

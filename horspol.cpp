#include<bits/stdc++.h>
using namespace std;
int horspool(char src[],char pat[],int shift[])
{
    int m=strlen(pat);
    int n=strlen(src);
    int i,j,k;
    i=m-1;
    while(i<n)
    {
        k=0;
        while(k<m && (src[i-k]==pat[m-1-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else
            i+=shift[src[i]];
    }
    return -1;
}
int main()
{
    cout<<"Enter the text string : ";
    char str[50],pat[50];
    cin>>str;
    cout<<"\n enter the pattern string : ";
    cin>>pat;
    int shift[200];
    int m=strlen(pat);
     for(int i=0;i<200;i++)
        shift[i]=m;
     for(int i=0;i<m-1;i++)
        shift[pat[i]]=m-1-i;
  int hors=horspool(str,pat,shift);
  if(hors==-1)
    cout<<"\n not found ";
  else
    cout<<"\n found at pos "<<hors+1;
}

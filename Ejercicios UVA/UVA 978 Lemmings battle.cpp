#include<iostream>
#include<cstdlib>
#include <stdlib.h>
#include<cstring>
#include<vector>
using namespace std;

int a[1000000];
long long int  camps , green , blue;
void merge(int *A,int i,int m,int j)
    {
    int b = i , d = m+1 , c = 0;
    while(b <= m &&d <= j){
        if(A[b] >= A[d])
            a[c++] = A[b++];
        else a[c++] = A[d++];
    }
    while(b <= m)a[c++] = A[b++];
    while(d <= j)a[c++] = A[d++];
    memcpy(A+i,a,sizeof(int)*(j-i+1));
    }
void cero(int a[],int b)
{
    for(int i=0 ; i<b ; i++)
        a[i]=0;
}
void merge(int *A,int i,int j)
    {
    if(i == j)return;
    int m = (i+j)/2;
    merge(A,i,m);
    merge(A,m+1,j);
    merge(A,i,m,j);
   }
void fill_in(int a[],int b)
    {
    for(int i = 0 ; i < b ; i++)
        {
        cin>>a[i];
        }
    merge(a,0,b);
    }
void war(int a[], int b[],int c)
    {
    for(int i = 0; i<c ;i++ )
        {
        if(a[i]>b[i])
            {
            a[i] -= b[i];
            b[i] = 0;
            }
        else
            {
            b[i] -= a[i];
            a[i]=0;
            }
        }
    merge(a,0,green);
    merge(b,0,blue);
    }
finish(int a[], int b[])
    {
        int alive=0;
        if(a[0]>b[0])
        {
            cout<<"green wins"<<endl;
            while(a[alive]!=0&&alive<=green)
                cout<<a[alive++]<<endl;
        }
       else if(a[0]<b[0]){
            cout<<"blue wins"<<endl;
            while(b[alive]!=0&&alive<=blue)
                cout<<b[alive++]<<endl;
        }
        else
            cout<<"green and blue died"<<endl;
    }
int main()
{
    int a[100000];
    int b[100000];
    int num;
    cin>>num;
    while(cin>>camps>>green>>blue)
        {
        fill_in(a,green);
        fill_in(b,blue);
        while(a[0] != 0 && b[0] != 0)
            {
            war(a,b,camps);
            }
        finish(a,b);
        cout<<endl;
        cero(a,green);
        cero(b,blue);
        if(num--==0)
            return 0;
        }
return 0;
}

#include <iostream>
using namespace std;

bool binary_search(int *A,int n, int x)
{
	int i=0;
	int j=n-1;
	
	int m=(i+j)/2;
	
	while(i<=j)
	{
		
		if(A[m]==x)
		{
			return true;
		}
		
		else if(A[m]<x)
		{
			i=m+1;
		}
		
		else
		{ 
			j=m-1;
		}
		m=(i+j)/2;
	}
	return -1;
}

bool linear_search(int *A,int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(A[i]==x)
		{
			return true;
		}
	}
	return -1;
}

void insertionSort(int *A, int n) 
{ 
    int i,aux,j; 
    for (i=1;i<n;i++)
	{ 
        aux=A[i]; 
        j=i-1; 

        while(j>=0 && A[j]>aux) 
		{ 
            A[j+1]=A[j]; 
            j=j-1; 
        } 
        A[j+1]=aux; 
    } 
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
   
void bubbleSort(int *A, int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (A[j] > A[j+1]) 
              swap(&A[j], &A[j+1]); 
} 

void selectionSort(int *A, int n) 
{ 
    int i, j,min; 
  
    for (i=0;i<n-1;i++) 
    { 
        min=i; 
        for (j=i+1;j<n;j++) 
          if (A[j]<A[min]) 
            min=j; 
  
        swap(&A[min], &A[i]); 
    } 
} 

 
int main() 
{ 
	int A[]={8,1,25,9,2};
	int x = 8; 
	int n=sizeof(A)/sizeof(A[0]); 
	
	cout<<"Binary search"<<endl;
	int resultado = binary_search(A,n-1,x); 
    (resultado == -1) ? cout<<"El elemento no esta"
	:cout<<"El elemento si esta "<<resultado<<endl;
	
	cout<<"Lineal search"<<endl;
	int result = linear_search(A,n,x); 
    (result == -1) ? cout<<"El elemento no esta"
	:cout<<"El elemento si esta"<<result<<endl;
	
	cout<<"Bubbles sort"<<endl;
	bubbleSort(A,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
	
	cout<<"Selection sort"<<endl;
	selectionSort(A,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
	
	cout<<"Inserction sort"<<endl;
	insertionSort(A,n);  
	
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
	            
} 

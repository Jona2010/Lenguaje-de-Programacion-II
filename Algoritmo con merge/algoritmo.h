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
   
void BubbleSort(int *A, int n) 
{
  bool swapped=true;
  int j=0;
  int aux;
 
  while (swapped) 
  {
    swapped=false;
    j++;
    for(int i=0;i<n-j;++i) 
	{
      if(A[i]>A[i+1]) 
	  {
        aux = A[i];
        A[i] = A[i + 1];
        A[i + 1] = aux;
        swapped = true;
      }
    }
  }
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

void merge(int *A, int l, int m, int r) 
{ 
    int i, j, k; 
    int x=m-l+1; 
    int y=r-m; 
  
    int L[x], R[y]; 
  
    for (i=0;i<x;i++) 
        L[i] = A[l+i]; 
    for (j=0;j<y;j++) 
        R[j] = A[m+1+j]; 
  
    i=0;
    j=0; 
    k=l; 

    while(i<x && j<y) 
    { 
        if(L[i]<=R[j]) 
        { 
            A[k]=L[i]; 
            i++; 
        } 
        else
        { 
            A[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while(i<x) 
    { 
        A[k]=L[i]; 
        i++; 
        k++; 
    } 
  
    while (j<y) 
    { 
        A[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int *A,int l,int r) 
{ 
    if(l<r) 
    {  
        int m=l+(r-l)/2; 
        
        mergeSort(A,l,m); 
        mergeSort(A,m+1,r); 
  
        merge(A,l,m,r); 
    }
} 

void mergeSort(int *A, int n)
{
    mergeSort(A,0,n-1);
}

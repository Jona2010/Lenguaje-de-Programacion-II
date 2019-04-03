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

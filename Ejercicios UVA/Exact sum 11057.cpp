#include <iostream>
#include <algorithm>

using namespace std;

int books[10000];

int main()
{
    int N;//numero de libros
	int M;//cantidad de dinero de peter
    
    while (cin>>N)
    {
        for (int i=0;i<N;++i)
            cin>>books[i];
        
        sort(books,books + N);
        
        cin>>M;
        
        int i=0,j=N-1;
        int aux1, aux2;
        while (i < j)
        {
            if (books[i] + books[j] < M)
                ++i;
            else if (books[i] + books[j] == M)
            {
                aux1=i;
                aux2=j;
                ++i;
				--j;
            }
            else
                --j;
        }
        
        cout<<"Peter should buy books whose prices are "<< books[aux1]<<" and "<<books[aux2]<<".\n\n";
    }
}

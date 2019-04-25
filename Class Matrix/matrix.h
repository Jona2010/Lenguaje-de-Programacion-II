#include <iostream>
#include <cstdlib>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

#define BYTE unsigned char

template<class T>
class Matrix
{
	private:
		int row,col;
	
	public:
		T* term=new T[row*col];
		Matrix(){} //constructor por defecto
		
		Matrix(int r,int c):row(r),col(c)
		{
			term=new T[row*col];
		}
		
		//constructor
		Matrix(int row,int col,T* a):Matrix(row,col)
		{
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					term[i*col+j]=a[i*col+j];
		}
		
		//2D constructor
		Matrix(int row,int col,T** m):Matrix(row,col)
		{
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					term[i*col+j]=m[i][j];
		}
		
		//<class T> r Matrix
		Matrix(int row,int col, T r):Matrix(row,col)
		{
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					term[i*col+j]=r;
		}
		
		T& operatir()(int i,int j)
		{
			return term[i*col+j];
		}
		
		void print()
		{
			cout<<"=======================================================";
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)}
				{
					cout<<term[i*col+j]<<"\t";
				}
				cout<<endl;
		}
		
		//private
		friend Matrix operator+(Matrix& A,Matrix& B)
		{
			Matrix C(A.row,A.col);
			for(int i=0;i<A.row;i++)
			{
				for(int j=0;j<A.col;j++)
				C(i,j)=(T)((T)A(i,j)+(T)B(i,j));
			}
			return C;
		}
		
		friend Matrix operator/(Matrix& A, const int r)
		{
			Matrix C(A.row,A.col);
			for(int i=0;i<A.row;i++)
			{
				for(int j=0;j<A.col;j++)
				C(i,j)=(T)(A(i,j)/r);
			}
			return C;
		}
		
		template<class S>
		friend Matrix operator*(Matrix A,const S r)
		{
			Matrix C(A.row,A.col);
			for(int i=0;i<A.row;i++)
			{
				for(int j=0;j<A.col;j++)
				C(i,j)=(T)(A(i,j)*r);
			}
			return C;
		}
	friend class ImageMatrix;			
};

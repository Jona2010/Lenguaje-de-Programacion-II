#include <iostream>
#include <cassert>
using namespace std;

template <class T>
Matrix<T> :: Matrix(size_t n_row, size_t n_column)
{
	n_rows=n_row;
	n_columns=n_column;
	M = new T [n_rows*n_columns];
}

template <class T>
Matrix<T> :: ~Matrix()
{
	delete [] M;
}

template <class T>
Matrix<T> :: Matrix(const Matrix<T> & dat);
{
	n_rows=dat.n_rows;
	n_columns=dat.n_columns;
	M = new T [n_rows*n_columns];
	for(int i=0;i<n_columns;i++)
	{
		for(int j=0;j<n_rows;j++)
		{
			M [j*n_rows+i] = dat.M[j*n_rows+i];
		}
	}
}

template <class T>
t & Matrix<T> :: operator() (size_t i, size_t j)
{
	assert(i<n_rows && j<n_columns);
	return M [j*n_rowns+i];
}

template <class T>
Matrix<T> Matrix<T> :: operator + (const Matrix<T> & dat)
{
	assert(n_rows == dat.n_rows && n_columns == dat.n_columns);
	Matrix <T> matrix;
	matrix.n_rows = dat.n_rows;
	matrix.n_columns = dat.n_columns;
	matrix.M = new T [matrix.n_rows*matrix.n_columns];
	
	for(int i=0;i<n_rows;i++)
	{
		for(int j=0;j<n_columns;j++)
		{
			matrix.M [j*matrix.n_rows+i]= M [j*n_rows+i] + dat.M [j*dat.n_rows+i]; 
		}
	}
}

template <class T>
Matrix<T> Matrix<T> :: operator * (const Matrix<T> & dat)
{
	assert(n_columns == dat.n_rows);
	Matrix <T> matrix;
	matrix.n_rows = n_rows;
	matrix.n_columns = dat.n_columns;
	matrix.M = new T [matrix.n_rows*matrix.n_columns];
	T suma = 0;
	
	for(int i=0;i<n_rows;i++)
	{
		for(int j=0;j<n_columns;j++)
		{
			for(int l=0;l<n_columns;l++)
			{
				suma = suma+ (M[l*n_rows+i] * dat.M [j*dat.n_rows+l]);
			}
			
			matrix.M [j*matrix.n_rows+i] = suma;
			suma = 0;
		}
	}
	
	return matrix;
}

template <class T>
Matrix<T> & Matrix<T> :: operator << (const T v)
{
	if(row<n_rows)
	{
		M [column*n_rows+row]=v;
		
		if(column<n_columns-1)
		{
			column++;
		}
		
		else
		{
			row++;
			column=0;
		}
	}
	
	return *this;
}

template <class T>
ostream & operator << (ostream & os, const Matrix<T> & dat)
{
	for(int i=0;i<dat.n_rows;i++)
	{
		for(int j=0;j<dat.n_columns;j++)
		{
			os<<dat.M [j*dat.n_rows+i]<<" ";
		}
		
		os<<endl;
	}
	
	return os;
}


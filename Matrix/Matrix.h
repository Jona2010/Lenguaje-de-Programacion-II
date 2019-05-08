#ifndef Matrix_h
#define Matrix_h
#include <iostream>
using namespace std;

template<class T>
class Matrix;

template<class T>
ostream operator<<(ostream & os, const Matrix<T> & dat);

template<class T>
class Matrix
{
	private:
		T* M;
		size_t n_rows;
		size_t n_columns;
		int row=0;
		int column=0;
		friend ostream & operator << <>(ostream & os,const Matrix<T> & dat);
 	
	public:
		Matrix(size_t n_row=0, size_t n_column=0);
		Matrix(const Matrix<T> & dat);
		~Matrix();
		T & operator()(size_t i,size_t j);
		Matrix<T> operator + (const Matrix<T> & dat);
		Matrix<T> operator * (const Matrix<T> & dat);
		Matrix<T> operator << (const T v);			
};

#include "Matrix.inl"
#endif

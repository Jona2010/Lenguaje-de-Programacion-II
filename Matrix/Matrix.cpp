#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix<int> matrix_1(2,2);
	matrix_1<<8<<1<<0<<4;
	Matrix<int> matrix_2(2,2);
	matrix_2<<1<<0<<0<<1;
	cout<<matrix_1+matrix_2;
	cout<<matrix_1*matrix_2;
	cout<<matrix_1(0,1);
	return 0;
}

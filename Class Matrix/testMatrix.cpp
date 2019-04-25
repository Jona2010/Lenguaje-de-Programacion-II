#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <ctime>
#include "matrix.h"
using namespace std;

int main()
{
	mt19937_64 gen(clock());
	uniform_int_distribution<> m(0,255);
	
	int N=10;
	cout<<dec;
	
	Matrix<int> A(N,N),B(N,N),C(N,N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			A(i,j)=m(gen);
			B(i,j)=m(gen);
		}
	
	A.print();
	B.print();
	C=A+B;
	C.print();
	C=A*3;
	C.print();
	C=A/3;
	C.print();
	
	string mm[6]={"hello","left","right","what","people","why"};
	Matrix<string> D(2,3,mm);
	D.print();
	Matrix<string> E=D+D;
	E.print();
	E=E+D;
	E.print();
	system("Pause");
	return 0;	
}

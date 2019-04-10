#include <iostream>
#include <iomanip> 
#include <cmath>
#include <cstdio>
#define EPS 1e-8

using namespace std;

int p, q, r, s, t, u;

double f(double x) 
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double bisection() 
{
	double xl=0,xu=1;
	while (xl+EPS<xu) 
	{
		double x=(xl+xu)/2;
		if (f(xl)*f(x)<=0)
			xu=x;
		else
			xl=x;
	}
}

int main(void) 
{
	while(cin>>p>>q>>r>>s>>t>>u) 
	{
		if (f(0)*f(1)>0)
			cout<<"No solution"<<endl;
		else
			//printf("%.4f\n", bisection());//
			cout<<setprecision(4)<<bisection()<<'\n';
	}

	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<"Valor de a: "<<a<<endl<<"Valor de b: "<<b<<endl;
	
	a=a+b;
	b=a-b;
	a=a-b;
	
	cout<<"Valor de a: "<<a<<endl;
	cout<<"Valor de b: "<<b<<endl;
}

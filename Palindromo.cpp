#include <iostream>
using namespace std;

int main()
{
	int A=0;
	string palabra;
	cin>>palabra;
	int B=palabra.length()-1;
	int x=B/2;
	
	while(palabra[A]==palabra[B])
	{
		if(x==A){
		cout<<"Palindromo";
		break;
		}
	B--;
	A++;	
	}
	
	if(x!=A){
	cout<<"No palindromo";
	return 0;
	}
}



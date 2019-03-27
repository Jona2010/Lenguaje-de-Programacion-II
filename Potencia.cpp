#include <iostream>
using namespace std;

int potencia(int x, int y)
{
    if(y==0)
    {
        return 1;
    }
    
    else
    {
        int aux=potencia(x,y/2);
        
        if(y%2==0)
        {
            return aux*aux;
        }
        else
        {
            return x*aux*aux;
        }
    }
}

int main()
{
    cout<<"el resultado es: "<<potencia(10,6)<<endl;
    return 0;
}


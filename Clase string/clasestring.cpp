#include "my_stringlab.h"

using namespace std;

String::String () 				//Constructor por defecto
{
    length = 0;
    palabra  = new char[0];
}

String::String (char c) 		//Constructor
{
    length = 1;
    palabra  = new char(c);
}

String::String (const char* c) 	//Toma en un string y crea un objeto (string)
{
    if (c) 
    {
        unsigned n = 0;
        while (c[n] != '\0') 
			n++;
			
        length = n;
        palabra  = new char[n];
        for (unsigned j=0; j < n; j++)
            palabra[j] = c[j];
    } else 
    {
        length = 0;
        palabra   = new char[0];
    }
}

String::String (const String& s) 		//Constructor de copia
{
    length = s.leng();
    palabra   = new char[length];
    for (unsigned j=0; j < length; j++)
        palabra[j] = s[j];
}



String::~String ( ) 
{
    delete[] palabra;			//Destructor 
}


//MÉTODOS BÁSICOS

unsigned String::leng ( ) const 		// longitud constante
{
    return length;
   
}

int String::indice (char c) const 		// Encontrar el índice de char (localización) 
{
    for (unsigned j=0; j < length; j++)
        if (palabra[j] == c) 
			return (int)j;
    	else
    		return -1;			//cout<<"Esa letra "<<c<<" no se encuentra en el string"<<endl;
}

bool String::vacio()
{
	if(palabra[0] == '\0' && length <= 1){
		return true;
	}
	else {return false;}
}

String String::substr(int indice, int leng)	//indice = de donde empieza,  leng= cuantas letras tendrá el substr
{
    unsigned leng2 = leng;
    if(leng2 > this->leng()- indice){leng2=this->leng()- indice;}
    int j = 0;
 
    String str;
    delete[]str.palabra;
    str.length = leng2 + 1;
    str.palabra = new char[str.length];
    for(int i = indice, j = 0; j < leng2; i++, j++)
    {
        str.palabra[j]=palabra[i];
    }
    str.palabra[leng2]= '\0';
    return str;
}
//  OPERADORES STREAM

ostream& operator<< (std::ostream& os, const String& s) 	//cout << String 
{
    if (s.leng() > 0) 
    {
        for (unsigned j=0; j < s.leng(); j++)
            os << s[j];
    } else os << "";

    return os;
}

istream& operator>> (std::istream& is, String& s) 		//cin >> String
{
    char* c = new char[1000];
    is >> c;
    s = String(c);
    delete[] c;
    
    return is;
}

//OPERADORES DE ACCESO

char String::operator[] (unsigned j) const 		// Acceso de referencia
{
    if (j >= length) throw 1;
    return palabra[j];
}

char& String::operator[] (unsigned j) 			//Copia acceso
{
    if (j >= length) throw 1;
    return palabra[j];
}


String& String::operator= (const String& s) 	// Asigna nuevo String
{
    if(this == &s) 
		return *this;

    delete palabra;
    
    length = s.leng();
    palabra   = new char[length];
    
    for (unsigned j=0; j < length; j++)
        palabra[j] = s[j];
    return *this;
}

bool operator== (const String& izq, const String& der)  //Igualdad de ambos string
{
    if (izq.leng() != der.leng()) 
		return false;

    unsigned cap = izq.leng();
    unsigned   n = 0;
    while ((n < cap) && (izq[n] == der[n])) 
		n++;
    return (n == cap);
    return true;
}





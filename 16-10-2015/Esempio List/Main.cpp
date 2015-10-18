#include "Console.h"

using namespace std;

/*===================================================================================================
Insertion Sort di un vettore gestito in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Ordina un Array dinamicamente (InsectionSort)
Data    		: 10/10/2015

To Do:
- Dividere la classe dal main -include-
-----------------------------------------------------------------------------------------------------*/

//#include "Array.cpp"

int main(){
    list<int> Container;
    int Val;

    for ( int i = 0; i < 10; i++){
        Val = (int)((float)rand()/RAND_MAX*10);
        Container.push_back(Val);
    }
    list <int>::iterator it1;
	for ( it1=Container.begin(); it1!= Container.end(); it1++){
		cout << "elemento della lista: " << *it1 << endl;
    }
    return 0;
}

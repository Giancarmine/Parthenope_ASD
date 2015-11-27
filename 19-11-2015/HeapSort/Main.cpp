#include "Console.h"

using namespace std;

/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: HeapSort [Slide 18]
Data    		: 19/11/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

#include "Array.cpp"

int main(){
    Array A;
    int N;
    srand((unsigned)time(0));

    //Faccio decidere la grandezza del array
    cout << "Inserisci la grandezza del Array: ";
    cin >> N ;
    A.GetLength ( N );
    //Alloco e carico dinamicamente l'Array
    A.Carica ();
    cout << "L`Array generato e`: " << endl;
    A.Stampa ();
    //Ordinamento
    A.HeapSort ();

    cout << "L`Array ordinato e`: " << endl;
    A.Stampa ();

    return 0;
}

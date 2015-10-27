#include "Console.h"

using namespace std;

/*===================================================================================================
Quick Sort di un vettore gestito in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Ordina un Array dinamicamente (QuickSort)
Data    		: 22/10/2015

To Do:
- Pass in class length
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
    A.QuickSort ();

    cout << "L`Array ordinato e`: " << endl;
    A.Stampa ();

    return 0;
}

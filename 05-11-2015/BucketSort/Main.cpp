#include "Console.h"

using namespace std;

/*===================================================================================================
MergeSort In Place di un vettore gestito in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Ordina un Array dinamicamente (BucketSort)
Data    		: 5/11/2015

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
    A.BucketSort ();

    cout << "L`Array ordinato e`: " << endl;
    A.Stampa ();

    return 0;
}

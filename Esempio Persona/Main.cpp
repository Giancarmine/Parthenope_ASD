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

#include "Array.cpp"

int main(){
    Array A;
    int N;
    srand((unsigned)time(0));

    //Faccio decidere la grandezza del array
    cout << "Inserisci la grandezza del Array: ";
    cin >> N ;
    //Alloco e carico dinamicamente l'Array
    A.Carica (N);

    cout << "L`Array generato e`: " << endl;
    A.Stampa (N);
    //Ordinamento
    A.InsectionSort (N);

    cout << "L`Array ordinato e`: " << endl;
    A.Stampa (N);

    return 0;
}

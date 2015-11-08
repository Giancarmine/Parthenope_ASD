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
    Array A, B;
    int N, M;
    srand((unsigned)time(0));

    //Faccio decidere la grandezza del array
    cout << "Inserisci la grandezza del Primo Array: ";
    cin >> N ;
    //Alloco e carico dinamicamente l'Array
    A.Carica (N);

    //Faccio decidere la grandezza del array
    cout << "Inserisci la grandezza del Secondo Array: ";
    cin >> M ;
    //Alloco e carico dinamicamente l'Array
    B.Carica (M);

    //Stampo gli Array allo stato Attuale
    cout << "Il Primo Array generato e`: " << endl;
    A.Stampa (N);
    cout << "Il Secondo Array ordinato e`: " << endl;
    B.Stampa (M);

    return 0;
}

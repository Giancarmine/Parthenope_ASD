#include "Console.h"

using namespace std;

/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Esecizio di Anagrafica -Slide ASD Lez.7-
Data    		: 10/10/2015

To Do: -Complete-
- Class in altro file
-----------------------------------------------------------------------------------------------------*/

#include "Anagrafica.cpp"

int main(){
    Studente Stud;
    char Risp;
    int Cod;
    string Cognome, Nome;


    cout << "Inserisci il Codice: ";
    cin >> Cod ;
    Stud.Inserisci_Codice (Cod);

    cout << "Inserisci il Cognome: ";
    cin >> Cognome ;
    Stud.Inserisci_Cognome (Cognome);

    cout << "Inserisci il Nome: ";
    cin >> Nome ;
    Stud.Inserisci_Nome (Nome);

    Stud.Registra ();

    cout << "Promosso S/N: " << endl;
    cin >> Risp;

    if (Risp = 'S'){
        Stud.Promuovi ();
    }

    Stud.Mostra ();
    Stud.Controlla ();
    return 0;
}

#include "Console.h"

using namespace std;

/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Esecizio DVD -Slide ASD Lez.5-
Data    		: 11/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

#include "DVD.cpp"

int main(){
    DVD New;
    int Cod;
    string Art, Edit, Gen;
	float Cost;
	double Scaff, Anno;


    cout << "Inserisci il Codice: ";
    cin >> Cod ;
    New.Inserisci_Codice (Cod);

    cout << "Inserisci l`Artista: ";
    cin >> Art ;
    New.Inserisci_Artista (Art);

    cout << "Inserisci l`Editore: ";
    cin >> Edit ;
    New.Inserisci_Editore (Edit);
	
	cout << "Inserisci il Genere: ";
    cin >> Gen ;
    New.Inserisci_Genere (Gen);

    cout << "Inserisci il Costo: ";
    cin >> Cost ;
    New.Inserisci_Costo (Cost);

    cout << "Inserisci lo Scaffale: ";
    cin >> Scaff ;
    New.Inserisci_Scaffale (Scaff);
	
	cout << "Inserisci l`Anno: ";
    cin >> Anno ;
    New.Inserisci_AnnoProd (Anno);

    New.Registra ();

    New.Stampa ();
    return 0;
}

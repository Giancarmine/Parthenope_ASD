#include "Console.h"

using namespace std;

/*===================================================================================================
BST in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: BST -Alberi Binari Di Ricerca- (Slide 19)
Data    		: 26/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

#include "BST.cpp"

int main() {
    //Dichiaro la Radice dell'Albero
    BST < int > A;
    int Tasto       ;
    //A.CreateNODO (5);
    //Menù delle scelte


    do{
        //Pulisco lo schermo -Win/Linux-
        system(CLEAR);
        cout << "/======================Gestione Albero Binario Di Ricerca===============" << endl;
        cout << endl << endl;
        cout << " [1] - Inserisci Elemento nell`Albero" << endl;
        cout << " [2] - Stampa l`ABR" << endl;
        cout << " [3] - Elimina Elemento dall`Albero" << endl;
        cout << " [4] - Ricerca" << endl;
        cout << " [3] - Elimina Elemento dall`Albero" << endl;
        cout << " [4] - Ricerca" << endl;
        cout << endl << endl;
        cout << " [0] - Esci" << endl << endl;
        cout << "Seleziona : ";
        cin >> Tasto;
        switch( Tasto )
        {
            case 1 :
                system(CLEAR);
                break;
            case 2 :
                system(CLEAR);
                break;
            case 3 :
                system(CLEAR);
                break;
            case 4 :
                system(CLEAR);
                break;
        }
    }
    while ( Tasto != 0 );
    return 0;
}


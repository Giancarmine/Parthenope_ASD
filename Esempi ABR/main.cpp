#include "Console.h"

using namespace std;

/*===================================================================================================
ABR in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: ABR -Alberi Binari Di Ricerca-
Data    		: 03/11/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

#include "ABR.cpp"

int main() {
    //Nodi dell'Albero
    ABR < char > Root, B, C, D, E, F, G;

    //Foglie
    F.Build ( NULL, NULL, 'F' );    G.Build ( NULL, NULL, 'G' );
    C.Build ( NULL, NULL, 'C' );    E.Build ( NULL, NULL, 'E' );
    //Rami
    B.Build ( & F, & G, 'B' );    D.Build ( & C, & E, 'D' );
    //Radice
    Root.Build ( & B, & D, 'R' );

    Root.Show ( & Root, Root.Height ( & Root ) );
    cout << "Height = " << Root.Height ( & Root ) << endl;
    cout << "Count = " << Root.Count ( & Root ) << endl;
    cout << "Visitati in Ordine: " << endl;
    Root.Traverse ( & Root );

    return 0;
}


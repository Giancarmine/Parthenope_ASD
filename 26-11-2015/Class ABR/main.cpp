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
        cout << "======================Gestione Albero Binario Di Ricerca======================" << endl;
        cout << endl << endl;
        cout << " [1] - Inserisci Elemento nell`Albero" << endl;
        cout << " [2] - Stampa l`ABR" << endl;
        cout << " [3] - Elimina Elemento dall`Albero" << endl;
        cout << " [4] - Ricerche" << endl;
        cout << " [5] - Rotazioni" << endl;
        cout << endl << endl;
        cout << " [0] - Esci" << endl << endl;
        cout << "Seleziona : ";
        cin >> Tasto;
        switch( Tasto ){
            case 1 :    //Inserimento
                system(CLEAR);
                break;
            case 2 :    //Stampa l`ABR
                do{
                    system(CLEAR);
                    cout << "======================Stampa l`ABR======================" << endl;
                    cout << endl << endl;
                    cout << " [1] - Stampa IN-Order" << endl;
                    cout << " [2] - Stampa POST-Order" << endl;
                    cout << " [3] - Stampa PRE-Order" << endl;
                    cout << endl << endl;
                    cout << " [0] - Esci" << endl << endl;
                    cout << "Seleziona : ";
                    cin >> Tasto;
                    switch( Tasto ){
                        case 1 :
                            system(CLEAR);
                            break;
                        case 2 :
                            system(CLEAR);
                            break;
                        case 3 :
                            system(CLEAR);
                            break;
                    }
                }
                while ( Tasto != 0 );
                cin.clear();
                Tasto = -1;
                break;
            case 3 :    //Eliminazione
                system(CLEAR);
                break;
            case 4 :    //Ricerche
                do{
                    system(CLEAR);
                    cout << "======================Ricerche======================" << endl;
                    cout << endl << endl;
                    cout << " [1] - Ricerca un elemento" << endl;
                    cout << " [2] - Ricerca il Minimo" << endl;
                    cout << " [3] - Ricerca il Massimo" << endl;
                    cout << endl << endl;
                    cout << " [0] - Esci" << endl << endl;
                    cout << "Seleziona : ";
                    cin >> Tasto;
                    switch( Tasto ){
                        case 1 :
                            system(CLEAR);
                            break;
                        case 2 :
                            system(CLEAR);
                            break;
                        case 3 :
                            system(CLEAR);
                            break;
                    }
                }
                while ( Tasto != 0 );
                cin.clear();
                Tasto = -1;
                break;
            case 5 :    //Rotazioni
                do{
                    system(CLEAR);
                    cout << "======================Rotazioni======================" << endl;
                    cout << endl << endl;
                    cout << " [1] - Rotazione a DX" << endl;
                    cout << " [2] - Rotazione a SX" << endl;
                    cout << endl << endl;
                    cout << " [0] - Esci" << endl << endl;
                    cout << "Seleziona : ";
                    cin >> Tasto;
                    switch( Tasto ){
                        case 1 :
                            system(CLEAR);
                            break;
                        case 2 :
                            system(CLEAR);
                            break;
                    }
                }
                while ( Tasto != 0 );
                cin.clear();
                Tasto = -1;
                break;
        }
    }
    while ( Tasto != 0 );
    cin.clear();
    return 0;
}


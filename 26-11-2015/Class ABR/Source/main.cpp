#include "Console.h"
#include "BST.h"

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
    int Key;
    int Tasto;

    //Menù delle scelte
    do{
        //Pulisco lo schermo -Win/Linux-
        system ( CLEAR );
        cout << "======================Gestione Albero Binario Di Ricerca======================" << endl;
        cout << endl << endl;
        cout << " [1] - Inserisci Elemento nell`Albero" << endl;
        cout << " [2] - Stampa l`ABR" << endl;
        cout << " [3] - Eliminazioni" << endl;
        cout << " [4] - Ricerche" << endl;
        cout << endl << endl;
        cout << " [0] - Esci" << endl << endl;
        cout << "Seleziona : ";
        cin >> Tasto;
        switch ( Tasto ){
            case 1 :    //Inserimento
                system ( CLEAR );
                cout << " Inserisci il valore da Inserire: ";
                cin >> Key;
                //Carico un'NODO e lo attacca in modo corretto al Albero
                A.CreateNODO ( Key );
                system("pause"); // "Press enter"
                break;
            case 2 :    //Stampa l`ABR
                do{
                    system ( CLEAR );
                    cout << "======================Stampa l`ABR======================" << endl;
                    cout << endl << endl;
                    cout << " [1] - Stampa IN-Order" << endl;
                    cout << " [2] - Stampa POST-Order" << endl;
                    cout << " [3] - Stampa PRE-Order" << endl;
                    cout << endl << endl;
                    cout << " [0] - Esci" << endl << endl;
                    cout << "Seleziona : ";
                    cin >> Tasto;
                    switch ( Tasto ){
                        case 1 :    //Stampa IN-Order
                            system (CLEAR);
                            A.InOrderVisit ( A.GetRoot () );
                            cout << endl;
                            system("pause"); // "Press enter"
                            break;
                        case 2 :    //Stampa POST-Order
                            system (CLEAR);
                            A.PostOrderVisit ( A.GetRoot () );
                            cout << endl;
                            system("pause"); // "Press enter"
                            break;
                        case 3 :    //Stampa PRE-Order
                            system (CLEAR);
                            A.PreOrderVisit ( A.GetRoot () );
                            cout << endl;
                            system("pause"); // "Press enter"
                            break;
                    }
                }
                while ( Tasto != 0 );
                cin.clear ();
                Tasto = -1;
                break;
            case 3 :    //Eliminazione
                system ( CLEAR );
                cout << " Inserisci il valore da Eliminare: ";
                cin >> Key;
                A.EliminaElemento ( A.GetRoot (), Key );
                system("pause"); // "Press enter"
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
                        case 1 :    //Ricerca un`Elemento
                            system ( CLEAR );
                            cout << "Inserisci il Valore da Ricercare: ";
                            cin >> Key;
                            if ( A.SearchKey ( A.GetRoot (), Key ) ){
                                cout << "L`Elemento e`Presente" << endl;
                            }
                            else{
                                cout << "L`Elemento NON e`presente nell`Albero" << endl;
                            }
                            cout << endl;
                            system("pause"); // "Press enter"
                            break;
                        case 2 :
                            system(CLEAR);
                            if ( A.GetRoot () ){
                                cout << "L`Elemento e`: " << A.Minimo ( A.GetRoot () ) <<  endl;
                            }
                            else{
                                cout << "L`Albero E`Vuoto!" << endl;
                            }
                            cout << endl;
                            system("pause"); // "Press enter"
                            break;
                        case 3 :
                            system(CLEAR);
                            if ( A.GetRoot () ){
                                cout << "L`Elemento e`: " << A.Massimo ( A.GetRoot () ) <<  endl;
                            }
                            else{
                                cout << "L`Albero E`Vuoto!" << endl;
                            }
                            cout << endl;
                            system("pause"); // "Press enter"
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


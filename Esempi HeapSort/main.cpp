#include "Console.h"

using namespace std;

/*===================================================================================================
HeapSort [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: HeapSort
Data    		: 03/11/2015

To Do:
 - Inserimento
 - Eliminazione
 - Max-Heapify
 - Increase Key
 //Con Eliminazione
 - Extract-Max
 //TROVA
 - MAXIMUM
 -HEAPSORT
-----------------------------------------------------------------------------------------------------*/


#include "HeapSort.cpp"

int main() {
    //Nodi dell'Albero
    Heap < int > Root, B, C, D, E, F, G;

    //Foglie
    F.Build ( NULL, NULL, & B, 64 );    G.Build ( NULL, NULL, & B, 43 );
    C.Build ( NULL, NULL, & D, 394 );    E.Build ( NULL, NULL, & D, 3 );
    //Rami
    B.Build ( & F, & G, & Root, 48 );    D.Build ( & C, & E, & Root, 93 );
    //Radice
    Root.Build ( & B, & D, NULL, 111 );

        cout<<" HEAPSORT "<<endl;
		cout<<" ----------------------------- "<<endl;
		cout<<" 1. Inserimento "<<endl;
		cout<<" 2. MAX-Heapify "<<endl;
		cout<<" 3. Increase Key "<<endl;
		cout<<" 4. Estrazione del Massimo "<<endl;
        cout<<" 5. Stampa "<<endl;
		cout<<" 6. Uscita "<<endl;
		cout<<" Inserisci la tua scelta : ";
		cin>>ch;
		switch(ch)
		{
		case 1: cout<<" Enter data to be inserted : ";
                cin.ignore(1);
                cin>>tmp;
                b.insert(tmp);
                break;
		case 2: cout<<endl;
                cout<<" Attraversamento In-Order "<<endl;
                cout<<" -------------------"<<endl;
                b.print_inorder();
                break;
		case 3: cout<<endl;
                cout<<" Pre-Order Traversal "<<endl;
                cout<<" -------------------"<<endl;
                b.print_preorder();
                break;
		case 4: cout<<endl;
                cout<<" Post-Order Traversal "<<endl;
                cout<<" --------------------"<<endl;
                b.print_postorder();
                break;
		case 5: cout<<" Enter data to be deleted : ";
                cin.clear();
                cin.ignore(1);
                cin>>tmp1;
                b.remove(tmp1);
                break;
		case 6: cout<<" Enter data to be searched : ";
                cin.ignore(1);
                cin>>tmp;
                b.search(tmp);
                break;
		case 7: system("pause");
                return 0;
                break;
		}

    Root.Show ( & Root, Root.Height ( & Root ) );
    cout << "Height = " << Root.Height ( & Root ) << endl;
    cout << "Count = " << Root.Count ( & Root ) << endl;
    cout << "Visitati in Ordine: " << endl;
    Root.Traverse ( & Root );

    return 0;
}


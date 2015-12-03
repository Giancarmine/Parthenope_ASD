#include "HeapSort.h"

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


//Stampa l'Elemento contenuto nel nodo visitato
template< typename  Filler >
void Heap < Filler > :: StampaElem ( Filler Elem ){
    cout << "Nodo visitato = " << Elem << endl;
}

//Attraversa l'Albero
template < typename  Filler>
void Heap < Filler > :: Traverse ( Heap < Filler > * Nodo ){
    if ( ! Nodo ) return;

    StampaElem ( Elem );
    Left->Traverse ( Left );
    Right->Traverse ( Right );
}

//Conta il numero di nodi nel albero
template < typename Filler>
int Heap < Filler > :: Count ( Heap < Filler > * Nodo ){
    if ( ! Nodo ) return 0;

    return (Left->Count ( Left ) + Right->Count ( Right ) + 1);
}

//Calcola l'Altezza dell'Albero
template < typename Filler>
int Heap < Filler > :: Height ( Heap < Filler > * Nodo ){
    if ( ! Nodo ) return 0;
    int U = Left->Height ( Left ), V = Right->Height( Right );

    if ( U > V)
        return U+1;
    else
        return V+1;
}

//Stampa il nodo shiftato in base all'Altezza
template < typename Filler>
void Heap < Filler > :: PrintNode ( Filler X, int H ){
    for ( int i=0; i < H; i++ )  cout << " ";
    cout << X << endl;
}

//Stampa l'intero albero Formattato
template < typename Filler>
void Heap < Filler > :: Show ( Heap < Filler > * Nodo, int H ){
    if ( ! Nodo ) { Nodo->PrintNode ( '*', H ); return;}
    Right->Show ( Right, H+1 );
    Nodo->PrintNode ( Elem, H );
    Left->Show ( Left, H+1 );
}

//Crea Un Nodo
template < typename Filler>
void Heap < Filler > :: Build ( Heap < Filler > * L, Heap < Filler > * R, Heap < Filler > * P, Filler X ){
    Parent = P;
    Left = L;
    Right = R;
    Elem = X;
}

//Ristabilisce le proprietà dell'Heap
template < typename Filler>
void Heap < Filler > :: MaxHeapify ( Heap < Filler > Nodo ){
    if ( ! Nodo ) { return; }
    Heap L = Left;
    Heap R = Right;

    //Se Il nodo è gia il massimo O è una foglia
    if ( Elem >= R->Elem && Elem >= L->Elem ){
        Left.MaxHeapify ( Left );
        Right.MaxHeapify ( Right );
    }
    else {
        if ( R->Elem > Elem ){
            //Switch che R è il max
        }
        else {
            //Switch che L è il max
        }
    }

}

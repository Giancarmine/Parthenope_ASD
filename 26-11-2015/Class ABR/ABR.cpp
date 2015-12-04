#include "ABR.h"

/*===================================================================================================
ABR in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: ABR -Alberi Binari Di Ricerca- (Slide 19)
Data    		: 26/10/2015

To Do:
 - Successivo
 - Precedente
 - Insert
 - Min
 - Max
 - Visita in order
 - Visita Post order
 - Visita Pre Order
-----------------------------------------------------------------------------------------------------*/


//Stampa l'Elemento contenuto nel nodo visitato
template< typename  Filler >
void ABR < Filler > :: StampaElem (){
    cout << "Nodo visitato = " << this->Elem << endl;
}

//Attraversa l'Albero
template < typename  Filler >
void ABR < Filler > :: Traverse (){
    if ( ! this ) return;

    StampaElem ();
    Left->Traverse ();
    Right->Traverse ();
}

//Conta il numero di nodi nel albero
template < typename Filler >
int ABR < Filler > :: Count (){
    if ( ! this ) return 0;

    return (Left->Count () + Right->Count () + 1);
}

//Calcola l'Altezza dell'Albero
template < typename Filler >
int ABR < Filler > :: Height (){
    if ( ! this ) return 0;
    int U = Left->Height (), V = Right->Height ();

    if ( U > V)
        return U+1;
    else
        return V+1;
}

//Stampa il nodo shiftato in base all'Altezza
template < typename Filler >
void ABR < Filler > :: PrintNode ( Filler X, int H ){
    for ( int i=0; i < H; i++ )  cout << " ";
    cout << X << endl;
}

//Stampa l'intero albero Formattato
template < typename Filler >
void ABR < Filler > :: Show ( int H ){
    if ( ! this ) { this->PrintNode ( '*', H ); return; }
    Right->Show ( H+1 );
    this->PrintNode ( Elem, H );
    Left->Show ( H+1 );
}

//Crea Un Nodo
template < typename Filler >
void ABR < Filler > :: Build ( ABR < Filler > * L, ABR < Filler > * R, Filler X ){
    Left = L;
    Right = R;
    Elem = X;
}

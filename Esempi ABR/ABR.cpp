#include "ABR.h"


//Stampa l'Elemento contenuto nel nodo visitato
template< typename  Filler >
void ABR < Filler > :: StampaElem ( Filler Elem ){
    cout << "Nodo visitato = " << Elem << endl;
}

//Attraversa l'Albero
template < typename  Filler>
void ABR < Filler > :: Traverse ( ABR < Filler > * Nodo ){
    if ( ! Nodo ) return;

    StampaElem ( Elem );
    Left->Traverse ( Left );
    Right->Traverse ( Right );
}

//Conta il numero di nodi nel albero
template < typename Filler>
int ABR < Filler > :: Count ( ABR < Filler > * Nodo ){
    if ( ! Nodo ) return 0;

    return (Left->Count ( Left ) + Right->Count ( Right ) + 1);
}

//Calcola l'Altezza dell'Albero
template < typename Filler>
int ABR < Filler > :: Height ( ABR < Filler > * Nodo ){
    if ( ! Nodo ) return 0;
    int U = Left->Height ( Left ), V = Right->Height( Right );

    if ( U > V)
        return U+1;
    else
        return V+1;
}

//Stampa il nodo shiftato in base all'Altezza
template < typename Filler>
void ABR < Filler > :: PrintNode ( Filler X, int H ){
    for ( int i=0; i < H; i++ )  cout << " ";
    cout << X << endl;
}

//Stampa l'intero albero Formattato
template < typename Filler>
void ABR < Filler > :: Show ( ABR < Filler > * Nodo, int H ){
    if ( ! Nodo ) { Nodo->PrintNode ( '*', H ); return;}
    Right->Show ( Right, H+1 );
    Nodo->PrintNode ( Elem, H );
    Left->Show ( Left, H+1 );
}

//Crea Un Nodo
template < typename Filler>
void ABR < Filler > :: Build ( ABR < Filler > * L, ABR < Filler > * R, Filler X ){
    Left = L;
    Right = R;
    Elem = X;
}

/*Ricerca di una chiave
ABR * ABR :: KeySearch ( ABR * Nodo, Filler Key ){
    if ( Nodo || Key ==  ) {
        return Nodo;
    }
}
*/

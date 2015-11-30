#include "ABR.h"

//Stampa l'Elemento contenuto nel nodo visitato
void ABR :: StampaElem(ABR Nodo){
    cout << "Nodo visitato = " << Elem << endl;
}

//Attraversa l'Albero
void ABR :: Traverse(ABR Nodo){
    if ( Elem == NULL ) return;
    Nodo.Traverse ( *Left );
    Nodo.Traverse ( *Right );
}

//Conta il numero di nodi nel albero
int ABR :: Count ( ABR Nodo ){
    if ( Elem == NULL ) return 0;
    return ( Nodo.Count( *Left ) + Nodo.Count ( *Right ) +1 );
}

//Calcola l'Altezza dell'Albero
int ABR :: Height ( ABR Nodo ){
    if ( Elem == NULL ) return 0;

    int U = Nodo.Height ( *Left ), V = Nodo.Height( *Right );

    if ( U > V)
        return U+1;
    else
        return V+1;
}

//Stampa il nodo shiftato in base all'Altezza
void ABR :: PrintNode ( char X, int H ){
    for ( int i=0; i < H; i++ )  cout << " ";
    cout << X << endl;
}

//Stampa l'intero albero Formattato
void ABR :: Show ( ABR Nodo, int H ){
    if ( Elem == NULL ) { Nodo.PrintNode ( '*', H ); return;}
    Nodo.Show ( *Right, H+1 );
    Nodo.PrintNode ( Elem, H );
    Nodo.Show ( *Left, H+1 );
}

//Crea Un Nodo
void ABR :: Build ( ABR L, ABR R, char X ){
	*Left = L;
	*Right = R;
	Elem = X;
}

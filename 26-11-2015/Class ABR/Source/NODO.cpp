#include "NODO.h"

/*===================================================================================================
NODO in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Classe templata standard per un NODO
Data    		: 04/12/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

//Inserisce il valore di un elem nel NODO
template < typename  Filler >
void NODO < Filler > :: SetElem ( Filler X ){
    if ( ! this ) return;

    Elem = X;
}

//Restituisce il Valore di elem
template < typename Filler >
Filler NODO < Filler > :: GetElem (){
    if ( ! this ) return 0;

    return Elem;
}

//Collega il Padre al NODO
template < typename  Filler >
void NODO < Filler > :: SetParent ( NODO * P ){
    if ( ! this ) return;

    Parent = P;
}

//Restituisce Padre di NODO
template < typename Filler >
NODO < Filler > * NODO < Filler > :: GetParent (){
    if ( ! this ) return 0;

    return Parent;
}

//Collega un figlio Left al NODO
template < typename  Filler >
void NODO < Filler > :: SetLeft ( NODO * L ){
    if ( ! this ) return;

    Left = L;
}

//Restituisce il figlio Left di NODO
template < typename Filler >
NODO < Filler > * NODO < Filler > :: GetLeft (){
    if ( ! this ) return 0;

    return Left;
}

//Collega un figlio Right al NODO
template < typename  Filler >
void NODO < Filler > :: SetRight ( NODO * R ){
    if ( ! this ) return;

    Right = R;
}

//Restituisce il figlio Right di NODO
template < typename Filler >
NODO < Filler > * NODO < Filler > :: GetRight (){
    if ( ! this ) return 0;

    return Right;
}

//Stampa il Valore di elem
template < typename Filler >
void NODO < Filler > :: PrintNODO (){
    if ( this ){
        std :: cout << "NODO visitato: " << this->GetElem () << std :: endl ;
    }
    else{
        std :: cout << "NODO INESISTENTE!" << std :: endl;
    }
}


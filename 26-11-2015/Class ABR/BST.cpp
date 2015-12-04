#include "BST.h"

/*===================================================================================================
BST in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: BST -Alberi Binari Di Ricerca- (Slide 19)
Data    		: 26/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/


//Crea il NODO
template< typename  Filler >
void BST < Filler > :: CreateNODO ( Filler X ){
    this->Root = new NODO < Filler >;
    if ( this ){
        this->Root->SetElem ( X );
        this->Root->PrintNODO ();
    }
    else{
        cout << "IMPOSSIBILE ALLOCARE IL NODO!!!" << endl;
    }
}

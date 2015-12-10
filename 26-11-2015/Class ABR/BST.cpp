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

//Stampa Visitando InOrder
template< typename  Filler >
void BST < Filler > :: InOrderVisit (){
    if ( this ){
        this->Root->GetLeft ()->InOrderVisit ();
        this->Root->PrintNODO ();
		this->Root->GetRight ()->InOrderVisit ();
    }
    else{
        cout << "L`Albero E`Vuoto!!!" << endl;
    }
}

/*Stampa Visitando PostOrder
template< typename  Filler >
void BST < Filler > :: PostOrderVisit (){
    if ( this ){
        this->Root->GetLeft ()->PostOrderVisit ();
		this->Root->GetRight ()->PostOrderVisit ();
		this->Root->PrintNODO ();
    }
    else{
        cout << "L`Albero E`Vuoto!!!" << endl;
    }
}

//Stampa Visitando PreOrder
template< typename  Filler >
void BST < Filler > :: PreOrderVisit (){
    if ( this ){
        this->Root->PrintNODO ();
        this->Root->GetLeft ()->PreOrderVisit ();
		this->Root->GetRight ()->PreOrderVisit ();
    }
    else{
        cout << "L`Albero E`Vuoto!!!" << endl;
    }
}

//Ricerca rispetto a una Key
template< typename  Filler >
void BST < Filler > :: SearchKey ( Filler Key ){
    while ( X != NULL && K != Key ){
        if ( K < Key ){
            //Go to the Left    X = Left
        }
        else{
            //Go to the Right   X = Right
        }
    }
    return X;
}

//Ricerca il minimo
template< typename  Filler >
int BST < Filler > :: Minimo (){
    //L = this->Left;
    while ( L ){
            //X = Left->Elem;
            //L = this->Left;
    }
    return X;
}

//Ricerca il MASSIMO
template< typename  Filler >
int BST < Filler > :: Massimo (){
    //R = this->Right;
    while ( R ){
            //X = Right->Elem;
            //R = this->Right;
    }
    return X;
}

//Ricerca Sucessore
template< typename  Filler >
int BST < Filler > :: Sucessore (){

}
*/

#include "Console.h"
#include "BST.h"

/*===================================================================================================
BST in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: BST -Alberi Binari Di Ricerca- (Slide 19)
Data    		: 26/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/


//Stampa Visitando InOrder
template< typename  Filler >
void BST < Filler > :: InOrderVisit ( NODO < Filler > * Nodo ){
    //Se esiste l'Albero e c'è almeno un nodo
    if ( this && Nodo ){
        //Se esiste il sinisto
        if ( Nodo->GetLeft () ){
            //Vai a sinistra
            InOrderVisit ( Nodo->GetLeft () );
        }
        else{
            std :: cout << "*" << std :: endl;
        }
        //Stampa il nodo
        Nodo->PrintNODO ();
        if ( Nodo->GetRight () ){
            InOrderVisit ( Nodo->GetRight () );
        }
        else{
            std :: cout << "*" << std :: endl;
        }
    }
    else{
        std :: cout << "*" << std :: endl;
    }
}


//Stampa Visitando PostOrder
template< typename  Filler >
void BST < Filler > :: PostOrderVisit ( NODO < Filler > * Nodo ){
    if ( this && Nodo ){
        if ( Nodo->GetLeft () ){
            PostOrderVisit ( Nodo->GetLeft () );
        }
        else{
            std :: cout << "*" << std :: endl;
        }
		if ( Nodo->GetRight () ){
            PostOrderVisit ( Nodo->GetRight () );
        }
        else{
            std :: cout << "*" << std :: endl;
        }
		Nodo->PrintNODO ();
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
}

//Stampa Visitando PreOrder
template< typename  Filler >
void BST < Filler > :: PreOrderVisit ( NODO < Filler > * Nodo ){
    if ( this && Nodo ){
        Nodo->PrintNODO ();
        //Left
        if ( Nodo->GetLeft () ){
            PreOrderVisit ( Nodo->GetLeft () );
        }
        else{
            std :: cout << "*" << std :: endl;
        }
        //Right
        if ( Nodo->GetRight () ){
            PreOrderVisit ( Nodo->GetRight () );
        }
        else{
            std :: cout << "*" << std :: endl;
        }
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
}

//Ricerca rispetto a una Key
template < typename  Filler >
NODO < Filler > * BST < Filler > :: SearchKey ( NODO < Filler > * Nodo, Filler Key ){
    //Se esiste l'Albero
    if ( this && Nodo ){
        while ( Nodo && Nodo->GetElem () != Key ){
            if ( Key < Nodo->GetElem () ){
                Nodo = Nodo->GetLeft ();
            }
            else{
                Nodo = Nodo->GetRight ();
            }
        }
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
    return Nodo;
}

//Ricerca il minimo
template< typename  Filler >
Filler BST < Filler > :: Minimo ( NODO < Filler > * Nodo ){
    Filler X;
    //Se esiste l'Albero
    if ( this && Nodo ){
        X = Nodo->GetElem ();
        while ( Nodo->GetLeft () ){
            Nodo = Nodo->GetLeft ();
            X = Nodo->GetElem ();
        }
        return X;
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
}

//Ricerca il MASSIMO
template< typename  Filler >
Filler BST < Filler > :: Massimo ( NODO < Filler > * Nodo ){
    Filler X;
    //Se esiste l'Albero
    if ( this && Nodo ){
        X = Nodo->GetElem ();
        while ( Nodo->GetRight () ){
            Nodo = Nodo->GetRight ();
            X = Nodo->GetElem ();
        }
        return X;
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
}

//Crea il NODO
template< typename  Filler >
void BST < Filler > :: CreateNODO ( Filler X ){
    NODO < Filler > * Nuovo;
    Nuovo = new NODO < Filler >;
    if ( Nuovo ){
        Nuovo->SetElem ( X );
        //Nuovo->PrintNODO ();
        Inserimento ( GetRoot (), Nuovo );
        std :: cout << "Nodo Allocato con Successo" << std :: endl << std :: endl;
    }
    else{
        std :: cout << "IMPOSSIBILE ALLOCARE IL NODO!!!" << std :: endl << std :: endl;
    }
}

//Inserimento
template< typename  Filler >        //Radice                   Nuovo Nodo
void BST < Filler > :: Inserimento ( NODO < Filler > * Root, NODO < Filler > * Z ){
    NODO < Filler > * X;
    NODO < Filler > * Y;
    X = Root;
    Y = NULL;
    while ( X ){
        Y = X;
        if ( Z->GetElem () < X->GetElem () ){
            X = X->GetLeft ();
        }
        else{
            X = X->GetRight ();
        }
    }
    Z->SetParent ( Y );
    if ( !Y ){
        this->SetRoot ( Z );
    }
    else{
        if ( Z->GetElem () < Y->GetElem () ){
            Y->SetLeft ( Z );
        }
        else{
            Y->SetRight ( Z );
        }
    }
}

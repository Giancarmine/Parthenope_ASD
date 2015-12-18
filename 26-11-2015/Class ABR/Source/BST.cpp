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
    X = 0;
    //Se esiste l'Albero
    if ( this && Nodo ){
        X = Nodo->GetElem ();
        while ( Nodo->GetLeft () ){
            Nodo = Nodo->GetLeft ();
            X = Nodo->GetElem ();
        }
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
    return X;
}

//Ricerca il MASSIMO
template< typename  Filler >
Filler BST < Filler > :: Massimo ( NODO < Filler > * Nodo ){
    Filler X;
    X = 0;
    //Se esiste l'Albero
    if ( this && Nodo ){
        X = Nodo->GetElem ();
        while ( Nodo->GetRight () ){
            Nodo = Nodo->GetRight ();
            X = Nodo->GetElem ();
        }
    }
    else{
        std :: cout << "L`Albero E`Vuoto!!!" << std :: endl;
    }
    return X;
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

//Inserimento
template< typename  Filler >
NODO < Filler > * BST < Filler > :: Successore ( NODO < Filler > * Nodo, Filler Key ){
    NODO < Filler > * Y;
    Y = NULL;
    while ( Nodo && Nodo->GetElem() != Key ){
        if ( Nodo->GetElem() < Key ){
            Nodo = Nodo->GetRight ();
        }
        else{
            Y = Nodo;
            Nodo = Nodo->GetLeft();
        }
    }
    if ( Nodo && Nodo->GetRight () ){
        return Minimo( Nodo->GetRight() );
    }
    else{
        return Y;
    }
}

//Eliminazione, Primo Caso
template< typename  Filler >
void BST < Filler > :: ElimCasoUno ( NODO < Filler > * Nodo){
    NODO < Filler > * Padre;

    if ( Nodo->GetParent () ){
        Padre = Nodo->GetParent ();
        if ( Padre->GetLeft () == Nodo ){
            Padre->SetLeft ( NULL );
        }
        else {
            Padre->SetRight ( NULL );
        }
        delete Nodo;
        }
    else{
        this->SetRoot ( NULL );
    }
}

//Eliminazione, Secondo Caso
template< typename  Filler >
void BST < Filler > :: ElimCasoDue ( NODO < Filler > * Nodo){
    NODO < Filler > * OldRoot;
    NODO < Filler > * Padre;
    NODO < Filler > * Figlio;

    //Se Non è la radice
    if ( Nodo->GetParent () ){
        Padre = Nodo->GetParent ();
        //Se Nodo è il figlio Sx del Padre
        if ( Padre->GetLeft () == Nodo ){
            //A seconda se il nodo ha figlio SX o DX
            //Rimpiazza il figlio Sx del Padre con mio Figlio
            if ( Nodo->GetLeft () ){
                Padre->SetLeft ( Nodo->GetLeft () );
                Figlio = Nodo->GetLeft ();
                Figlio->SetParent ( Padre );
            }
            else{
                Padre->SetLeft ( Nodo->GetRight () );
                Figlio = Nodo->GetRight ();
                Figlio->SetParent ( Padre );
            }
        }
        //Se Nodo è il figlio Dx del Padre
        else {
            //A seconda se il nodo ha figlio SX o DX
            //Rimpiazza il figlio Dx del Padre con mio Figlio
            if ( Nodo->GetLeft () ){
                Padre->SetRight ( Nodo->GetLeft () );
                Figlio = Nodo->GetLeft ();
                Figlio->SetParent ( Padre );
            }
            else{
                Padre->SetRight ( Nodo->GetRight () );
                Figlio = Nodo->GetRight ();
                Figlio->SetParent ( Padre );
            }
        }
        delete Nodo;
    }
    //Elimina la Radice
    else{
            //A seconda se il nodo ha figlio SX o DX
            //Rimpiazza il figlio Dx del Padre con mio Figlio
            OldRoot = this->GetRoot ();
            if ( Nodo->GetLeft () ){
                this->SetRoot ( Nodo->GetLeft () );
                Figlio = Nodo->GetLeft ();
                Figlio->SetParent ( NULL );
            }
            else{
                this->SetRoot ( Nodo->GetRight () );
                Figlio = Nodo->GetRight ();
                Figlio->SetParent ( NULL );
            }
            delete OldRoot;
    }
}
/*
//Eliminazione, Terzo Caso
template< typename  Filler >
void BST < Filler > :: ElimCasoDue ( NODO < Filler > * Nodo){
    NODO < Filler > * OldRoot;
    NODO < Filler > * Padre;
    NODO < Filler > * Figlio;

    //Se Non è la radice
    if ( Nodo->GetParent () ){
        Padre = Nodo->GetParent ();
        //Se Nodo è il figlio Sx del Padre
        if ( Padre->GetLeft () == Nodo ){
            //A seconda se il nodo ha figlio SX o DX
            //Rimpiazza il figlio Sx del Padre con mio Figlio
            if ( Nodo->GetLeft () ){
                Padre->SetLeft ( Nodo->GetLeft () );
                Figlio = Nodo->GetLeft ();
                Figlio->SetParent ( Padre );
            }
            else{
                Padre->SetLeft ( Nodo->GetRight () );
                Figlio = Nodo->GetRight ();
                Figlio->SetParent ( Padre );
            }
        }
        //Se Nodo è il figlio Dx del Padre
        else {
            //A seconda se il nodo ha figlio SX o DX
            //Rimpiazza il figlio Dx del Padre con mio Figlio
            if ( Nodo->GetLeft () ){
                Padre->SetRight ( Nodo->GetLeft () );
                Figlio = Nodo->GetLeft ();
                Figlio->SetParent ( Padre );
            }
            else{
                Padre->SetRight ( Nodo->GetRight () );
                Figlio = Nodo->GetRight ();
                Figlio->SetParent ( Padre );
            }
        }
        delete Nodo;
    }
    //Elimina la Radice
    else{
            //A seconda se il nodo ha figlio SX o DX
            //Rimpiazza il figlio Dx del Padre con mio Figlio
            OldRoot = this->GetRoot ();
            if ( Nodo->GetLeft () ){
                this->SetRoot ( Nodo->GetLeft () );
                Figlio = Nodo->GetLeft ();
                Figlio->SetParent ( NULL );
            }
            else{
                this->SetRoot ( Nodo->GetRight () );
                Figlio = Nodo->GetRight ();
                Figlio->SetParent ( NULL );
            }
            delete OldRoot;
    }
}



//Se Non è la radice
                    if ( Nodo->GetParent () ){
                        Padre = Nodo->GetParent ();
                        //Se Nodo è il figlio Sx del Padre
                        if ( Padre->GetLeft () == Nodo ){
                            //A seconda se il nodo ha figlio SX o DX
                            //Rimpiazza il figlio Sx del Padre con mio Figlio
                            if ( Nodo->GetLeft () ){
                                Padre->SetLeft ( Nodo->GetLeft () );
                                Figlio = Nodo->GetLeft ();
                                Figlio->SetParent ( Padre );
                            }
                            else{
                                Padre->SetLeft ( Nodo->GetRight () );
                                Figlio = Nodo->GetRight ();
                                Figlio->SetParent ( Padre );
                            }
                        }
                        //Se Nodo è il figlio Dx del Padre
                        else {
                            //A seconda se il nodo ha figlio SX o DX
                            //Rimpiazza il figlio Dx del Padre con mio Figlio
                            if ( Nodo->GetLeft () ){
                                Padre->SetRight ( Nodo->GetLeft () );
                                Figlio = Nodo->GetLeft ();
                                Figlio->SetParent ( Padre );
                            }
                            else{
                                Padre->SetRight ( Nodo->GetRight () );
                                Figlio = Nodo->GetRight ();
                                Figlio->SetParent ( Padre );
                            }
                        }
                        delete Nodo;
                    }
                    //Elimina la Radice
                    else{
                        //A seconda se il nodo ha figlio SX o DX
                        //Rimpiazza il figlio Dx del Padre con mio Figlio
                        OldRoot = this->GetRoot ();
                        if ( Nodo->GetLeft () ){
                            this->SetRoot ( Nodo->GetLeft () );
                            Figlio = Nodo->GetLeft ();
                            Figlio->SetParent ( NULL );
                        }
                        else{
                            this->SetRoot ( Nodo->GetRight () );
                            Figlio = Nodo->GetRight ();
                            Figlio->SetParent ( NULL );
                        }
                        delete OldRoot;
                    }*/



//parti dalla radice, cerca la chiave e poi applica l'eliminazione scegliendo il caso corretto .
template< typename  Filler >
void BST < Filler > :: EliminaElemento ( NODO < Filler > * Nodo, Filler Key ){

    if( this && Nodo ){
        //RICERCA DELLA KEY
        if ( ( Nodo = SearchKey ( Nodo, Key ) ) ){
            //CASO 1: NODO SENZA FIGLI
            if ( !Nodo->GetLeft () && !Nodo->GetRight () ){
                ElimCasoUno( Nodo );
            }
            else{
                //Almeno Uno
                if ( Nodo->GetLeft () && Nodo->GetRight () ){
                    //CASO 3: NODO CON DUE FIGLI
                }
                else{
                    //CASO 2: NODO CON UN FIGLIO
                    ElimCasoDue( Nodo );
                }
            }
            std :: cout << "Elemento Eliminato con successo" << std :: endl;
        }
        else {
            std :: cout << "Elemento NON TROVATO!" << std :: endl;
        }
    }
    else{
        std :: cout << "L`Albero E`Vuoto!" << std :: endl;
    }
}

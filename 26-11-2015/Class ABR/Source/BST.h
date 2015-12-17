//=================================
// include guard
#ifndef __CLASS_ABR_INCLUDED__
#define __CLASS_ABR_INCLUDED__

    //=================================
    // included dependencies
    #include "Console.h"
    #include "NODO.cpp"
    //=================================
    //Classe templata
    template < class Filler >
    class BST {
        private:
            //Attributi
            NODO < Filler > * Root;
        public:
            //Albero e gestione
                BST (){ Root = NULL; }; //Costruttore
                ~BST (){};
            //Metodi
            NODO < Filler > * GetRoot () { return Root; };
            void SetRoot ( NODO < Filler > * Nodo ) { Root = Nodo; };
            //Inserimento
            void CreateNODO ( Filler );
            void Inserimento ( NODO < Filler > *, NODO < Filler > * );
            //Visite (Stampe)
            void InOrderVisit ( NODO < Filler > * );
            void PostOrderVisit ( NODO < Filler > * );
            void PreOrderVisit ( NODO < Filler > * );
            //Ricerche
            NODO < Filler > * SearchKey ( NODO < Filler > *, Filler );
            Filler Minimo ( NODO < Filler > * );
            Filler Massimo ( NODO < Filler > * );
            NODO < Filler > * Sucessore ( NODO < Filler > *, Filler );
    };
#endif // __CLASS_ABR_INCLUDED__

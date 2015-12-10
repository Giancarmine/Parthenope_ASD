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
    template <class Filler>
    class BST {
        private:
            //Attributi
            NODO < Filler > * Root;
        public:
            //Albero e gestione
                BST (){ Root = NULL; }; //Costruttore
                ~BST (){};
            //Metodi
            void CreateNODO ( Filler );
            //Visite (Stampe)
            void InOrderVisit ();
            void PostOrderVisit ();
            void PreOrderVisit ();
            //Ricerche
            void SearchKey ( Filler );
            int Minimo ();
            int Massimo ();
    };
#endif // __CLASS_ABR_INCLUDED__

//=================================
// include guard
#ifndef __CLASS_H_INCLUDED__
#define __CLASS_H_INCLUDED__

    //=================================
    // included dependencies
    #include "Console.h"

    //=================================
    //Classe templata
    template <class Filler>
    class ABR {
        private:
            //Attributi
            Filler Elem;
            ABR * Left;
            ABR * Right;
            //Metodi
            void PrintNode ( Filler, int );
            void StampaElem ();
        public:
            //Albero e gestione
                ABR (){ Left = Right = NULL; }; //Costruttore
                ~ABR(){};
            //Metodi
            void Traverse ();
            int Count ();
            int Height ();
            void Show ( int );
            void Build ( ABR < Filler > *, ABR < Filler > *, Filler );
    };
#endif // __CLASS_H_INCLUDED__

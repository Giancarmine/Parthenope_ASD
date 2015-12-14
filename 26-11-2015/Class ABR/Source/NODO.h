//=================================
// include guard
#ifndef __CLASS_NODO_INCLUDED__
#define __CLASS_NODO_INCLUDED__

    //=================================
    // included dependencies
    #include "Console.h"

    //=================================
    //Classe templata
    template <class Filler>
    class NODO {
        private:
            //Attributi
            Filler Elem;
            NODO < Filler > * Parent;
            NODO < Filler > * Left;
            NODO < Filler > * Right;
        public:
            //NODO e gestione
                NODO (){ Parent = Left = Right = NULL; }; //Costruttore
                ~NODO(){};
            //Metodi
            void SetElem ( Filler );
            Filler GetElem ();
            void SetParent ( NODO * );
            NODO * GetParent ();
            void SetLeft ( NODO * );
            NODO * GetLeft ();
            void SetRight ( NODO * );
            NODO * GetRight ();
            void PrintNODO ();
    };
#endif // __CLASS_NODO_INCLUDED__

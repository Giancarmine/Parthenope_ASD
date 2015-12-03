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
    class Heap {
        private:
            //Attributi
            Filler Elem;
            Heap * Parent;
            Heap * Left;
            Heap * Right;
            //Metodi
            void PrintNode ( Filler, int );
            void StampaElem ( Filler );
        public:
            //Albero e gestione
                Heap (){ Parent = Left = Right = NULL; }; //Costruttore
                ~Heap(){};
            //Metodi
            void Traverse ( Heap < Filler > * );
            int Count ( Heap < Filler > * );
            int Height ( Heap < Filler > * );
            void Show ( Heap < Filler > *, int );
            void Build ( Heap < Filler > *, Heap < Filler > *, Heap < Filler > *, Filler );
    };
#endif // __CLASS_H_INCLUDED__

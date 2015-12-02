//=================================
// include guard
#ifndef __CLASS_H_INCLUDED__
#define __CLASS_H_INCLUDED__

    //=================================
    // included dependencies
    #include "Console.h"

    //=================================
    //Class
    class ABR{
        private:
            //Attributi
            char Elem;
            ABR * Left;
            ABR * Right;
            //Metodi
            void PrintNode ( char, int );
            void StampaElem ( char );
        public:
            //Albero e gestione
                ABR (){ Left = Right = NULL; }; //Costruttore
                ~ABR(){};
            //Metodi
            void Traverse ( ABR * );
            int Count ( ABR * );
            int Height ( ABR * );
            void Show ( ABR *, int );
            void Build ( ABR *, ABR *, char );
    };
#endif // __CLASS_H_INCLUDED__

class ABR{
    private:
        //Attributi
        char Elem;
        ABR *Left;
        ABR *Right;
        //Metodo
        void PrintNode ( char, int );
    public:
        //Albero e gestione
            //ABR (){ Elem = Left = Right = NULL; }; //Costruttore
            //~ABR(){};
        //Metodi
        void StampaElem ( ABR );
        void Traverse ( ABR );
        int Count ( ABR );
        int Height ( ABR );
        void Show ( ABR, int );
        void Build ( ABR, ABR, char );
};

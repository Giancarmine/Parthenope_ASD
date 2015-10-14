/*===================================================================================================


Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Class DVD
Data    		: 11/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/
class DVD{
    private:
        bool Registrato;
        int Codice;
        string Artista;
        string Editore;
        string Genere;
        float Costo;
        double Scaffale;
        double AnnoProd;

    public:
            DVD (){;};
            ~DVD (){;};
        void Inserisci_Codice (int Cod);
        void Inserisci_Artista (string Art);
        void Inserisci_Editore (string Edit);
        void Inserisci_Genere (string Gen);
        void Inserisci_Costo (float Cost);
        void Inserisci_Scaffale (double Scaff);
        void Inserisci_AnnoProd (double Anno);
        void Registra ();
        void Stampa ();
};

void DVD :: Inserisci_Codice (int Cod) {Codice = Cod;}
void DVD :: Inserisci_Artista (string Art) {Artista = Art;}
void DVD :: Inserisci_Editore (string Edit) {Editore = Edit;}
void DVD :: Inserisci_Genere (string Gen) {Genere = Gen;}
void DVD :: Inserisci_Costo (float Cost) {Costo = Cost;}
void DVD :: Inserisci_Scaffale (double Scaff) {Scaffale = Scaff;}
void DVD :: Inserisci_AnnoProd (double Anno) {AnnoProd = Anno;}
void DVD :: Registra () {Registrato = true;}
void DVD :: Stampa (){
    if (Registrato){
        cout << "Codice: " << Codice << endl;
        cout << "Artista: " << Artista << endl;
        cout << "Editore: " << Editore << endl;
        cout << "Genere: " << Genere << endl;
        cout << "Costo: " << Costo << " Euro" << endl;
        cout << "Scaffale: " << Scaffale << endl;
        cout << "AnnoProd: " << AnnoProd << endl;
    }
    else {
        cout << "NON REGISTRATO!" << endl;
    }
}

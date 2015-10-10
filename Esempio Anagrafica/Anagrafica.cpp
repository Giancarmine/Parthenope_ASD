/*===================================================================================================


Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Class Anagrafica
Data    		: 10/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/
class Anagrafica{
    private:
        bool Registrato;
        int Codice;
        string Cognome;
        string Nome;

    public:
            Anagrafica (){;};
            ~Anagrafica (){;};
        void Registra ();
        void Mostra ();
        void Inserisci_Codice (int Cod);
        void Inserisci_Cognome (string Cog);
        void Inserisci_Nome (string N);
};

void Anagrafica :: Registra () { Registrato = true; }
void Anagrafica :: Mostra () {
    if (Registrato){
        cout << Codice << endl << Cognome << endl << Nome << endl;
    }
    else {
        cout << "NON REGISTRATO!" << endl;
    }
}

void Anagrafica :: Inserisci_Codice (int Cod) {Codice = Cod;}
void Anagrafica :: Inserisci_Cognome (string Cog) {Cognome = Cog;}
void Anagrafica :: Inserisci_Nome (string N) {Nome = N;}


class Studente: public Anagrafica{
    private:
        bool Promosso;
    public:
            Studente (){Promosso = false;}; //Costruttore
        void Promuovi ();
        void Controlla ();
};

void Studente :: Promuovi () {Promosso = true;}
void Studente :: Controlla () {
    if (Promosso){
        cout << "Studente PROMOSSO!" << endl;
    }
    else{
        cout << "Studente NON promosso" << endl;
    }
}

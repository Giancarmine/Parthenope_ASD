/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Persona
Data    		: 15/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

class Persona{
    public:
        Persona(string S): nome(S){ }
    	virtual void print() { cout << "Il mio nome e`" << nome << endl; }

	protected:
    	string nome;
};

class Studente : public Persona {
    public:
        Studente (string S, float G): Persona (S), Media (G) {}
        void Print () { cout << "Il mio nome e`" << Nome << "La mia media e`" << Media << endl;}
    private:
        float Media;
};

class Professore : public Persona {
    public:
        Studente (string S, int N): Persona (S), Media (G) {}
        void Print () { cout << "Il mio nome e`" << Nome << " e ho " << Pubblicazioni << endl;}
    private:
        int Pubblicazioni;
};

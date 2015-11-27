#include "Console.h"

using namespace std;

/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Zaino 0-1 Greedy [Slide 15]
Data    		: 13/11/2015

To Do:
-----------------------------------------------------------------------------------------------------*/
class Mercanzia {
  private :
	    float Peso;
	    float Valore;
	    string Nome;
	    float Interesse;    //Appetibilita
        float FrazioneRubata;
	    Mercanzia();
	public:
	    Mercanzia ( string Name, float Weight, float Value ) {
            Nome = Name;
            Peso = Weight;
            Valore = Value;
            Interesse = Valore/Peso;
            FrazioneRubata = 0;
        }
	    float get_Peso() {return Peso;}
	    float get_Valore() {return Valore;}
	    float get_Interesse() {return Interesse;}

        void set_FrazioneRubata(float Parte){FrazioneRubata = Parte;}
        float get_FrazioneRubata() {return FrazioneRubata;}
        void Stampa();
};

void Mercanzia :: Stampa() {
    cout << "Mercanzia " << Nome << " Peso = " << Peso << " Valore = " << Valore;
    cout << " Interesse' = " << Interesse;
    if (FrazioneRubata > 0){
        cout << " FrazioneRubata = " << FrazioneRubata;
    }
    cout << endl;
}

list < Mercanzia > ZainoGreedy ( multimap < float, Mercanzia > &Robe, float MaxCapacita, float &ValoreFurto ){
    list < Mercanzia > Sacco;
    multimap <float, Mercanzia> :: reverse_iterator it_ObjectsMap;
    float Capacita = MaxCapacita;                   //Iniziamo con la capacità massima e gradualmente la diminuiamo
    ValoreFurto = 0;                                                 // Il valore del furto e' inizialmente zero.
    if(!Robe.empty()){       // Se la mappa non è vuota
        // Scorriamo tutti gli oggetti
        for (it_ObjectsMap = Robe.rbegin(); it_ObjectsMap != Robe.rend() && Capacita > 0; it_ObjectsMap++){
            // Verifica se l'oggetto può essere contenuto completamente nel sacco
            if( it_ObjectsMap -> second.get_Peso () <= Capacita ){
                // Mettiamo l‘ intero oggetto nel sacco
                it_ObjectsMap -> second.set_FrazioneRubata (1.0);
                Sacco.push_back (it_ObjectsMap -> second);
                Capacita = Capacita - it_ObjectsMap -> second.get_Peso();
                ValoreFurto = ValoreFurto + it_ObjectsMap->second.get_Valore();
            }
            else{
                // Mettiamo una frazione dell'oggetto nel sacco!!!
                it_ObjectsMap -> second.set_FrazioneRubata( Capacita/it_ObjectsMap -> second.get_Peso () );
                Sacco.push_back (it_ObjectsMap->second);
                ValoreFurto = ValoreFurto + it_ObjectsMap -> second.get_FrazioneRubata () * it_ObjectsMap -> second.get_Valore ();       // Il sacco è pieno
                Capacita = 0;
            }
        }
    }
    return(Sacco);
}


int main(){
    multimap < float, Mercanzia > ObjectsMap;

    Mercanzia myObj1 ("Mortadella", 5, 30);
    Mercanzia myObj2 ("Prosciutto", 10, 20);
    Mercanzia myObj3 ("Salame", 20, 100);
    Mercanzia myObj4 ("Latticini", 30, 90);
    Mercanzia myObj5 ("Parmigiano", 40, 160);

    ObjectsMap.insert (make_pair (myObj1.get_Interesse(), myObj1));
    ObjectsMap.insert (make_pair (myObj2.get_Interesse(), myObj2));
    ObjectsMap.insert (make_pair (myObj3.get_Interesse(), myObj3));
    ObjectsMap.insert (make_pair (myObj4.get_Interesse(), myObj4));
    ObjectsMap.insert (make_pair (myObj5.get_Interesse(), myObj5));

    multimap < float, Mercanzia > :: reverse_iterator it_ObjectsMap;

    // Stampa tutti gli oggetti che si possono rubare
    cout << "*** ELENCO DELLA MERCANZIA DA RUBARE ORDINATI PER INTERESSE ***" << endl;
    for( it_ObjectsMap = ObjectsMap.rbegin(); it_ObjectsMap != ObjectsMap.rend(); it_ObjectsMap++ )
        it_ObjectsMap -> second.Stampa();
    list < Mercanzia > OggettiRubati; 	// Richiama l'algoritmo greedy frazionale
    float ValoreFurto;
    OggettiRubati = ZainoGreedy ( ObjectsMap, 60, ValoreFurto );

    list < Mercanzia > ::iterator it_OggettiRubati;    // Stampa gli oggetti rubati

    cout << endl << "*** MERCANZIA RUBATA ***" << endl;
    for(it_OggettiRubati = OggettiRubati.begin(); it_OggettiRubati != OggettiRubati.end(); it_OggettiRubati++ )
        it_OggettiRubati->Stampa();
    cout << endl << "Valore totale del sacco = " << ValoreFurto << endl;
    return 0;
}


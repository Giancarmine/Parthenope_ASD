#include "Console.h"

using namespace std;

/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Shortest Job First [Slide 15]
Data    		: 12/11/2015

To Do:
-----------------------------------------------------------------------------------------------------*/
class Attivita {
  private :
	    int t_inizio;
	    int t_fine;
	    string nome_attivita;
	    int t_durata;
	    Attivita();
	public:
	    Attivita(string nome, int inizio, int fine) {nome_attivita = nome; t_inizio = inizio;
                            t_fine = fine; t_durata = t_fine - t_inizio;}
	    void stampa() {cout << "Attivita' [" << nome_attivita << "] Inizio = " << t_inizio;
                            cout << " Fine = " << t_fine << " Durata = " << t_durata << endl;}
	    int get_fine() {return t_fine;}
	    int get_inizio() {return t_inizio;}
	    int get_durata() {return t_durata;}
};


list < Attivita > ShortestJobFirst ( multimap < int, Attivita > &Activities ){
    list < Attivita > A;
    multimap< int, Attivita >::iterator it_ActivitiesMap;
    if(!Activities.empty()){     // Ci assicuriamo che la mappa sia piena
        int N = Activities.size();
        for(int turnaround = 1; turnaround<= N; turnaround++){
            it_ActivitiesMap = Activities.begin(); // Si posiziona sul primo elemento della mappa
            int i = 1;
            for ( it_ActivitiesMap = Activities.begin(); i<=turnaround; it_ActivitiesMap++ ){
                A.push_back(it_ActivitiesMap->second);
                i++;
            }
        }
    }
    return(A);
}


int main(){
    multimap < int, Attivita > ActivitiesMap;

    Attivita myAtt1("JOB A"  , 0, 4);  Attivita myAtt2("JOB X"  , 4, 5); Attivita myAtt3("JOB S"  , 5, 11);
    Attivita myAtt4("JOB D"  , 11, 14);
    ActivitiesMap.insert(make_pair(myAtt1.get_durata(), myAtt1));
    ActivitiesMap.insert(make_pair(myAtt2.get_durata(), myAtt2));
    ActivitiesMap.insert(make_pair(myAtt3.get_durata(), myAtt3));
    ActivitiesMap.insert(make_pair(myAtt4.get_durata(), myAtt4));

    multimap < int, Attivita >::iterator it_ActivitiesMap;

    cout << "*** ELENCO DELLE ATTIVITA ORDINATE PER DURATA ***" << endl;
    // Stampa tutte le attivita' previste
    for( it_ActivitiesMap = ActivitiesMap.begin(); it_ActivitiesMap != ActivitiesMap.end(); it_ActivitiesMap++ )
        it_ActivitiesMap->second.stampa();

    list <Attivita> AttivitaSchedulate = ShortestJobFirst(ActivitiesMap);
    // Richiama l'algoritmo greedy per la schedulazione SJF delle attivita'
    list<Attivita>::iterator it_AttivitaSchedulate;     	// Stampa tutte le attivita' schedulate
    cout << endl << "*** ATTIVITA ' SCHEDULATE ***" << endl;
    int turnaround = 1, k = 0;
    cout << endl << "TURNAROUND " << turnaround << endl;

    for(it_AttivitaSchedulate = AttivitaSchedulate.begin(); it_AttivitaSchedulate != AttivitaSchedulate.end(); it_AttivitaSchedulate++){
        if (k == (turnaround*(turnaround+1))/2){ //Per stampare le attività raggruppate per turnaround
            turnaround++; cout << endl << "TURNAROUND " << turnaround << endl;
        }
        it_AttivitaSchedulate->stampa();
        k++;
    }
    return 0;
}


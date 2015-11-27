#include "Console.h"

using namespace std;

/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Activity Shedule [Slide 14]
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
        Attivita(string nome, int inizio, int fine) {
            nome_attivita = nome;
            t_inizio = inizio;
            t_fine = fine;
            t_durata = t_fine - t_inizio;
        }
        void stampa() {
            cout << "Attivita' [" << nome_attivita << "] Inizio = " << t_inizio;
            cout << " Fine = " << t_fine << " Durata = " << t_durata << endl;
        }
        int get_fine()      { return t_fine; }
        int get_inizio()    { return t_inizio; }
        int get_durata()    { return t_durata; }
};

list < Attivita > schedule( map < int, Attivita > &Activities )
{
    list <Attivita> A;
    map <int, Attivita> :: iterator it_ActivitiesMap, it_prevActivity;
    it_ActivitiesMap = Activities.begin(); // Si posiziona sul primo elemento della mappa
    if(it_ActivitiesMap != Activities.end()){
        // Ci assicuriamo che la mappa sia piena
        A.push_back((it_ActivitiesMap->second));   // Schedula attivita' 1 per prima
        it_prevActivity = it_ActivitiesMap;      // Salva l'iteratore dell'attività inserita
        it_ActivitiesMap++;
        for ( ;it_ActivitiesMap != Activities.end();it_ActivitiesMap++ ){
            // Se non c'e' interferenza
            if(it_ActivitiesMap->second.get_inizio() >= it_prevActivity->second.get_fine()){
                A.push_back((it_ActivitiesMap->second));
                // Salva l'iteratore dell'attività inserita
                it_prevActivity = it_ActivitiesMap;
            }
        }
    }
    return(A);
}


int main() {
    map <int, Attivita> ActivitiesMap;

    Attivita myAtt1("JOB A"  , 12, 14); Attivita myAtt2("JOB X"  , 3, 5); Attivita myAtt3("JOB S"  , 0, 6);
    Attivita myAtt4("JOB D"  , 8, 11);  Attivita myAtt5("JOB T"  , 3, 8);  Attivita myAtt6("JOB E"  , 5, 7);
    Attivita myAtt7("JOB Z"  , 8, 12); Attivita myAtt8("JOB M"  , 5, 9);   Attivita myAtt9("JOB J"  , 6, 10);
    Attivita myAtt10("JOB K" , 1, 4);

    ActivitiesMap.insert(make_pair(myAtt1.get_fine(), myAtt1));
    ActivitiesMap.insert(make_pair(myAtt2.get_fine(), myAtt2));
    ActivitiesMap.insert(make_pair(myAtt3.get_fine(), myAtt3));
    ActivitiesMap.insert(make_pair(myAtt4.get_fine(), myAtt4));
    ActivitiesMap.insert(make_pair(myAtt5.get_fine(), myAtt5));
    ActivitiesMap.insert(make_pair(myAtt6.get_fine(), myAtt6));
    ActivitiesMap.insert(make_pair(myAtt7.get_fine(), myAtt7));
    ActivitiesMap.insert(make_pair(myAtt8.get_fine(), myAtt8));
    ActivitiesMap.insert(make_pair(myAtt9.get_fine(), myAtt9));
    ActivitiesMap.insert(make_pair(myAtt10.get_fine(), myAtt10));

    // Stampa tutte le attivita' previste
    map <int, Attivita>::iterator it_ActivitiesMap;
    cout << "*** ELENCO DELLE ATTIVITA ' ORDINATE PER TEMPO DI FINE ***" << endl;
    for(it_ActivitiesMap = ActivitiesMap.begin(); it_ActivitiesMap != ActivitiesMap.end(); it_ActivitiesMap++)
        it_ActivitiesMap->second.stampa();

    list<Attivita> AttivitaSchedulate = schedule(ActivitiesMap);

    // Richiama l'algoritmo greedy per la selezione delle attivita'
    // Stampa tutte le attivita' Schedulate
    list<Attivita>::iterator it_AttivitaSchedulate;
    cout << endl << "*** ATTIVITA ' SCHEDULATE ***" << endl;

    for(it_AttivitaSchedulate = AttivitaSchedulate.begin(); it_AttivitaSchedulate != AttivitaSchedulate.end(); it_AttivitaSchedulate++)
        it_AttivitaSchedulate->stampa();
    return 0;
}

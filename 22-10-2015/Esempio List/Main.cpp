#include "Console.h"

using namespace std;

/*===================================================================================================


Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Esempio MAXI - Template -
Data    		: 22/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

template<class T>
T maxi (T P1, T P2){
    if ( P1<P2 ) return P2;
    else return P1;
}
int main(){
    cout << maxi<int>( 10, 20) << endl;
    cout << maxi<float>( 2.6, 1.0 ) << endl;
    return 0;
}

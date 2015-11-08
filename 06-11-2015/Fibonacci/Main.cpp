#include "Console.h"
const int MAXN = 500;

using namespace std;

/*===================================================================================================
MergeSort In Place di un vettore gestito in classi [C++]

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Ordina un Array dinamicamente (BucketSort)
Data    		: 6/11/2015

To Do:
-----------------------------------------------------------------------------------------------------*/
int FibonacciStat (int i){
    if ( i==0 || i==1 ) return 1;

    return FibonacciStat ( i-1 )+ FibonacciStat ( i-2 );
}

int FibonacciDin (int i){
    static int knowF[MAXN];

    if (knowF[i] != 0) return knowF[i];
    if (i < 0)  return 0;
    if (i == 0) return 1;

    if ( i > 0){
        return knowF[i] = ( FibonacciDin(i-1) + FibonacciDin(i-2) );
    }

}

int main(){

    for ( int i=10; i < MAXN; i++){
        //FibonacciStat (i);
        FibonacciDin (i);
        cout << i << endl;
    }

    return 0;
}

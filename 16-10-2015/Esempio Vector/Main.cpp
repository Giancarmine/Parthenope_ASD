#include "Console.h"

using namespace std;

/*===================================================================================================


Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Vector
Data    		: 16/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

int main(){
    vector<int> V;
    const int N=10;

    for ( int i = 0; i <= N; i++){
        V.push_back(i);
    }
    for ( int i = 0; i < V.size(); i++){
        cout << V[i] << ", ";
    }
    cout << endl;
    for ( int i = 0; i < V.size(); i++){
        V[i] = V[i] * 10; // Assignment
    }
    for ( int i = 0; i < V.size(); i++){
        cout << V[i] << ", ";
    }
    return 0;
}

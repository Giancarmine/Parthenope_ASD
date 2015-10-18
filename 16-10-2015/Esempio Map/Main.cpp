#include "Console.h"

using namespace std;

/*===================================================================================================


Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Map
Data    		: 16/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

//#include "Array.cpp"

int main(){
    map<string,int> amap;
	amap["Primo"] = 1111;
	amap["Secondo"] = 2222;

	cout << "Size : " << amap.size() << endl;
	amap["Terzo"] = 3333;
	amap["Quarto"] = 4444;
	cout << "Size : " << amap.size() << endl;
	map<string,int>::iterator it;
	for ( it=amap.begin(); it!=amap.end(); it++)
		cout << "map : " << it->first << " " << it->second << endl;
	cout << amap.find("Terzo")->second << endl;
	amap.clear();//rimuove gli elementi dalla mappa

    return 0;
}

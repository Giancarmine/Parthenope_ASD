#include <iostream>
#include <string>
using namespace std;

int Hash ( char *v, int M ) { // hash semplice
 int h = 0, a = 127;
 for ( ; *v != 0; v++ )
    h = ( a *h + *v ) %M;
 return h;
}

int Hashu ( char *v, int M ) { // hash universale
 int h, a = 31415, b = 27183;
 for(h = 0; *v != 0; v++, a = a*b % ( M - 1 ) )
    h = (a *h + *v) %M;
 return ( h < 0 ) ? ( h + M ) : h;
}

int main(){
	string myString = "HASHING";
	cout << "Hashing di " << myString << " = " << Hash((char *)myString.c_str(), 100) << endl;
	cout << "Hashing universale di " << myString << " = " << Hashu((char *)myString.c_str(), 100);
    cout  << endl;
	return 0;
}

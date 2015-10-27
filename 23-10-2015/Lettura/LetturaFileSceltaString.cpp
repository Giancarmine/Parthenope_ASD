#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string c_str filename;
    ifstream fileread;
    cout << "inserisci nome file" << endl;
    cin >> filename;
    fileread.open(filename);
    char Ch;
    while ( fileread.get(Ch) ) //legge da file 1
        cout << Ch;
    cout << endl;
    fileread.close();
    return 0;
}

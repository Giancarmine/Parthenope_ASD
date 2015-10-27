#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
    char line[80];
    fstream iofile;
    iofile.open("file1.txt", ios::in | ios::out);
    iofile << "Ciao Gente";
    iofile.seekg(ios::beg);  //posizione iniziale del file
    iofile.getline(line,80);
    cout << line<< endl;
    iofile.close();
    return 0;
}


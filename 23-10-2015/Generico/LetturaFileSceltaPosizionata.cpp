#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    fstream iofile;
    iofile.open("file1.txt", ios::in | ios::out);
    iofile << "Ciao Gente";
    iofile.seekg(ios::beg);  //posizione iniziale del file
    iofile >> str;
    cout << str << endl;
    iofile.close();
    return 0;
}

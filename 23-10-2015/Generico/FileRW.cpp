#include <fstream>
#include <iostream>
using namespace std;

int main(){
    char filename[64], out [64];
    strcpy (filename, "file1.txt");
    strcpy (out, "nuovo");
    ifstream Optfile;
    Optfile.open (filename, ios::in);
    char Ch;
    Optfile.get(ch);
    Optfile.close();
    Optfile.open(filename, ios::in | ios::out)
    Optfile << out << " " << Ch << endl;
    fileread.close();
    return 0;
}

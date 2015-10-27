#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream fileread("file1.txt");
    char Ch;
    while ( fileread.get(Ch) ) //legge da file 1
        cout << Ch;
    cout << endl;
    fileread.close();
    return 0;
}

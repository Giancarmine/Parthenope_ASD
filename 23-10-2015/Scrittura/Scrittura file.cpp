#include <fstream>
using namespace std;

int main(){
    ofstream filewrite("file1.txt");
    filewrite  << "Ciao Gente" << endl;
    filewrite.close();
    return 0;
}

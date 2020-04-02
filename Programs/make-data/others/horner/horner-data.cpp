#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int defaultNum = 100;

int main(int argc, char** argv) {
    string dirname = (argc >= 2 ? argv[1] : "");
    string filename = dirname + "horner-data";
    int num = (argc >= 3 ? atoi(argv[2]) : defaultNum);
    ofstream fout(filename);
    if (!fout) {
        cout << "出力ファイルが開けません。" << endl;
        return 1;
    }
    srand(time(NULL));
    fout << rand() % num << endl;
    for (int i=0; i<=num; i++) {
        fout << rand() % num << (i!=num?' ':'\n');
    }
    fout.close();
    fout.close();
    return 0;
}

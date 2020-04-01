#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int defaultNum = 100;

int main(int argc, char** argv) {
    string dirname = (argc >= 2 ? argv[1] : "");
    string filename = dirname + "practice4-data";
    int num = (argc >= 3 ? atoi(argv[2]) : defaultNum);
    ofstream fout(filename);
    if (!fout) {
        cout << "出力ファイルが開けません。" << endl;
        return 1;
    }
    srand(time(NULL));
    for (int b=0; b<2; ++b) {
        for (int i=0; i<num; i++) {
            fout << rand() % 2;
        }
        fout << endl;
    }
    fout.close();
    return 0;
}

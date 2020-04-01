#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int defaultNum = 100;

int main(int argc, char** argv) {
    string dirname = (argc >= 2 ? argv[1] : "");
    string filename = dirname + "practice7-data";
    int num = (argc >= 3 ? atoi(argv[2]) : defaultNum);
    ofstream fout(filename);
    if (!fout) {
        cout << "出力ファイルが開けません。" << endl;
        return 1;
    }
    srand(time(NULL));
    fout << rand() % (num * 2) << endl;
    for (int i=0; i<num; i++) {
        fout << rand() % num << (i!=num-1?' ':'\n');
    }
    fout.close();
    return 0;
}

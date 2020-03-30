#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "data";

int main(int argc, char** argv)
{
    string dataFile = (argc >= 2 ? argv[1] : defaultFile);
    ifstream fin(dataFile);
    if (!fin) {
        cout << "入力ファイルが開けません。" << endl;
        return 1;
    }
    ofstream fout(dataFile + "sorted");
    if (!fout) {
        cout << "出力ファイルが開けません。" << endl;
        if (fin) fin.close();
        return 1;
    }
    vector<int> a;
    while (!fin.eof()) {
        int i;
        fin >> i;
        a.push_back(i);
    }

    // ソートアルゴリズムここから



    // ここまで

    for (int i=0; i<int(a.size()); ++i) {
        fout << a[i] << (i!=int(a.size())-1?' ':'\n');
    }
    fin.close();
    fout.close();
    return 0;
}

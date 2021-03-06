#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "search-data";

int search(vector<int> a, int v) {

}

int main(int argc, char** argv)
{
    string dataFile = (argc >= 2 ? argv[1] : defaultFile);
    ifstream fin(dataFile);
    if (!fin) {
        cout << "入力ファイルが開けません。" << endl;
        return 1;
    }
    ofstream fout(dataFile + "-searched");
    if (!fout) {
        cout << "出力ファイルが開けません。" << endl;
        if (fin) fin.close();
        return 1;
    }
    int v;
    fin >> v;
    vector<int> a;
    while (!fin.eof()) {
        int i;
        fin >> i;
        a.push_back(i);
    }

    // 探索アルゴリズムここから

    int i = search(a, v);

    // ここまで

    if (i == -1) fout << "NIL" << endl;
    else fout << i << endl;

    fin.close();
    fout.close();
    return 0;
}

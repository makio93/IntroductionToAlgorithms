#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "search-sorted-data";

int binary_search(vector<int> a, int v) {
    int l = 0, r = a.size()-1;
    while (r > l) {
        int c = (l + r) / 2;
        if (a[c] >= v) r = c;
        else l = c + 1;
    }
    if (a[l] == v) return l;
    else return -1;
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

    int i = binary_search(a, v);

    // ここまで

    if (i == -1) fout << "NIL" << endl;
    else fout << i << endl;

    fin.close();
    fout.close();
    return 0;
}

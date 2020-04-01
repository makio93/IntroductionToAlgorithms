#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "search-sorted-data";

int binary_search2(vector<int> a, int v, int l, int r) {
    if (l == r) {
        if (a[l] == v) return l;
        else return -1;
    }
    int c = (l + r) / 2;
    if (a[c] >= v) return binary_search2(a, v, l, c - 1);
    else return binary_search2(a, v, c + 1, r);
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

    int i = binary_search2(a, v, 0, int(a.size()) - 1);

    // ここまで

    if (i == -1) fout << "NIL" << endl;
    else fout << i << endl;

    fin.close();
    fout.close();
    return 0;
}

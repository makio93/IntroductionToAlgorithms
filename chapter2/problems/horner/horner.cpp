#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "horner-data";

long long horner(vector<int> a, int x) {
    int n = a.size() - 1;
    long long y = 0LL;
    for (int i=n; i>=0; --i) {
        y = y * x + a[i];
    }
    return y;
}

int main(int argc, char** argv)
{
    string dataFile = (argc >= 2 ? argv[1] : defaultFile);
    ifstream fin(dataFile);
    if (!fin) {
        cout << "入力ファイルが開けません。" << endl;
        return 1;
    }
    ofstream fout(dataFile + "-solved");
    if (!fout) {
        cout << "出力ファイルが開けません。" << endl;
        if (fin) fin.close();
        return 1;
    }
    int x;
    fin >> x;
    vector<int> a;
    while (!fin.eof()) {
        int i;
        fin >> i;
        a.push_back(i);
    }

    // 探索アルゴリズムここから

    long long y = horner(a, x);

    // ここまで

    fout << y << endl;
    fin.close();
    fout.close();
    return 0;
}

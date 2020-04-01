#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string defaultFile = "practice4-data";

vector<int> practice4(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> c(n+1);
    for (int i=n-1; i>=0; --i) {
        c[i] = (a[i] + b[i] + c[i+1]) / 2;
        c[i+1] = (a[i] + b[i] + c[i+1]) % 2;
    }
    return c;
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
    string as, bs;
    fin >> as >> bs;
    vector<int> a, b;
    for (char c : as) {
        a.push_back(c - '0');
    }
    for (char c : bs) {
        b.push_back(c - '0');
    }

    // ソートアルゴリズムここから

    vector<int> c = practice4(a, b);

    // ここまで

    for (int i=0; i<int(c.size()); ++i) fout << c[i];
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}

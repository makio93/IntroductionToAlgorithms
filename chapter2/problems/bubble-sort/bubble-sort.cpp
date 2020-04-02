#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "sort-data";

void bubble_sort(vector<int>& a) {
    int n = a.size();
    for (int i=0; i<n-1; ++i) {
        for (int j=n-1; j>=1; --j) {
            if (a[j-1] > a[j]) swap(a[j-1], a[j]);
        }
    }
}

int main(int argc, char** argv)
{
    string dataFile = (argc >= 2 ? argv[1] : defaultFile);
    ifstream fin(dataFile);
    if (!fin) {
        cout << "入力ファイルが開けません。" << endl;
        return 1;
    }
    ofstream fout(dataFile + "-sorted");
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

    bubble_sort(a);

    // ここまで

    for (int i=0; i<int(a.size()); ++i) {
        fout << a[i] << (i!=int(a.size())-1?' ':'\n');
    }
    fin.close();
    fout.close();
    return 0;
}

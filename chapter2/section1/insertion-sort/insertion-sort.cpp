#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "sort-data";

void insertion_sort(vector<int>& a) {
    int n = a.size();
    for (int i=1; i<n; ++i) {
        int key = a[i];
        int j = i-1;
        while (j>=0 && a[j]>key) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
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
        return 1;
    }
    vector<int> a;
    while (!fin.eof()) {
        int i;
        fin >> i;
        a.push_back(i);
    }

    // ソートアルゴリズムここから

    insertion_sort(a);

    // ここまで

    for (int i=0; i<int(a.size()); ++i) {
        fout << a[i] << (i!=int(a.size())-1?' ':'\n');
    }
    fin.close();
    fout.close();
    return 0;
}

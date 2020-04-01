#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "sort-data";
const int INF = INT32_MAX;

void merge(vector<int>& a, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q;
    vector<int> L(n1+1), R(n2+1);
    for (int i=0; i<n1; ++i) L[i] = a[p+i];
    for (int i=0; i<n2; ++i) R[i] = a[q+i+1];
    L[n1] = INF; R[n2] = INF;
    int i = 0, j = 0;
    for (int k=p; k<=r; ++k) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            ++i;
        }
        else {
            a[k] = R[j];
            ++j;
        }
    }
}

void merge_sort(vector<int>& a, int p, int r) {
    if (r > p) {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
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

    merge_sort(a, 0, a.size());

    // ここまで

    for (int i=0; i<int(a.size()); ++i) {
        fout << a[i] << (i!=int(a.size())-1?' ':'\n');
    }
    fin.close();
    fout.close();
    return 0;
}

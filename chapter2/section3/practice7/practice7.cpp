#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string defaultFile = "practice7-data";
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

bool binary_searchA(vector<int>& a, int v, int i) {
    int l = 0, r = a.size()-1;
    while (r > l) {
        int c = (l + r) / 2;
        if (a[c] >= v) r = c;
        else l = c + 1;
    }
    if (l != i)  {
        if (a[l] == v) return true;
        else return false;
    }
    else {
        if (a[l+1] == v) return true;
        else return false;
    }
}

bool practice7(vector<int>& a, int x) {
    if (int(a.size()) < 2) return false;
    merge_sort(a, 0, a.size() - 1);
    for (int i=0; i<int(a.size()); ++i) {
        int v = x - a[i];
        if (binary_searchA(a, v, i)) return true;
    }
    return false;
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
    int x;
    fin >> x;
    vector<int> a;
    while (!fin.eof()) {
        int i;
        fin >> i;
        a.push_back(i);
    }

    // 探索アルゴリズムここから

    bool p = practice7(a, x);

    // ここまで

    if (p) fout << "Yes" << endl;
    else fout << "No" << endl;

    fin.close();
    fout.close();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    vector<string> kota(n);
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> kota[i];
    }

    vector<vector<int>> graf(n, vector<int>(n));
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                graf[i][j] = 0;
            } else {
                cout << kota[i] << "-->" << kota[j] << " = ";
                cin >> graf[i][j];
            }
        }
    }

    // Output adjacency matrix
    cout << endl << "    ";
    for (int i = 0; i < n; ++i) {
        cout << kota[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << kota[i] << " ";
        for (int j = 0; j < n; ++j) {
            cout << graf[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

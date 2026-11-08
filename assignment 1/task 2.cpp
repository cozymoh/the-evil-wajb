#include <iostream>
#include <vector>
using namespace std;
bool isDiagonal(const vector<vector<int>>& matrix, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int size;
    cout << "Enter size of the square matrix: ";
    cin >> size;
    vector<vector<int>> matrix(size, vector<int>(size));
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
    if (isDiagonal(matrix, size)) {
        cout << "The matrix is a diagonal matrix." << endl;
    } else {
        cout << "The matrix is not a diagonal matrix." << endl;
    }
    return 0;
}

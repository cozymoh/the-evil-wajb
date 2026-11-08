#include <iostream>
#include <vector>
using namespace std;
vector<int> resizeArray(const vector<int>& inArray, const int size) {
    vector<int> outArray(size * 2);
    for (int i = 0; i < size; i++) {
        outArray[i] = inArray[i];
        outArray[i + size] = inArray[i] * 2;
    }
    return outArray;
}
int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    vector<int> resized = resizeArray(arr, size);
    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++) {
        cout << resized[i];
        if (i < size * 2 - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}

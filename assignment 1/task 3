#include <iostream>
#include <vector>
using namespace std;
int stringLength(const char* text) {
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    return length;
}
vector<char> left(const char* target, const int count) {
    vector<char> result;
    if (count < 0 || count > stringLength(target)) {
        return result;
    }
    for (int i = 0; i < count; i++) {
        result.push_back(target[i]);
    }
    return result;
}
int main() {
    char str[30];
    int count;
    cout << "Enter a string: ";
    cin.getline(str, 30);
    cout << "Enter count: ";
    cin >> count;
    if (count < 0 || count > stringLength(str)) {
        cout << "Count is out of range." << endl;
        return 0;
    }
    vector<char> sub = left(str, count);
    cout << "Left substring: ";
    for (int i = 0; i < count; i++) {
        cout << sub[i];
    }
    cout << endl;
    return 0;
}

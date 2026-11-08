#include <iostream>
#include <vector>
using namespace std;
int findMin(const vector<int>& inArray) {
    int minimum = inArray[0];
    for (int i = 1; i < inArray.size(); i++) {
        if (inArray[i] < minimum) {
            minimum = inArray[i];
        }
    }
    return minimum;
}
int findMax(const vector<int>& inArray) {
    int maximum = inArray[0];
    for (int i = 1; i < inArray.size(); i++) {
        if (inArray[i] > maximum) {
            maximum = inArray[i];
        }
    }
    return maximum;
}
int computeAverage(const vector<int>& inArray) {
    int sum = 0;
    for (int i = 0; i < inArray.size(); i++) {
        sum += inArray[i];
    }
    return sum / inArray.size();
}
int computeMedian(vector<int> inArray) {
    int size = inArray.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (inArray[j] > inArray[j + 1]) {
                int temp = inArray[j];
                inArray[j] = inArray[j + 1];
                inArray[j + 1] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        return (inArray[size / 2 - 1] + inArray[size / 2]) / 2;
    }
    return inArray[size / 2];
}
int main() {
    int size;
    do {
        cout << "Enter number of students: ";
        cin >> size;
    } while (size <= 0);
    vector<int> marks(size);
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter marks of student " << i + 1 << ": ";
            cin >> marks[i];
            if (marks[i] < 0) {
                cout << "Marks cannot be negative." << endl;
            }
        } while (marks[i] < 0);
    }
    cout << "Maximum: " << findMax(marks) << endl;
    cout << "Minimum: " << findMin(marks) << endl;
    cout << "Average: " << computeAverage(marks) << endl;
    cout << "Median: " << computeMedian(marks) << endl;
    return 0;
}

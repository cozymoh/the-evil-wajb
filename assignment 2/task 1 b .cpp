#include <iostream>
#include <string>
using namespace std;
const int STOCK_SIZE = 10;
struct InventoryItem {
    string code;
    string name;
    double cost;
    double sellingPrice;
};
string makePrefix(const string& name) {
    string prefix = "";
    for (int i = 0; i < 3 && i < name.size(); i++) {
        char letter = name[i];
        if (letter >= 'a' && letter <= 'z') {
            letter = letter - 'a' + 'A';
        }
        prefix += letter;
    }
    return prefix;
}
string numberToText(int number) {
    if (number == 0) {
        return "0";
    }
    string text = "";
    while (number > 0) {
        text = char('0' + number % 10) + text;
        number /= 10;
    }
    return text;
}
InventoryItem insertItem() {
    static int runningNumber = 31203;
    InventoryItem item;
    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter item cost: ";
    cin >> item.cost;
    item.code = makePrefix(item.name) + "_" + numberToText(runningNumber);
    runningNumber++;
    item.sellingPrice = item.cost * 1.40;
    return item;
}
void displayStock(const InventoryItem* stock) {
    cout << "Code\t\tName\t\tCost\tPrice" << endl;
    for (int i = 0; i < STOCK_SIZE; i++) {
        cout << stock[i].code << "\t" << stock[i].name << "\t\t" << stock[i].cost << "\t" << stock[i].sellingPrice << endl;
    }
}
int main() {
    InventoryItem stock[STOCK_SIZE];
    for (int i = 0; i < STOCK_SIZE; i++) {
        stock[i] = insertItem();
    }
    displayStock(stock);
    return 0;
}

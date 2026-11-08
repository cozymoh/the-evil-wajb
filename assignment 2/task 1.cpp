#include <iostream>
#include <string>
using namespace std;
const int STOCK_SIZE = 10;
struct InventoryItem {
    int code;
    string name;
    double cost;
    double sellingPrice;
};
InventoryItem insertItem() {
    static int nextCode = 3123;
    InventoryItem item;
    item.code = nextCode++;
    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter item cost: ";
    cin >> item.cost;
    item.sellingPrice = item.cost * 1.40;
    return item;
}
void displayStock(const InventoryItem* stock) {
    cout << "Code\tName\t\tCost\tPrice" << endl;
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

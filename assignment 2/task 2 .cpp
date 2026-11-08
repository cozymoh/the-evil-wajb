#include <iostream>
#include <vector>
using namespace std;
struct FeetInches {
    int feet;
    int inches;
};
struct RoomDimension {
    FeetInches length;
    FeetInches width;
};
double computeTheCarpetingCost(const RoomDimension& room, const double pricePerSqFt) {
    double length = room.length.feet + room.length.inches / 12.0;
    double width = room.width.feet + room.width.inches / 12.0;
    return length * width * pricePerSqFt;
}
int main() {
    int rooms;
    double price;
    cout << "Enter number of rooms: ";
    cin >> rooms;
    cout << "Enter price per square foot: ";
    cin >> price;
    vector<RoomDimension> house(rooms);
    for (int i = 0; i < rooms; i++) {
        cout << "Room " << i + 1 << " length (feet inches): ";
        cin >> house[i].length.feet >> house[i].length.inches;
        cout << "Room " << i + 1 << " width (feet inches): ";
        cin >> house[i].width.feet >> house[i].width.inches;
    }
    int choice;
    do {
        cout << "1. Total carpeting cost of the house" << endl;
        cout << "2. Carpeting cost of a single room" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            double total = 0;
            for (int i = 0; i < rooms; i++) {
                total += computeTheCarpetingCost(house[i], price);
            }
            cout << "Total cost: Rs. " << total << endl;
        } else if (choice == 2) {
            int room;
            cout << "Enter room number (1-" << rooms << "): ";
            cin >> room;
            if (room >= 1 && room <= rooms) {
                cout << "Cost of room " << room << ": Rs. " << computeTheCarpetingCost(house[room - 1], price) << endl;
            } else {
                cout << "Invalid room number." << endl;
            }
        } else if (choice != 3) {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 3);
    return 0;
}

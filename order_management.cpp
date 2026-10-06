#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX = 100;
    string customerNames[MAX];
    string orderType[MAX];
    int quantity[MAX];
    double unitPrice[MAX];
    double totalPrice[MAX];
    int orderCount = 0;
    int choice;

    do {
        cout << "\n=== Magwinya Magic Order Management ===" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. View All Orders" << endl;
        cout << "3. Search Order by Name" << endl;
        cout << "4. View Total Sales" << endl;
        cout << "5. Delete Order" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (orderCount >= MAX) {
                cout << "Order list full!" << endl;
                continue;
            }
            cout << "Enter customer name: ";
            getline(cin, customerNames[orderCount]);
            cout << "Enter magwinya type (plain/cheese/polony): ";
            getline(cin, orderType[orderCount]);
            cout << "Enter quantity: ";
            cin >> quantity[orderCount];
            cout << "Enter unit price: ";
            cin >> unitPrice[orderCount];
            totalPrice[orderCount] = quantity[orderCount] * unitPrice[orderCount];
            cout << "Order added! Total: R" << totalPrice[orderCount] << endl;
            orderCount++;
            cin.ignore();
        }
        else if (choice == 2) {
            if (orderCount == 0) cout << "No orders yet." << endl;
            else {
                cout << "\n--- All Orders ---" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << i+1 << ". " << customerNames[i] << " | "
                         << orderType[i] << " | Qty: " << quantity[i]
                         << " | Total: R" << totalPrice[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            string searchName;
            cout << "Enter name to search: ";
            getline(cin, searchName);
            bool found = false;
            for (int i = 0; i < orderCount; i++) {
                if (customerNames[i] == searchName) {
                    cout << "Found: " << customerNames[i] << " | "
                         << orderType[i] << " | Qty: " << quantity[i]
                         << " | R" << totalPrice[i] << endl;
                    found = true;
                }
            }
            if (!found) cout << "Order not found." << endl;
        }
        else if (choice == 4) {
            double grandTotal = 0;
            for (int i = 0; i < orderCount; i++) grandTotal += totalPrice[i];
            cout << "Total Sales: R" << grandTotal << " from " << orderCount << " orders." << endl;
        }
        else if (choice == 5) {
            int del;
            cout << "Enter order number to delete (1-" << orderCount << "): ";
            cin >> del;
            if (del >= 1 && del <= orderCount) {
                for (int i = del-1; i < orderCount-1; i++) {
                    customerNames[i] = customerNames[i+1];
                    orderType[i] = orderType[i+1];
                    quantity[i] = quantity[i+1];
                    unitPrice[i] = unitPrice[i+1];
                    totalPrice[i] = totalPrice[i+1];
                }
                orderCount--;
                cout << "Order deleted." << endl;
            } else cout << "Invalid number." << endl;
        }
    } while (choice!= 6);

    cout << "Thank you for using Magwinya Magic!" << endl;
    return 0;
}

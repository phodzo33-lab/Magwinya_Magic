#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary = char('0' + decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

string decimalToHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    string hexChars = "0123456789ABCDEF";
    string hex = "";
    while (decimal > 0) {
        hex = hexChars[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}

int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int base = 1;
    for (int i = hex.length() - 1; i >= 0; i--) {
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') digit = hex[i] - '0';
        else if (hex[i] >= 'A' && hex[i] <= 'F') digit = hex[i] - 'A' + 10;
        else if (hex[i] >= 'a' && hex[i] <= 'f') digit = hex[i] - 'a' + 10;
        else continue;
        decimal += digit * base;
        base *= 16;
    }
    return decimal;
}

int main() {
    srand(time(0));
    int choice;
    do {
        cout << "\nConversion Menu:\n";
        cout << "1. Convert Decimal to Binary\n";
        cout << "2. Convert Binary to Decimal\n";
        cout << "3. Convert Hexadecimal to Decimal\n";
        cout << "4. Convert Decimal to Hexadecimal\n";
        cout << "5. Demo (Generate and convert random integers to binary)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        switch (choice) {
            case 1: {int d; cout<<"Enter a decimal number: "; cin>>d; cout<<"Binary representation: "<<decimalToBinary(d)<<endl; break;}
            case 2: {string b; cout<<"Enter a binary number: "; cin>>b; cout<<"Decimal representation: "<<binaryToDecimal(b)<<endl; break;}
            case 3: {string h; cout<<"Enter a hexadecimal number: "; cin>>h; cout<<"Decimal representation: "<<hexadecimalToDecimal(h)<<endl; break;}
            case 4: {int d; cout<<"Enter a decimal number: "; cin>>d; cout<<"Hexadecimal representation: "<<decimalToHexadecimal(d)<<endl; break;}
            case 5: {int r=rand()%100; cout<<"Generated random integer: "<<r<<endl; cout<<"Binary representation: "<<decimalToBinary(r)<<endl; break;}
            case 6: cout<<"Exiting the program."<<endl; break;
            default: cout<<"Invalid choice!"<<endl;
        }
    } while (choice!= 6);
    return 0;
}
// Final update for ISAT subtask 2 

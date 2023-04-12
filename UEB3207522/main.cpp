//
//  main.cpp
//  Momo project
//
//  Created by Haruna Illiasu on 08/04/2023.
//  UEB3207522
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int balance = 1000;
    string default_pin = "0000";
    string pin = default_pin;
    int attempts = 0;
    int choice;

    while (true) {
        cout << "Welcome to Mobile Money Service" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Send Money" << endl;
        cout << "3. Change Pin" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your pin: ";
                cin >> pin;
                if (pin == default_pin) {
                    cout << "Your balance is: " << balance << endl;
                } else {
                    cout << "Incorrect pin" << endl;
                    attempts++;
                }
                break;
            case 2:
                cout << "Enter your pin: ";
                cin >> pin;
                if (pin == default_pin) {
                    int amount;
                    int receiver;
                    cout << "Enter the amount to send: ";
                    cin >> amount;
                    cout << "Enter the receiver's mobile number: ";
                    cin >> receiver;
                    // send the money here
                    balance -= amount;
                    cout << "Money sent successfully" << endl;
                } else {
                    cout << "Incorrect pin" << endl;
                    attempts++;
                }
                break;
            case 3:
                cout << "Enter your current pin: ";
                cin >> pin;
                if (pin == default_pin) {
                    string new_pin;
                    cout << "Enter new 4-digit pin: ";
                    cin >> new_pin;
                    if (new_pin.size() == 4) {
                        default_pin = new_pin;
                        pin = new_pin;
                        cout << "Pin changed successfully" << endl;
                    } else {
                        cout << "Invalid pin. Please enter a 4-digit pin." << endl;
                    }
                } else {
                    cout << "Incorrect pin" << endl;
                    attempts++;
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }

        if (attempts >= 3) {
            cout << "Maximum attempts reached. Exiting..." << endl;
            return 0;
        }
    }

    return 0;
}

//bro change mo sa addAccounts();
//  this one -->     "  encodedPINs.push_back(encodeString(pin));  "


//security function
    string encodeString(string plain){
        string encoded = "";

        for(int i = 0; i < plain.length(); i++){
            int asciiValue = int(plain[i]);
            encoded += to_string(asciiValue);
        }
        return encoded;
    }

    bool verifyPIN(string input, string stored){
        return encodeString(input) == stored;
    }



//client menyuuwu
void clientMenu () {
    
    string card, pin;

    cout << "\nInsert your Card Number: ";
    cin >> card;

    int accountIndex = -1;

        for(int i = 0; i < cardNumbers.size(); i++){
            if(cardNumbers[i] == card){
                accountIndex = i;
                break;
            }
        }

        if(accountIndex == -1){
            clearScreen();

            cout << "Your card number cannot be found.\n";
            return;
        }

        cout << "Enter your PIN number: ";
        cin >> pin;

        if(encodeString(pin) != encodedPINs[accountIndex]){
            cout << "Wrong PIN number.\n";
            return;
        }

    int choice;

        do{
            clearScreen();

            displayDateTime();

            cout << "===== CLIENT MENU =====\n";
            cout << "\nBank: " << userBanks[accountIndex];
            cout << "\nAccount Type: " << accountTypes[accountIndex];
            cout << "\nCurrent Balance: PHP*******" << endl;

            cout << "\n1. Check Balance.\n";
            cout << "2. Withdraw.\n";
            cout << "3. Transfer.\n";
            cout << "4. View Transaction History.\n" << endl;

            cout << "5. Change your PIN number.\n";
            cout << "6. Logout\n" << endl;

            cout << "Enter your choice: ";
            cin >> choice;

                if(choice == 1){
                    clearScreen();

                    cout << "===== BALANCE CHECK PANEL =====\n";
                    cout << "\nBalance: " << balances[accountIndex] << endl;

                    cout << "\nPress any key to continue another transaction: ";
                    string temp;
                    cin >> temp;
                    

                }
                if(choice == 2){
                    clearScreen();

                    cout << "===== WITHDRAWAL PANEL =====\n" << endl;

                int wdrawAmount1, wdrawAmount2, amount = 0;

                    cout << "1. 500Php";
                    cout << "      2. 1000Php\n";
                    cout << "3. 5,000Php";
                    cout << "    4. 10,000Php\n";
                    cout << "   5. Enter an Amount." << endl;
                    cout << "\nEnter your choice (1-5): ";
                    cin >> wdrawAmount1;

                        if(wdrawAmount1 == 1){
                            amount = 500;
                        }
                        else if(wdrawAmount1 == 2){
                            amount = 1000;
                        }
                        else if(wdrawAmount1 == 3){
                            amount = 5000;
                        }
                        else if(wdrawAmount1 == 4){
                            amount = 10000;
                        }
                        else if(wdrawAmount1 == 5){
                            cout << "\nEnter amount to Withdraw: ";
                            cin >> wdrawAmount2;

                            amount = wdrawAmount2;

                    }
                    if(amount > balances[accountIndex]){
                        cout << "\nSorry, but you do not have enough Balance.\n";
                        continue;

                    }

                    balances[accountIndex] -= amount;
                    logTransaction("Withdrawal", amount, 0);

                        cout << "Please Wait..." << endl;
                        cout << "\nCollect your cash: PHP " << amount << endl;

                        cout << "\nPress any key to continue: ";
                        string temp;
                        cin >> temp;

                }
                if(choice == 3){
                    clearScreen();

                    string receiver;
                    double amount;

                        cout << "===== TRANSFER PANEL =====\n";

                        cout << "Enter receipient card number: ";
                        cin >> receiver;

                        int receiverIndex = -1;

                        for(int i = 0; i < cardNumbers.size(); i++){
                            if(cardNumbers[i] == receiver){
                                receiverIndex = i;
                                break;
                            }
                        }
                        if(receiverIndex == -1){
                            cout << "Sorry, Recipient not found.\n";
                            continue;
                        }

                        cout << "Enter amount to transfer: ";
                        cin >> amount;

                        if(amount > balances[accountIndex]){
                            cout << "Insufficient balance.\n";
                            continue;
                        }
                            balances[accountIndex] -= amount;
                            balances[receiverIndex] += amount;

                            logTransaction("Transfer", amount, 0);
                                cout << "\nTransfered successfully.\n";
                }
                if(choice == 4){
                    clearScreen();

                        cout << "===== VIEWING TRANSACTION HISTORY =====" << endl;

                        if(transactionTypes.empty()){
                            cout << "Oops, you do not have transactions yet.\n";

                        }
                        for(int i = 0; i < transactionTypes.size(); i++){
                            cout << transactionTypes[i] << " | Amount: " << transactionAmounts[i] << " | Fee: " << transactionFees[i] << " | Count: " << transactionQuantities[i] << endl;

                        }

                        cout << "\nPress any key to continue: ";
                        string temp;
                        cin >> temp;
                    
                }
                if(choice == 5){
                    clearScreen();

                    string oldPIN, newPIN;

                    cout << "Enter your current PIN number: ";
                    cin >> oldPIN;

                    if(encodeString(oldPIN) != encodedPINs[accountIndex]){
                        cout << "Incorrect PIN.\n";
                        continue;

                    }
                    cout << "Enter your NEW PIN number: ";
                    cin >> newPIN;

                        encodedPINs[accountIndex] = encodeString(newPIN);

                        cout << "\nSuccessfully changed your PIN number.\n";

            }
            while(choice != 6);
                clearScreen();
                cout << "Logging you out...\n";

            return;
            
        }

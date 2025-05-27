#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

#include "AirGeadDisplays.h"

AirGeadUserInfo user1;

void CharacterPrint(int k, int j){ // function prints out the characters for the displays as they are needed.
    char symbol[] = {'=', '-', '*'}; // list of characters used for the displays
    for (int i = 0; i < k; ++i){    
        cout << symbol[j] ;
    }
}

void AirGeadDisplays::InitialDisplay(){
    
    CharacterPrint(40, 2); // prints out the lines for the initial display
    cout << endl;
    CharacterPrint(14, 2);
    cout << " Data Input ";
    CharacterPrint(14, 2);
    cout << endl;
    CharacterPrint(40, 2);
    cout << endl;
    cout << "Initial Investment Amount: $" << fixed << setprecision(2) << user1.GetInitialAmount() <<endl; // format for the initial display
    cout << "Monthly Deposit: $" << fixed << setprecision(2) << user1.GetMonthlyAmount() << endl;
    cout << "Annual Interest: %" << fixed << setprecision(2) << user1.GetInitialInterest() << endl;
    cout << "Number of years: " << user1.GetYears() << endl;
    cout << "Press any key to continue . . . " << endl;
    cin.ignore();
    cin.get();
}

void AirGeadDisplays::UserInfoCollection(){ //collects user information.
    double deposit;
    double monthdeposit;
    double monthlyInterest;
    int totalyears;

    cout << "Please enter your initial deposit." << endl; 
    cin >> deposit;
        while (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Please enter a vaild number." << endl;
            cin >> deposit;
        }
    user1.SetInitialAmount(deposit);

    cout << "Please enter your monthly deposit." << endl;
    cin >> monthdeposit;
        while (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Please enter a vaild number." << endl;
            cin >> monthdeposit;
        }
    user1.SetMonthlyAmount(monthdeposit);

    cout << "Please enter the interest." << endl;
    cin >> monthlyInterest;
        while (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Please enter a vaild number." << endl;
            cin >> monthlyInterest;
        }
    user1.SetInitialInterest(monthlyInterest);

    cout << "Please enter the years your account will remain active." << endl;
    cin >> totalyears;
        while (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Please enter a vaild number." << endl;
            cin >> totalyears;
        }
    user1.SetYears(totalyears);

    InitialDisplay();
}

void AirGeadDisplays::BalanceWithoutAdditionalDeposits(){
    double balance = user1.GetInitialAmount();
    double interest = user1.GetInitialInterest();
    int numYears = user1.GetYears();
    double interestPerMonth;
    double yearEndInterest;
    
    CharacterPrint(60, 0);  // line for the display, using the '=' character
    cout << "\n    Balance and Interest Without Any Additional Deposits    " << endl;
    CharacterPrint(60, 0);  // line for the display, using the '=' character
    cout << "\nYear        Year End Balance       Year End Earned Interest" << endl;
    CharacterPrint(60, 1);  // line for the display, using the '-' character 
    cout << endl;

    for (int i = 0; i < numYears; i++){
        interestPerMonth = 0; // resets monthly interest after each year
        yearEndInterest = 0; // resets year end interest after each year
            for (int j = 0; j < 12; j++){ // calcualtes the balance and year end interest after each year without additional monthly deposits
                interestPerMonth = (balance) * (interest / 100.0 / 12.0);
                balance = balance + interestPerMonth;
                yearEndInterest += interestPerMonth;
            }
        cout << setw(2) << left << i + 1 << setw(18) << right << fixed << setprecision(2) << "$" << balance <<  setw(25) << right << fixed << setprecision(2) << "$" << yearEndInterest << endl; // outputs year, balance, and yearendinterest after each year is calcuated
    }
    CharacterPrint(60, 1);
    cout << endl;
}

void AirGeadDisplays::BalanceWithAdditionalDeposits(){
    double balance = user1.GetInitialAmount();
    double interest = user1.GetInitialInterest();
    double monthlyDeposit = user1.GetMonthlyAmount();
    int numYears = user1.GetYears();
    double interestPerMonth;
    double yearEndInterest;

    cout << endl;
    CharacterPrint(60, 0);  // line for the display, using the '=' character
    cout << "\n       Balance and Interest With Additional Deposits      " << endl;
    CharacterPrint(60, 0); // line for the display, using the '=' character
    cout << "\nYear        Year End Balance       Year End Earned Interest" << endl;
    CharacterPrint(60, 1); // line for the display, using the '-' character 
    cout << endl;

    for (int i = 0; i < numYears; i++){
        interestPerMonth = 0; // resets monthly interest after each year
        yearEndInterest = 0; // resets year end interest after each year
            for (int j = 0; j < 12; j++){ //calcualtes the balance and year end interest after each year with monthly deposits
                interestPerMonth = (balance + monthlyDeposit) * (interest / 100.0 / 12.0);
                balance = balance + interestPerMonth + monthlyDeposit;
                yearEndInterest += interestPerMonth;
            }
        cout << setw(2) << left << i + 1 << setw(18) << right << fixed << setprecision(2) << "$" << balance <<  setw(25) << right << fixed << setprecision(2) << "$" << yearEndInterest << endl; // outputs year, balance, and yearendinterest after each year is calcuated
    }
    CharacterPrint(60, 1);
    cout << endl;

    user1.SetInitialAmount(0); //resets the variables to 0
    user1.SetMonthlyAmount(0);
    user1.SetInitialInterest(0);
    user1.SetYears(0);
}
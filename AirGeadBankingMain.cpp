#include <iostream>
#include <limits>

#include "AirGeadDisplays.h"

using namespace std;

int main(){
    bool exitProgram = false;
    string yesOrNo;

    AirGeadDisplays display; 

    while (exitProgram != true){ // runs functions while the user doesnt exit the program.
        display.InitialDisplay();
        display.UserInfoCollection();
        display.BalanceWithoutAdditionalDeposits();
        display.BalanceWithAdditionalDeposits();

        cout << "Would you like to try a different set of variables? \n\nYes/No" << endl;
        cin >> yesOrNo; // acquires user input for exiting program
            while(yesOrNo != "Yes" && yesOrNo != "yes" && yesOrNo != "No" && yesOrNo != "no"){
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                cout << "Please enter a valid input" << endl;
                cin >> yesOrNo;
            }
            if (yesOrNo == "Yes" || yesOrNo == "yes"){
                exitProgram = false;
                cout << endl;
            }
            else{
                exitProgram = true;
                cout << "Goodbye." << endl;
            }
    }
    return 0;
}


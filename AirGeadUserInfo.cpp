#include <iostream>
using namespace std;

#include "AirGeadUserInfo.h"
//setters and getters for the 4 banking variables
void AirGeadUserInfo::SetInitialAmount(double amount){
    initialAmount = amount;
}

double AirGeadUserInfo::GetInitialAmount(){
    return initialAmount;
}

void AirGeadUserInfo::SetMonthlyAmount(double monthlyAmount){
    monthlyDeposit = monthlyAmount;
}

double AirGeadUserInfo::GetMonthlyAmount(){
    return monthlyDeposit;
}

void AirGeadUserInfo::SetInitialInterest(double initialInterest){
    interest = initialInterest;
}

double AirGeadUserInfo::GetInitialInterest(){
    return interest;
}

void AirGeadUserInfo::SetYears(int years){
    numOfYears = years;
}

int AirGeadUserInfo::GetYears(){
    return numOfYears;
}



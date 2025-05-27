#ifndef AIRGEADUSERINFO_H
#define AIRGEADUSERINFO_H


class AirGeadUserInfo{
    public:
    void SetInitialAmount(double amount);
    double GetInitialAmount();

    void SetMonthlyAmount(double monthlyAmount);
    double GetMonthlyAmount();

    void SetInitialInterest(double initialInterest);
    double GetInitialInterest();

    void SetYears(int years);
    int GetYears();

    
    private: // 4 variables for banking
        double initialAmount = 0;
        double monthlyDeposit = 0;
        double interest = 0;
        int numOfYears = 0;
};

#endif
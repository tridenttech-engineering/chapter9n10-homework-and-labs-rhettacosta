//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by Rhett Acosta on 3/24/25

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);
double getTotal (double, int);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double totalCreditPayment = 0.0;
    double totalDealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, 
        dealerRate / 12, term * 12); 
    totalCreditPayment = getTotal(creditPayment, term * 12);
    totalDealerPayment = getTotal(dealerPayment, term * 12);
    //assign values to calculate payments
    
    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union monthly payment: $" 
        << creditPayment << endl;
    cout << "Dealer monthly payment: $"
        << dealerPayment << endl;
    cout << "Total credit union payment: $"
        << totalCreditPayment << endl;
    cout << "Total dealer payment: $"
        << totalDealerPayment << endl;
    
    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;
    double denom = 0.0;
    denom = (1 - pow(monthRate + 1, -months));

    if (denom == 0)
        cout << "-1";
    else 
        monthPay = prin * monthRate / denom;
    
    return monthPay;
    
}

double getTotal(double monthPay, int months)
{
    double total = 0.0;
    double roundedPay = 0.0;
    
    roundedPay = static_cast<int>((monthPay + .005) * 100)/ 100.0;
    total = roundedPay * months;
    
    return total;
}


//end of getPayment function//*****function definition*****

//Lab10-2.cpp - displays total owed
//Created/revised by Rhett Acosta on 3/24/25

#include <iostream>
#include <iomanip>
using namespace std;
//function prototypes
void displayChoices();
void getRegular (int windows, double price, double &total);
void getBoGo (int windows, double price, double &total);

int main()
{
    int numWindows = 0;
    double winPrice = 0.0;
    double total = 0.0;
    int choice = 0;

    displayChoices();
    cout << " Enter your choice (1 or 2): ";
    cin >> choice;
    if (choice == 1 || choice == 2)
    {
        cout << "Number of windows: ";
        cin >> numWindows;
        cout << "Price per window: ";
        cin >> winPrice;
        
        if (choice == 1)
            getRegular(numWindows, winPrice, total);
        else
            getBoGo(numWindows, winPrice, total); 

        cout << fixed << setprecision(2) << endl;
        cout << "Total owed: $" << total << endl;
    }
    else
        cout << "Invalid choice" << endl;
    
    return 0;
} //end of main function

//*****function definitions*****
void displayChoices()
{
    cout << "Pricing Options: " << endl;
    cout << "1 Regular windows" << endl;
    cout << "2 BoGo windows" << endl;
}

void getRegular(int windows, double price, double &total)
{
    total = windows * price;
}

void getBoGo(int windows, double price, double &total)
{
    total = (windows / 2 + windows % 2) * price;
}

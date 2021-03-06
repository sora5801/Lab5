/*****************************************************************************/
//  Filename:      Lab5.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.05.31
//
//
//  Description:  This program calculates the monthly cost of a house given
//                the selling price, annual rate of interest, and number of
//                years for the loan. After calculating them, it outputs the values
//                in a neat format in a text file. 
//
//
/*****************************************************************************/

#include <math.h>
#include <fstream>
#include <iomanip>
#include <iostream>

//The annual property tax rate is 1.25% of selling price,
//utilities is $300 per month, and insurance is $550 per year.

#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_UTILITIES 300.00

using namespace std;


//The function Prototypes are declared here. There are four
//functions for this program
void input(double &, double &, int &);
void output(double &, double &, double &, double &, int &, const double &, double &, double &, double &, double &);
void subcalculations(double &, double &, int &, const double &, double &, double &, double &);
void calculations(double &, double &, int &, const double &);

/*****************************************************************************/
//
// Function:   int main()
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: This is the main function. It declares variables for the selling price,
//              annual rate of interest, and the number of years for the loan. Then it
//              passes them into the input function and then passes them to the 
//              calculation function where the output function is.
// 
//
/*****************************************************************************/

int main()
{
   const double DOWN_PAYMENT_PERCENTAGE = 0.2; //The down payment is 20% of the selling price

   //The input variables are declared here
   double sellingPrice; // selling price of the house
   double annualRateOfInterest; // interest rate on the loan 
   int numberOfYears; //Number of years to pay off the loan

   //I pass the reference of the variables into the functions
   input(sellingPrice, annualRateOfInterest, numberOfYears);
   calculations(sellingPrice, annualRateOfInterest, numberOfYears, DOWN_PAYMENT_PERCENTAGE);
  
   return 0;
}

/*****************************************************************************/
//
// Function:   void input(double &sellingPrice, double &annualRateOfInterest,
//                           int &numberOfYears)
//
// Parameters:  double &sellingPrice - selling price of the house
//              double &annualRateOfInterest- interest rate on the loan 
//              int &numberOfYears - Number of years to pay off the loan
//
// Outputs:    None
//
// Returns:  
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: This function asks for the selling price, annual rate of interest
//              and number of years to pay off loan and then store the values into 
//              the address of several variables.
// 
//
/*****************************************************************************/

void input(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears) {
   cout << "What is the selling price?" << endl;
   cin >> sellingPrice;
   cout << "What is the annual rate of interest?" << endl;
   cin >> annualRateOfInterest;
   cout << "What is the number of years for the loan?" << endl;
   cin >> numberOfYears;
}
/*****************************************************************************/
//
// Function:  void output(double &sellingPrice, double &downPayment, double &loanAmount, double &annualRateOfInterest, 
//                         int &numberOfYears, const double &downPaymentPercentage,
//                         double &mortgagePayment, double &propertyTax, double &insurance, double &total)
//
// Parameters: double &sellingPrice - selling price of the house
//             double &downPayment - the initial payment
//             double &loanAmount - How much money to borrow for the house
//             double &annualRateOfInterest- interest rate on the loan 
//             int &numberOfYears - Number of years to pay off the loan
//             const double &downPaymentPercentage - down payment percentage of selling price
//             double &mortgagePayment - The calculated montly payment amount
//             double &propertyTax - The amount to pay per month in property tax.
//             double &insurance - the monthly cost of insurance
//             double &total the sum of mortgage payment, property tax, insurance, and utilities

// Outputs:    None
//
// Returns:    None
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: This functions outputs everything that was calculated and declared
//              and put them into a .txt file in a neat and ordered fashion.
//
//
/*****************************************************************************/

void output(double &sellingPrice, double &downPayment, double &loanAmount, double &annualRateOfInterest, 
   int &numberOfYears, const double &downPaymentPercentage,
   double &mortgagePayment, double &propertyTax, double &insurance, double &total)
{
   ofstream myfile;
   myfile.open("OutputDataSet1.txt");
   myfile << setprecision(2) << fixed;
   myfile << "****************************************************************" << endl;
   myfile << setw(40)<< "MONTHLY COST OF HOUSE" << endl;
   myfile << "****************************************************************" << endl;
   myfile << "SELLING PRICE" << setw(36) << "$ " << sellingPrice << endl;
   myfile << "DOWN PAYMENT" << setw(37) << "$ " << downPayment << endl;
   myfile << "AMOUNT OF LOAN" << setw(35) << "$ " << loanAmount << endl;
   myfile << "\n";
   myfile << "INTEREST RATE" << setw(27) << annualRateOfInterest <<"%"<< endl;
   myfile << "TAX RATE" << setw(32) << TAX_RATE * 100 <<"%"<< endl;
   myfile << "\n";
   myfile << "DURATION OF LOAN(YEARS)" << setw(14) << numberOfYears << " yrs"<< endl;
   myfile << "\n\n";
   myfile << "********************" << endl;
   myfile << "MONTHLY PAYMENT" << endl;
   myfile << "********************" << endl;
   myfile << "\n";
   myfile << "MORTGAGE PAYMENT" << setw(35) << "$ " << mortgagePayment << endl;
   myfile << "UTILITIES" << setw(43) << "$  " << COST_OF_UTILITIES << endl;
   myfile << "PROPERTY TAXES" << setw(38) << "$  " << propertyTax << endl;
   myfile << "INSURANCE" << setw(44) << "$   " << insurance << endl;
   myfile << setw(58)<< "----------------" << endl;
   myfile << setw(51)<< "$ " << total << endl;
   myfile.close();
}
/*****************************************************************************/
//
// Function:  void subcalculations(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears, 
//                                 const double &downPaymentPercentage, double &downPayment, 
//                                 double &loanAmount,double &mortgagePayment)
//
// Parameters: double &sellingPrice - selling price of the house
//             double &annualRateOfInterest- interest rate on the loan 
//             int &numberOfYears - Number of years to pay off the loan
//             const double &downPaymentPercentage - down payment percentage of selling price
//             double &downPayment - the initial payment
//             double &loanAmount - How much money to borrow for the house
//             double &mortgagePayment - The calculated montly payment amount

// Outputs:    None
//
// Returns:    None
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: This function is the subfunction called by the main calculation functions. 
//              This function takes the address of the down payment, loan amount, and
//              mortgage payment and makes the calculation.
// 
/*****************************************************************************/

void subcalculations(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears, 
   const double &downPaymentPercentage, double &downPayment, double &loanAmount,
   double &mortgagePayment) {
   downPayment = sellingPrice * downPaymentPercentage; //Down payment is the initial payment made when something is bought on credit
   loanAmount = sellingPrice - downPayment; // It is the amount of money borrowed
   mortgagePayment = (loanAmount * (annualRateOfInterest * 0.01 / 12.0) * //This formula that comes for the monthly mortgage payment.
      pow((1 + (annualRateOfInterest * 0.01 / 12.0)), numberOfYears * 12)) /
      (pow((1 + (annualRateOfInterest * 0.01 / 12.0)), numberOfYears * 12) - 1.0);
}
/*****************************************************************************/
//
// Function:  void calculations(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears, 
//                              const double &downPaymentPercentage) 
//
// Parameters: double &sellingPrice - selling price of the house
//             double &annualRateOfInterest - interest rate on the loan
//             int &numberOfYears - Number of years to pay off the loan
//             const double &downPaymentPercentage - down payment percentage of selling price
//             
// Outputs:    None
//
// Returns:    None
//
// Author:     
//
// Date:       2018.31.05
// 
// Description: This function declares the variables for down payment, loan amount, and 
//              mortgage payment and pass them by reference to the subcalculation functions.
//              This function then calculates the monthly cost in property tax, 
//              monthly insurance cost,and adds the monthly mortgage payment and monthly
//              utilities for the total. Then it passes all the variables by reference
//              to the output function.
/*****************************************************************************/

void calculations(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears, const double &downPaymentPercentage) {
   //Variables for the down payment, loan amount, and mortgage payment are declared here to be passed.
   double downPayment;
   double loanAmount;
   double mortgagePayment;

   //I first call the subcalculation function.
   subcalculations(sellingPrice, annualRateOfInterest, numberOfYears, downPaymentPercentage, downPayment, loanAmount, mortgagePayment);

   //I declare the variables for the monthly property tax, monthly insurance cost, and monthly total here and the calculations for them.
   double propertyTax = sellingPrice * TAX_RATE/12;
   double insurance = COST_OF_INSURANCE / 12.0;
   double total = mortgagePayment + COST_OF_UTILITIES + propertyTax + insurance;

   //Then I call the output function.
   output(sellingPrice, downPayment, loanAmount, annualRateOfInterest, numberOfYears, downPaymentPercentage, mortgagePayment, propertyTax, insurance, total);

}
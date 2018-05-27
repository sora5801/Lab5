/*****************************************************************************/
//  Filename:      Lab5.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.05.31
//
//
//  Description:
//
//
/*****************************************************************************/


#include <math.h>
#include <fstream>
#include <iomanip>
#include <iostream>

#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_UTILITIES 300.00

using namespace std;
//Down payment is the initial payment made when
//something is bought on credit. Since the down payment
//is 20% of the selling price, that means that you pay
//20% of the selling price to the seller upfront and
//you borrow the rest.

//The function Prototypes are declared here.
void input(double &, double &, int &);
void output(double &, double &, double &, double &, int &, const double &, double &, double &, double &, double &);
void subcalculations(double &, double &, int &, const double &, double &, double &, double &);
void calculations(double &, double &, int &, const double &);

int main()
{
   const double DOWN_PAYMENT_PERCENTAGE = 0.2;
   double SellingPrice1;
   double AnnualRateOfInterest1;
   int NumberOfYears1;
   input(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1);
   calculations(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1, DOWN_PAYMENT_PERCENTAGE);
  
   return 0;
}
/*****************************************************************************/
//
// Function:   
//
// Parameters: 
//
// Outputs:    None
//
// Returns:  
//
// Author:     
//
// Date:       2016.10.05
//
//
// Description:
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
// Function:   
//
// Parameters: 
//
// Outputs:    None
//
// Returns:    None
//
// Author:     Matthew Fu
//
// Date:       2016.10.05
//
//
// Description: This functions outputs everything into a .txt file in
//              a neat or ordered fashion
//
//
/*****************************************************************************/

void output(double &SellingPrice2, double &DownPayment2, double &LoanAmount2, double &AnnualRateOfInterest2, int &NumberOfYears2, const double &DownPaymentPercentage2,
   double &MortgagePayment2, double &PropertyTax2, double &Insurance2, double &Total2)
{
   ofstream myfile;
   myfile.open("Output.txt");
   myfile << setprecision(2) << fixed;
   myfile << "****************************************************************" << endl;
   myfile << setw(40)<< "MONTHLY COST OF HOUSE" << endl;
   myfile << "****************************************************************" << endl;
   myfile << "SELLING PRICE" << setw(36) << "$ " << SellingPrice2 << endl;
   myfile << "DOWN PAYMENT" << setw(37) << "$ " << DownPayment2 << endl;
   myfile << "AMOUNT OF LOAN" << setw(35) << "$ " << LoanAmount2 << endl;
   myfile << "\n";
   myfile << "INTEREST RATE" << setw(27) << AnnualRateOfInterest2 <<"%"<< endl;
   myfile << "TAX RATE" << setw(32) << TAX_RATE * 100 <<"%"<< endl;
   myfile << "\n";
   myfile << "DURATION OF LOAN(YEARS)" << setw(14) << NumberOfYears2 << " yrs"<< endl;
   myfile << "\n\n";
   myfile << "********************" << endl;
   myfile << "MONTHLY PAYMENT" << endl;
   myfile << "********************" << endl;
   myfile << "\n";
   myfile << "MORTGAGE PAYMENT" << setw(35) << "$ " << MortgagePayment2 << endl;
   myfile << "UTILITIES" << setw(43) << "$  " << COST_OF_UTILITIES << endl;
   myfile << "PROPERTY TAXES" << setw(39) << "$   " << PropertyTax2 << endl;
   myfile << "INSURANCE" << setw(44) << "$   " << Insurance2 << endl;
   myfile << setw(58)<< "----------------" << endl;
   myfile << setw(51)<< "$ " << Total2 << endl;
   myfile.close();
}
/*****************************************************************************/
//
// Function:  
//
// Parameters: 
//
// Outputs:    None
//
// Returns:    
//
// Author:     
//
// Date:       2016.10.05
//
//
// Description:
// 
/*****************************************************************************/

void subcalculations(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears, const double &downPaymentPercentage, double &downPayment, double &loanAmount,
   double &mortgagePayment) {
   downPayment = sellingPrice * downPaymentPercentage; //Down payment is the initial payment made when something is bought on credit
   loanAmount = sellingPrice - downPayment; // It is the amount of money borrowed
   mortgagePayment = (loanAmount * (annualRateOfInterest * 0.01 / 12.0) * //This formula comes from the lab assignment.
      pow((1 + (annualRateOfInterest * 0.01 / 12.0)), numberOfYears * 12)) / (pow((1 + (annualRateOfInterest * 0.01 / 12.0)), numberOfYears * 12) - 1.0);
}
/*****************************************************************************/
//
// Function:   
//
// Parameters: 
//
// Outputs:    None
//
// Returns:    
//
// Author:     
//
// Date:       2016.10.05
// 
// Description:
/*****************************************************************************/

void calculations(double &sellingPrice, double &annualRateOfInterest, int &numberOfYears, const double &downPaymentPercentage) {
   double downpayment2;
   double loanamount2;
   double mortgagepayment2;

   subcalculations(sellingPrice, annualRateOfInterest, numberOfYears, downPaymentPercentage, downpayment2, loanamount2, mortgagepayment2);

   double propertyTax = mortgagepayment2 * TAX_RATE;
   double insurance = COST_OF_INSURANCE / 12.0;
   double total = mortgagepayment2 + COST_OF_UTILITIES + propertyTax + insurance;

   output(sellingPrice, downpayment2, loanamount2, annualRateOfInterest, numberOfYears, downPaymentPercentage, mortgagepayment2, propertyTax, insurance, total);

}
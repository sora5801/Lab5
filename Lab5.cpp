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
#define COST_OF_INSURANCE 550
#define COST_OF_UTILITIES 300

using namespace std;
//Down payment is the initial payment made when
//something is bought on credit. Since the down payment
//is 20% of the selling price, that means that you pay
//20% of the selling price to the seller upfront and
//you borrow the rest.

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

void input(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears) {
   cout << "What is the selling price?" << endl;
   cin >> SellingPrice;
   cout << "What is the annual rate of interest?" << endl;
   cin >> AnnualRateOfInterest;
   cout << "What is the number of years for the loan?" << endl;
   cin >> NumberOfYears;
}
/*****************************************************************************/
//
// Function:   
//
// Parameters: 
//
// Outputs:    None
//
// Returns:    double – resistance, in ohms
//
// Author:     Jack Ryan
//
// Date:       2016.10.05
//
//
// Description:
//
//
/*****************************************************************************/

void output(double &SellingPrice2, double &DownPayment2, double &LoanAmount2, double &AnnualRateOfInterest2, int &NumberOfYears2, const double &DownPaymentPercentage2,
   double &MortgagePayment2, double &PropertyTax2, double &Insurance2, double &Total2)
{
   ofstream myfile;
   myfile.open("example.txt");
   myfile << setprecision(2) << fixed;
   myfile << "****************************************************************" << endl;
   myfile << "MONTHLY COST OF HOUSE" << endl;
   myfile << "****************************************************************" << endl;
   myfile << "SELLING PRICE" << setw(20) << SellingPrice2 << endl;
   myfile << "DOWN PAYMENT" << setw(20) << DownPayment2 << endl;
   myfile << "AMOUNT OF LOAN" << setw(20) << LoanAmount2 << endl;
   myfile << "INTEREST RATE" << setw(14) << AnnualRateOfInterest2 <<"%"<< endl;
   myfile << "TAX RATE" << setw(14) << TAX_RATE * 100 <<"%"<< endl;
   myfile << "DURATION OF LOAN(YEARS)" << NumberOfYears2 << " yrs"<< endl;
   myfile << "MONTHLY PAYMENT" << endl;
   myfile << MortgagePayment2 << endl;
   myfile << COST_OF_UTILITIES << endl;
   myfile << PropertyTax2 << endl;
   myfile << Insurance2 << endl;
   myfile << "---------------------" << endl;
   myfile << Total2 << endl;
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

void subcalculations(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears, const double &DownPaymentPercentage, double &downPayment, double &loanAmount,
   double &mortgagePayment) {
   downPayment = SellingPrice * DownPaymentPercentage;
   loanAmount = SellingPrice - downPayment;
   mortgagePayment = (loanAmount * (AnnualRateOfInterest * 0.01 / 12.0) *
      pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears * 12)) / (pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears * 12) - 1.0);
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

void calculations(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears, const double &DownPaymentPercentage) {
   double downpayment2;
   double loanamount2;
   double mortgagepayment2;

   subcalculations(SellingPrice, AnnualRateOfInterest, NumberOfYears, DownPaymentPercentage, downpayment2, loanamount2, mortgagepayment2);

   double PropertyTax = mortgagepayment2 * TAX_RATE;
   double Insurance = COST_OF_INSURANCE / 12.0;
   double Total = mortgagepayment2 + COST_OF_UTILITIES + PropertyTax + Insurance;

   output(SellingPrice, downpayment2, loanamount2, AnnualRateOfInterest, NumberOfYears, DownPaymentPercentage, mortgagepayment2, PropertyTax, Insurance, Total);

}
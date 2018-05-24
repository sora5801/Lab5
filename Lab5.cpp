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



void input(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears) {
   cout << "What is the selling price?" << endl;
   cin >> SellingPrice;
   cout << "What is the annual rate of interest?" << endl;
   cin >> AnnualRateOfInterest;
   cout << "What is the number of years for the loan?" << endl;
   cin >> NumberOfYears;
}

void output(double &SellingPrice2, double &DownPayment2, double &LoanAmount2, double &AnnualRateOfInterest2, int &NumberOfYears2, const double &DownPaymentPercentage2,
   double &MortgagePayment2, double &PropertyTax2, double &Insurance2, double &Total2)
{
   ofstream myfile;
   myfile.open("example.txt");
   myfile << setprecision(2) << fixed;
   myfile << "MONTHLY COST OF HOUSE" << endl;
   myfile << "SELLING PRICE" << setw(20) << SellingPrice2 << endl;
   myfile << DownPayment2 << endl;
   myfile << LoanAmount2 << endl;
   myfile << AnnualRateOfInterest2 << endl;
   myfile << TAX_RATE * 100 << endl;
   myfile << NumberOfYears2 << endl;
   myfile << "MONTHLY PAYMENT" << endl;
   myfile << MortgagePayment2 << endl;
   myfile << COST_OF_UTILITIES << endl;
   myfile << PropertyTax2 << endl;
   myfile << Insurance2 << endl;
   myfile << "---------------------" << endl;
   myfile << Total2 << endl;
   myfile.close();
}

void subcalculations(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears, const double &DownPaymentPercentage, double &downPayment3, double &loanAmount3,
   double &mortgagePayment3) {
   double downPayment = SellingPrice * DownPaymentPercentage;
   double loanAmount = SellingPrice - downPayment3;
   double mortgagePayment = (loanAmount * (AnnualRateOfInterest * 0.01 / 12.0) *
      pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears)) / (pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears) - 1.0);
}


void calculations(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears, const double &DownPaymentPercentage/*, double &downPayment, double &loanAmount,
   double &mortgagePayment*/) {
   double downpayment2;
   double loanamount2;
   double mortgagepayment2;
   /*double downPayment = SellingPrice * DownPaymentPercentage;
   double loanAmount = SellingPrice - downPayment;

   //double NumberOfCompoundingPeriods = NumberOfYears * 12.0;
   //double RateOfInterestPerCompoundingPeriod = AnnualRateOfInterest * 0.01 / 12.0;
   double mortgagePayment = (loanAmount * (AnnualRateOfInterest * 0.01 / 12.0) *
      pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears)) / (pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears) - 1.0);
      */
   subcalculations(SellingPrice, AnnualRateOfInterest, NumberOfYears, DownPaymentPercentage, downpayment2, loanamount2, mortgagepayment2);

   double PropertyTax = SellingPrice * TAX_RATE;
   double Insurance = COST_OF_INSURANCE / 12.0;
   double Total = mortgagepayment2 + COST_OF_UTILITIES + PropertyTax + Insurance; 


   output(SellingPrice, downpayment2, loanamount2, AnnualRateOfInterest, NumberOfYears, DownPaymentPercentage, mortgagepayment2, PropertyTax, Insurance, Total);

}



//void output(double &Downpayment/*, double &LoanAmount2, double */ )
/*{ cout << setprecision(2) << fixed;
cout << "Monthly Cost Of House" << endl;
cout << "SELLING PRICE" << setw(20) <<  Downpayment << endl;
/*cout << DownPayment << endl;
cout << LoanAmount << endl;
cout << AnnualRateOfInterest << endl;
cout << TAX_RATE * 100 << endl;
cout << NumberOfYears << endl;
cout << MortgagePayment << endl;
cout << COST_OF_UTILITIES << endl;
cout << PropertyTax << endl;
cout << Insurance << endl;
cout << Total << endl; */
//}*/

int main()
{
   const double DOWN_PAYMENT_PERCENTAGE = 0.2;
   double SellingPrice1;
   double AnnualRateOfInterest1;
   int NumberOfYears1;
   /*double downpayment1;
   double loanamount1;
   double mortgagepayment1; */
   input(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1);
   calculations(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1, DOWN_PAYMENT_PERCENTAGE/*, downpayment1, loanamount1, mortgagepayment1*/);
   //output(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1);

   /*double DownPayment = SellingPrice * DOWN_PAYMENT_PERCENTAGE;
   double LoanAmount = SellingPrice - DownPayment;

   double NumberOfCompoundingPeriods = NumberOfYears * 12.0;
   double RateOfInterestPerCompoundingPeriod = AnnualRateOfInterest * 0.01 / 12.0;

   double MortgagePayment = (LoanAmount * RateOfInterestPerCompoundingPeriod *
   pow((1 + RateOfInterestPerCompoundingPeriod), NumberOfYears))/ (pow((1 + RateOfInterestPerCompoundingPeriod), NumberOfYears) - 1.0);
   double PropertyTax = SellingPrice * TAX_RATE;
   double Insurance = COST_OF_INSURANCE / 12.0;
   double Total = MortgagePayment + COST_OF_UTILITIES + PropertyTax + Insurance;

   cout << setprecision(2) << fixed;
   cout << "Monthly Cost Of House" << endl;
   cout << "SELLING PRICE" << setw(20) <<  SellingPrice << endl;
   cout << DownPayment << endl;
   cout << LoanAmount << endl;
   cout << AnnualRateOfInterest << endl;
   cout << TAX_RATE * 100 << endl;
   cout << NumberOfYears << endl;
   cout << MortgagePayment << endl;
   cout << COST_OF_UTILITIES << endl;
   cout << PropertyTax << endl;
   cout << Insurance << endl;
   cout << Total << endl;

   */


   return 0;
}


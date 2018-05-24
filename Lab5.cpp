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
   cout << setprecision(2) << fixed;
   cout << "Monthly Cost Of House" << endl;
   cout << "SELLING PRICE" << setw(20) << SellingPrice2 << endl;
   cout << DownPayment2 << endl;
   cout << LoanAmount2 << endl;
   cout << AnnualRateOfInterest2 << endl;
   cout << TAX_RATE * 100 << endl;
   cout << NumberOfYears2 << endl;
   cout << "MONTHLY PAYMENT" << endl;
   cout << MortgagePayment2 << endl;
   cout << COST_OF_UTILITIES << endl;
   cout << PropertyTax2 << endl;
   cout << Insurance2 << endl;
   cout << "---------------------" << endl;
   cout << Total2 << endl;
}


void Calculations(double &SellingPrice, double &AnnualRateOfInterest, int &NumberOfYears, const double &DownPaymentPercentage) {
   double DownPayment = SellingPrice * DownPaymentPercentage;
   double LoanAmount = SellingPrice - DownPayment;

   //double NumberOfCompoundingPeriods = NumberOfYears * 12.0;
   //double RateOfInterestPerCompoundingPeriod = AnnualRateOfInterest * 0.01 / 12.0;

   double MortgagePayment = (LoanAmount * (AnnualRateOfInterest * 0.01 / 12.0) *
      pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears)) / (pow((1 + (AnnualRateOfInterest * 0.01 / 12.0)), NumberOfYears) - 1.0);
   double PropertyTax = SellingPrice * TAX_RATE;
   double Insurance = COST_OF_INSURANCE / 12.0;
   double Total = MortgagePayment + COST_OF_UTILITIES + PropertyTax + Insurance;

   output(SellingPrice, DownPayment, LoanAmount, AnnualRateOfInterest, NumberOfYears, DownPaymentPercentage, MortgagePayment, PropertyTax, Insurance, Total);

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
   input(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1);
   Calculations(SellingPrice1, AnnualRateOfInterest1, NumberOfYears1, DOWN_PAYMENT_PERCENTAGE);
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


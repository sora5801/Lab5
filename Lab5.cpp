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

// double Calculations() {}




int main()
{
   const double DOWN_PAYMENT_PERCENTAGE = 0.2;
   double SellingPrice;
   double AnnualRateOfInterest;
   int NumberOfYears;
   
   cout << "What is the selling price?" << endl;
   cin >> SellingPrice;
   cout << "What is the annual rate of interest?" << endl;
   cin >> AnnualRateOfInterest;
   cout << "What is the number of years for the loan?" << endl;
   cin >> NumberOfYears;

   double DownPayment = SellingPrice * DOWN_PAYMENT_PERCENTAGE;
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




    return 0;
}


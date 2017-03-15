/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on February 22, 2017, 1:20 PM
 * Purpose:  Gaddis Chapter 3 Programming Challenge 13: Currency
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float dollar,yen,euro;   //USD Amount,Yen Amount,Euro Amount
    
    //Input or initialize values Here
    cout<<"This Program will convert USD Currency to Euros and Yen."<<endl;
    cout<<"Please enter the amount of USD."<<endl;
    cin>>dollar;  //User enters dollar amount
    
    //Process/Calculations Here
    euro=dollar*0.95f; //1 Dollar to 0.95 Exchange rate for Euro of 2/22/17
    yen=dollar*113.03f; //1 Dollar to 113.03 Exchange rate for Yen of 2/22/17
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    
    //Output Located Here
    cout<<"USD:   $"<<dollar<<endl;
    cout<<"Euros: €"<<euro<<" (at 1 Dollar to 0.95 Euro exchange rate.)"<<endl;
    cout<<"Yen:   ¥"<<yen<<" (at 1 Dollar to 113.03 Yen exchange rate.)"<<endl;
    
    //Exit
    return 0;
}

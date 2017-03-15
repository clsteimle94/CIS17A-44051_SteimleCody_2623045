/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 2 Programming Challenge 10: Miles per Gallon
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes

//Program Execution Begins
int main(int argc, char** argv) {
    //Declare Variables
    int gas=15;    //Max tank in gallons
    int miles=375; //Distance traveled on max tank
    float mpg;     //Miles per gallon
    
    //Input or initialize values Here
    
    //Process
    mpg=miles/gas;
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); 
    
    //Output
    cout<<"A car with a "<<gas<<" gallon tank can travel "<<miles<<" on a "
            "full tank."<<endl;
    cout<<"Therfore the car will get "<<mpg<<" miles per gallon."<<endl;
   
    //Exit
    return 0;
}

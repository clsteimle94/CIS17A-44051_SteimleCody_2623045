/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on February 22, 2017, 1:10 PM
 * Purpose:  Gaddis Chapter 3 Programming Challenge 12: Celsius to Fahrenheit
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
    int celsi;     //Celsius
    float fahren;  //Fahrenheit
    
    //Input or initialize values Here
    cout<<"This program will convert Celsius into Fahrenheit."<<endl;
    cout<<"Please enter the temperature in Celsius."<<endl;
    cin>>celsi;    //User inputs the temperature in Celsius
    
    //Process/Calculations Here
    fahren=(9.0f/5.0f)*celsi+32; //Converts Celsius into Fahrenheit
    
    //Output Located Here
    cout<<"The temperature ("<<celsi<<"C) converted to Fahrenheit: "
            <<fahren<<"F."<<endl;

    //Exit
    return 0;
}


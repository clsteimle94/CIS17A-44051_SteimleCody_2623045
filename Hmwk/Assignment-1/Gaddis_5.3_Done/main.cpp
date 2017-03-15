/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 5 Programming Challenge 3: Ocean Levels
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
    float ocnRse=1.5f; //Millimeters per year the ocean level rises
    float ocnLvl=0.0f;   //Tracks the total rising levels yearly
    int years=25;     //The number of years the ocean level will rise
    
    //Input or initialize values Here

    //Process/Output    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    //Calculate and display the yearly increase
    for(int count=1;count<=years;count++){
        ocnLvl=ocnLvl+ocnRse;
        cout<<"Years passed: "<<count<<" | The ocean level has risen: "
                <<ocnLvl<<" millimeters."<<endl;
    }
    
    //Exit
    return 0;
}

//3. Ocean Levels
//Assuming the ocean’s level is currently rising at about 1.5 millimeters per year, write
//a program that displays a table showing the number of millimeters that the ocean will
//have risen each year for the next 25 years. 
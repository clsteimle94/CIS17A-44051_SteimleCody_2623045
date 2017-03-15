/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 6 Programming Challenge 7: Celsius Temperature Table
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float celsius(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int fahren=0; //Fahrenheit (Begin on 0F and end on 20F)
    float celsi;  //Celsius

    //Input or initialize values Here
    
    //Process/Output
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    
    //Use a loop to call Celsius function ~21 times
    cout<<"F   "<<"   C"<<endl;
    do{
        cout<<fahren<<"F  =  "<<celsius(fahren)<<"C"<<endl;
        fahren++;
    }while(fahren<21);
    
    //Exit
    return 0;
}

//Celsius function
//Inputs: Fahrenheit
//Returns: Celsius conversion
float celsius(int fahr){
    float cels;
    cels=5.0f/9.0f*(fahr-32);  //Conversion from F -> C
    return cels;
}
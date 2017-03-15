/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 9 Programming Challenge 5: Pointer Rewrite
 */

//System Libraries Here
#include <iostream>   //Input/output
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes
int swpCalc(int *,int *); //Swap Calculation, ten fold then addition

//Program Execution Begins
int main(int argc, char** argv) {        
    //Declare Variables
    int *x, *y;  //The pointers of the variables
    int a, b;    //The variables
    
    //Set the pointers
    x=&a;
    y=&b;
    
    //Initialize/Input
    cout<<"This program uses pointers to pass variables, and also finds the sum"
            " of two numbers ten-folded."<<endl;
    cout<<"Please enter the first number: "<<endl;
    cin>>a;
    cout<<"Please enter the second number: "<<endl;
    cin>>b;
    
    //Call the Swap Calculation function
    cout<<"The results of the calculation (x*10)+(y*10): ";
    cout<<swpCalc(x,y);

    //Exit
    return 0;
}

int swpCalc(int *x, int *y){
    int temp = *x;  //temp=2
    *x = *y * 10;   //3x10=30
    *y = temp * 10; //2x10=20
    return *x + *y; //30+20=50
}

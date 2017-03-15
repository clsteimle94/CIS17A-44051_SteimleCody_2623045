/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:00 PM
 * Purpose:  Gaddis Chapter 5 Programming Challenge 11: Population
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int popltn; //Base population needs to be 2 or more
    float growth;  //Growth Percentage, has to be positive
    int numDays; //Number of days to multiply,  needs to be 1 or more
    
    //Input or initialize values Here
    cout<<"Please enter the following information."<<endl;
    do{
        cout<<"Starting population size? (Min. 2)"<<endl;
        cin>>popltn;
    }while(popltn<2); //Input Validation
    do{
        cout<<"Daily growth percent? (Positive Value)"<<endl;
        cin>>growth;  
    }while(growth<0); //Input Validation
    do{
        cout<<"Number of days to multiply? (Min. 1)"<<endl;
        cin>>numDays;       
    }while(numDays<1); //Input Validation    

    //Process/Calculations Here -> Map inputs to outputs and display
    //Convert "growth" percent into a prop
    growth=growth/100.0f; //i.e. 6% -> 0.06
    //Calculate and output the population for each day
    for(int count=1;count<numDays;count++){
        cout<<"Day: "<<count<<" Population: "<<popltn<<endl;
        popltn=(popltn*growth)+popltn;
    }
    
    //Output
    //The final population
    cout<<"The final population: "<<popltn<<endl;
    
    //Exit
    return 0;
}
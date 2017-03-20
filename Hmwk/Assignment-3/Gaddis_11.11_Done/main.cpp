/*
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 22, 2017, 11:45 AM
 * Purpose:  Gaddis 11.11 - Monthly Budget
 */

//System Libraries Here
#include <iostream> //Input/Output
using namespace std;

//User Libraries Here
#include "budget.h"

//Global Constants

//Function Prototypes Here
Budget mSpent(Budget);     //Money Spent
Budget getBdgt(Budget);    //Stores the budget amounts
void chkBdgt(Budget, Budget); //Calculate the budget

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    Budget spent;     //The amount spent
    Budget allowed;   //The allowed amount of a budget
    
    //Initialize
    cout<<"This program takes a structure to help calculate the results of a "
            "monthly budget."<<endl;
    
    //Get the Budget information
    allowed = getBdgt(allowed);
    
    //Collect the budget for the month
    spent = mSpent(spent);
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
     
    //Compared the spend amount with the allowed amount
    chkBdgt(spent,allowed);
            
    //Exit Program
    return 0;
} 

Budget mSpent(Budget bdgt){
    cout<<"Enter the amount spent on housing ($500.00 Budget):"<<endl;
    cin>>bdgt.housing;
    cout<<"Enter the amount spent on utilities ($150.00 Budget):"<<endl;
    cin>>bdgt.util;
    cout<<"Enter the amount spent on household expenses ($65.00 Budget):"<<endl;
    cin>>bdgt.housHld;
    cout<<"Enter the amount spent on transportation ($50.00 Budget):"<<endl;
    cin>>bdgt.transpt;
    cout<<"Enter the amount spent on food ($250.00 Budget):"<<endl;
    cin>>bdgt.food;
    cout<<"Enter the amount spent on medical ($30.00 Budget):"<<endl;
    cin>>bdgt.medical; 
    cout<<"Enter the amount spent on insurance ($100.00 Budget):"<<endl;
    cin>>bdgt.insurnc;
    cout<<"Enter the amount spent on entertainment ($15.00 Budget):"<<endl;
    cin>>bdgt.entertn;
    cout<<"Enter the amount spent on clothes ($75.00 Budget):"<<endl;
    cin>>bdgt.clothes;
    cout<<"Enter the amount spent on miscellaneous ($50.00 Budget):"<<endl;
    cin>>bdgt.misc;
    
    return bdgt;
}


Budget getBdgt(Budget bdgt){
    bdgt.housing=500.00f;  //Housing
    bdgt.util=150.00f;     //Utilities
    bdgt.housHld=65.00f; //Household expenses
    bdgt.transpt=50.00f;  //Transportation 
    bdgt.food=250.00f;     //Food
    bdgt.medical=30.00f; //Medical
    bdgt.insurnc=100.00f;   //Insurance
    bdgt.entertn=150.00f;   //Entertainment
    bdgt.clothes=75.00f;   //Clothes
    bdgt.misc=50.00f;     //Miscellaneous
    
    return bdgt;
}


void chkBdgt(Budget bSpent, Budget bAllow){
    cout<<endl;
    cout<<"---Here are the budget results for the month---"<<endl;
    cout<<"Amount spent on housing: $"<<bSpent.housing<<endl;
    cout<<"Amount allowed on housing: $"<<bAllow.housing<<endl;
    cout<<"Budget result: $"<<bAllow.housing - bSpent.housing<<endl;
    cout<<endl;
    cout<<"Amount spent on utilities: $"<<bSpent.util<<endl;
    cout<<"Amount allowed on utilities: $"<<bAllow.util<<endl;
   cout<<"Budget result: $"<<bAllow.util - bSpent.util<<endl;
    cout<<endl;
    cout<<"Amount spent on household expenses: $"<<bSpent.housHld<<endl;
    cout<<"Amount allowed on household expenses: $"<<bAllow.housHld<<endl;
    cout<<"Budget result: $"<<bAllow.housHld - bSpent.housHld<<endl;;
    cout<<endl;
    cout<<"Amount spent on transportation: $"<<bSpent.transpt<<endl;
    cout<<"Amount allowed on transportation: $"<<bAllow.transpt<<endl;
    cout<<"Budget result: $"<<bAllow.transpt - bSpent.transpt<<endl;
    cout<<endl;
    cout<<"Amount spent on food: $"<<bSpent.food<<endl;
    cout<<"Amount allowed on food: $"<<bAllow.food<<endl;
    cout<<"Budget result: $"<<bAllow.food - bSpent.food<<endl;
    cout<<endl;
    cout<<"Amount spent on medical: $"<<bSpent.medical<<endl;
    cout<<"Amount allowed on medical: $"<<bAllow.medical<<endl;
    cout<<"Budget result: $"<<bAllow.medical - bSpent.medical<<endl;
    cout<<endl;
    cout<<"Amount spent on insurance: $"<<bSpent.insurnc<<endl;
    cout<<"Amount allowed on insurance: $"<<bAllow.insurnc<<endl;
    cout<<"Budget result: $"<<bAllow.insurnc - bSpent.insurnc<<endl;
    cout<<endl;
    cout<<"Amount spent on entertainment: $"<<bSpent.entertn<<endl;
    cout<<"Amount allowed on entertainment: $"<<bAllow.entertn<<endl;
    cout<<"Budget result: $"<<bAllow.entertn - bSpent.entertn<<endl;
    cout<<endl;
    cout<<"Amount spent on clothes: $"<<bSpent.clothes<<endl;
    cout<<"Amount allowed on clothes: $"<<bAllow.clothes<<endl;
    cout<<"Budget result: $"<<bAllow.clothes - bSpent.clothes<<endl;
    cout<<endl;
    cout<<"Amount spent on miscellaneous: $"<<bSpent.misc<<endl;
    cout<<"Amount allowed on miscellaneous: $"<<bAllow.misc<<endl;
    cout<<"Budget result: $"<<bAllow.misc - bSpent.misc<<endl;
}
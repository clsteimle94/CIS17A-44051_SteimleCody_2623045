/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 29, 2017, 7:25 PM
 * Purpose:  A menu for Assignment 3
 */

//System Libraries
#include <iostream>  //Input and Output
using namespace std;

//User Libraries Here
#include "movie.h"    //Used for 11.1-2
#include "account.h"  //Used for 11.7-8
#include "bureau.h"   //Used for 11.9-10
#include "budget.h"   //Used for 11.11

//Global Constants

//Function Prototypes Here
//For the Menu
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
//For 11.1-2
Movie getMvie(Movie);  //Fills the information for the movies
void pntMv(Movie);     //Prints out the movie information
void prntMv(Movie);    //Prints out the movie information
Movie getRev(Movie);   //Calculates the revenue made
//For 11.7-8
void edtCust(Account *,const int);  //Add or Modify Information
void shwCust(Account *,const int);  //Prints out the information of the customer
void prntAll(Account *,const int);  //Prints everyone
void fndCust(Account *,const int);  //Searches the structure / array
//For 11.9-10
void edtSpkr(Bureau *,const int);  //Add or Modify Information
void prntSpk(Bureau *,const int);  //Prints out the information of the speaker
void prntAll(Bureau *,const int);   //Prints everyone
void srchSpk(Bureau *,const int);   //Searches the structure / array
//For 11.11
Budget mSpent(Budget);     //Money Spent
Budget getBdgt(Budget);    //Stores the budget amounts
void chkBdgt(Budget, Budget); //Calculate the budget

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int menuItm; //Choice for menu
    
    //Loop until users exits
    do{
        //Prompt for problem for user input
        cout<<"1.  Type 1  for: Gaddis 11.1 - Movie Data"<<endl;
        cout<<"2.  Type 2  for: Gaddis 11.2 - Movie Profit"<<endl;
        cout<<"3.  Type 3  for: Gaddis 11.7 - Customer Accounts"<<endl;
        cout<<"4.  Type 4  for: Gaddis 11.8 - Search Function for Customer Accounts Program"<<endl;
        cout<<"5.  Type 5  for: Gaddis 11.9 - Speakers’ Bureau"<<endl;
        cout<<"6.  Type 6  for: Gaddis 11.10 - Search Function for the Speakers’ Bureau Program"<<endl;
        cout<<"7.  Type 7  for: Gaddis 11.11 - Monthly Budget"<<endl;
        cout<<"8.  Type 8  for: problem 8"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:problem1();break;
            case 2:problem2();break;
            case 3:problem3();break;
            case 4:problem4();break;
            case 5:problem5();break;
            case 6:problem6();break;
            case 7:problem7();break;
            case 8:problem8();
        } //End the Switch/Case
    }while(menuItm>0&&menuItm<=8); //Ends the Do-While Loop

    //Exit Program
    return 0;
}

//**************************** Gaddis 11.1 *************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem1(){
    cout<<endl;
    cout<<"Inside Gaddis 11.1 - Movie Data"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare Variables
    Movie info;   //Structure of the movie
    
    //Initialize
    cout<<"This program takes a structure for a movie "
            "and passes it in functions."<<endl;
    
    //Get movie information
    info=getMvie(info);
    
    //Print out the movie
    pntMv(info);
    
    cout<<endl;
}

//**************************** Gaddis 11.2 *************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem2(){
    cout<<endl;
    cout<<"Inside Gaddis 11.2 - Movie Profit"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare Variables
    Movie info;   //Structure for movie information
    
    //Initialize
    cout<<"This program takes program 11.1 and adds in "
            "profit calculations."<<endl;
    
    //Fill in the movie information 
    info=getMvie(info);
    
    //Calculate the revenue
    info=getRev(info);
            
    //Print
    prntMv(info);        
    
    cout<<endl;
}

//**************************** Gaddis 11.7 *************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem3(){
    cout<<endl;
    cout<<"Inside Gaddis 11.7 - Customer Accounts"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    const int N_ACNTS=10;          //Amount of people in the Account
    Account accInfo[N_ACNTS]={ };   //Structure array of the speaker
    int menuItm;                  //Menu item
    
    //Initialize
    cout<<"This program allows the user to add information to a structure array"
            " and edit or display any element."<<endl;
    cout<<"The customer slots are blank and to be filled in by the user."<<endl;
    
    //Loop until users exits
    do{ 
        //Prompt for problem for user input
        cout<<"0.  Type 0  for: Exit program"<<endl;
        cout<<"1.  Type 1  for: Fill out a customer's information"<<endl;
        cout<<"2.  Type 2  for: Print out a customer's information"<<endl;
        cout<<"3.  Type 3  for: Print everyone's information"<<endl;
        cin>>menuItm;

        //Go to the Function
        switch(menuItm){
            case 1:edtCust(accInfo,N_ACNTS);break;
            case 2:shwCust(accInfo,N_ACNTS);break;
            case 3:prntAll(accInfo,N_ACNTS);
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=3);//Ends the Do-While
    
    cout<<endl;
}

//**************************** Gaddis 11.8 *************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem4(){
    cout<<endl;
    cout<<"Inside Gaddis 11.8 - Search Function for Customer Accounts Program"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    const int N_ACNTS=10;          //Amount of people in the Account
    Account accInfo[N_ACNTS]={ };   //Structure array of the speaker
    int menuItm;                  //Menu item
    
    //Initialize
    cout<<"This program takes program 11.7 and adds a search by name."<<endl;
    
    //Loop until users exits
    do{ 
        //Prompt for problem for user input
        cout<<"0.  Type 0  for: Exit program"<<endl;
        cout<<"1.  Type 1  for: Fill out a customer's information"<<endl;
        cout<<"2.  Type 2  for: Print out a customer's information"<<endl;
        cout<<"3.  Type 3  for: Print everyone's information"<<endl;
        cout<<"4.  Type 4  for: Search for a customer's information"<<endl;
        cin>>menuItm;

        //Go to the Function
        switch(menuItm){
            case 1:edtCust(accInfo,N_ACNTS);break;
            case 2:shwCust(accInfo,N_ACNTS);break;
            case 3:prntAll(accInfo,N_ACNTS);break;
            case 4:fndCust(accInfo,N_ACNTS);
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=4);//Ends the Do-While Loop
    
    cout<<endl;
}

//**************************** Gaddis 11.9 *************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    cout<<endl;
    cout<<"Inside Gaddis 11.9 - Speakers’ Bureau"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    const int N_SPKRS=10;          //Amount of people in the Bureau
    Bureau speakrs[N_SPKRS]={ };   //Structure array of the speaker
    int spkMenu;                  //Menu item
       
    //Initialize
    cout<<"This program allows the user to add information to a structure array"
            " and edit or display any element."<<endl;
    cout<<"The speaker slots are blank and to be filled in by the user."<<endl;
    
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    
    //Loop until users exits
    do{ 
        //Prompt for problem for user input
        cout<<"0.  Type 0  for: Exit program"<<endl;
        cout<<"1.  Type 1  for: Fill out speaker information"<<endl;
        cout<<"2.  Type 2  for: Print out one speaker's informtaion"<<endl;
        cout<<"3.  Type 3  for: Prints everyone's information"<<endl;
        cin>>spkMenu;

        //Go to the Function
        switch(spkMenu){
            case 1:edtSpkr(speakrs,N_SPKRS);break;
            case 2:prntSpk(speakrs,N_SPKRS);break;
            case 3:prntAll(speakrs,N_SPKRS);
        }
    }while(spkMenu>0&&spkMenu<=3);//Ends the Do-While Loop
    
    cout<<endl;
}

//**************************** Gaddis 11.10 ************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem6(){
    cout<<endl;
    cout<<"Inside Gaddis 11.10 - Search Function for the Speakers’ Bureau Program"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    const int N_SPKRS=10;          //Amount of people in the Bureau
    Bureau speakrs[N_SPKRS]={ };   //Structure array of the speaker
    int spkMenu;                  //Menu item

    //Initialize
    cout<<"This program takes program 11.9 and adds a search by "
            "name or topic."<<endl;
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    
    //Loop until users exits
    do{ 
        //Prompt for problem for user input
        cout<<"0.  Type 0  for: Exit program"<<endl;
        cout<<"1.  Type 1  for: Fill out speaker information"<<endl;
        cout<<"2.  Type 2  for: Print out one speaker's informtaion"<<endl;
        cout<<"3.  Type 3  for: Prints everyone's information"<<endl;
        cout<<"4.  Type 4  for: Search"<<endl;
        cin>>spkMenu;

        //Go to the Function
        switch(spkMenu){
            case 1:edtSpkr(speakrs,N_SPKRS);break;
            case 2:prntSpk(speakrs,N_SPKRS);break;
            case 3:prntAll(speakrs,N_SPKRS);break;
            case 4:srchSpk(speakrs,N_SPKRS);
        }//End the Switch/Case
    }while(spkMenu>0&&spkMenu<=4);//Ends the Do-While Loop
    
    cout<<endl;
}

//**************************** Gaddis 11.11 ************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem7(){
    cout<<endl;
    cout<<"Inside Gaddis 11.11 - Monthly Budget"<<endl;
    cout<<"*********************************************"<<endl;
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
    
    cout<<endl;
}

//*************************   Problem 8 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem8(){
    cout<<endl;
    cout<<"Inside Problem 8"<<endl;
    cout<<"*********************************************"<<endl;
   
    cout<<endl;
}


//------------------------------Used in 11.1-2----------------------------------
Movie getMvie(Movie mv){
    mv.title="Titanic";
    mv.directr="James Cameron";
    mv.year=1997;
    mv.length=195;  //In minutes   
    mv.cost=0.2f; //in Billions 
    mv.rev=1.84f; //in Billions 
    return mv;
}

Movie getRev(Movie mv){
    mv.profit = mv.rev - mv.cost;    
    return mv;
}

void pntMv(Movie mv){
    cout<<"Title: "<<mv.title<<endl;
    cout<<"Directed by: "<<mv.directr<<endl;
    cout<<"Year Released: "<<mv.year<<endl;
    cout<<"Length: "<<mv.length<<" Minutes"<<endl;
}

void prntMv(Movie mv){
    cout<<"Title: "<<mv.title<<endl;
    cout<<"Directed by: "<<mv.directr<<endl;
    cout<<"Year Released: "<<mv.year<<endl;
    cout<<"Length: "<<mv.length<<" Minutes"<<endl;
    cout<<"The movie netted: $"<<mv.profit<<" Profit"<<endl;
}

//------------------------------Used in 11.7-8----------------------------------
void edtCust(Account *a, const int SIZE){
    //Declare Variables
    unsigned int indx;         //User picks the speaker slot
    
    //Select a costumer
    cout<<"Which customer # would you like to edit? (1-10, 0 returns to menu)"<<endl;
    do{
        cin>>indx;
    }while(indx<0||indx>10);
    
    if(indx>0){     //Returns to menu if 0
        //Clear cin
        cin.ignore();

        //Fill in information
        cout<<"Name for costumer #"<<indx<<":"<<endl;
        getline(cin, a[indx-1].name);
        cout<<"Address for costumer #"<<indx<<
                " (Street Address, City, State, Zip code):"<<endl;
        getline(cin, a[indx-1].address);
        cout<<"Phone number for costumer #"<<indx<<":"<<endl;
        getline(cin, a[indx-1].phonNum);
        cout<<"Account balance for costumer #"<<indx<<":"<<endl;
        do{
            cin>>a[indx-1].acntBal;
        }while(a[indx-1].acntBal<0);  //Input Validation
        cout<<"Last payment on: "<<a[indx-1].lastPay<<endl;
        getline(cin, a[indx-1].lastPay);
        
        //Clear '/n'
        cin.ignore();


        //Confirmation
        cout<<"Stored information for costumer #"<<indx<<"!"<<endl;
        cout<<endl;
    }    
}

void prntAll(Account *a,const int SIZE){
    cout<<endl;
    cout<<"Costumer Amount = "<<SIZE<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"---Customer #"<<i<<"---"<<endl;
        cout<<"Name: "<<a[i].name<<endl;
        cout<<"Address: "<<a[i].address<<endl;
        cout<<"Phone Number: "<<a[i].phonNum<<endl;
        cout<<"Account Balance: "<<"$"<<a[i].acntBal<<endl;
        cout<<"Last payment on: "<<a[i].lastPay<<endl;
        cout<<endl;
    }
    cout<<endl;
}

void shwCust(Account *a,const int SIZE){
    //Declare Variables
    unsigned int indx;         //User picks the speaker slot
    
    //Select a costumer
    cout<<"Which customer # would you like to view? (1-10)"<<endl;
    do{
        cin>>indx;
    }while(indx<1||indx>10);
    
    //Clear cin
    cin.ignore();
    
    //Print the Speaker's Info
    cout<<endl;
    cout<<"---Customer #"<<indx<<"---"<<endl;
    cout<<"Name: "<<a[indx-1].name<<endl;
    cout<<"Address: "<<a[indx-1].address<<endl;
    cout<<"Phone Number: "<<a[indx-1].phonNum<<endl;
    cout<<"Account Balance: "<<"$"<<a[indx-1].acntBal<<endl;
    cout<<"Last payment on: "<<a[indx-1].lastPay<<endl;
    cout<<endl;
}

void fndCust(Account *a,const int SIZE){
    //Declare Variables
    string find;         //User searches for the topic / name
    
    //Input
    cin.ignore(); //Clear cin
    cout<<"Please enter the name of the customer you would like to find:"<<endl;
    getline(cin, find);
    
    //Search
    for(int i=0;i<SIZE;i++){
        if(find==a[i].name){
            cout<<"Found a matching name!"<<endl;
            cout<<"---Customer #"<<i<<"---"<<endl;
            cout<<"Name: "<<a[i].name<<endl;
            cout<<"Address: "<<a[i].address<<endl;
            cout<<"Phone Number: "<<a[i].phonNum<<endl;
            cout<<"Account Balance: "<<"$"<<a[i].acntBal<<endl;
            cout<<"Last payment on: "<<a[i].lastPay<<endl;
            return;
        }    
    }
    cout<<"No matches found."<<endl;
}    

//------------------------------Used in 11.9-10---------------------------------
void edtSpkr(Bureau *a, const int SIZE){
    //Declare Variables
    unsigned int indx;         //User picks the speaker slot
    
    //Input or initialize values Here
    //Which Speaker
    cout<<"Which Speaker # would you like to edit? (1-10, 0 returns to menu)"<<endl;
    do{
        cin>>indx;
    }while(indx<0||indx>10);
    
    if(indx>0){     //Returns to menu if 0
        //Clear cin
        cin.ignore();

        //Fill in information
        cout<<"Name for speaker #"<<indx<<":"<<endl;
        getline(cin, a[indx-1].name);
        cout<<"Phone number for speaker #"<<indx<<":"<<endl;
        getline(cin, a[indx-1].phonNum);
        cout<<"Topic for speaker #"<<indx<<":"<<endl;
        getline(cin, a[indx-1].topic);
        cout<<"Fee required for speaker #"<<indx<<":"<<endl;
        do{
            cin>>a[indx-1].fee;
        }while(a[indx-1].fee<0);  //Input Validation
        cin.ignore();             //Clear '/n'

        //Confirmation
        cout<<"Stored information for speaker #"<<indx<<"!"<<endl;
        cout<<endl;
    }    
}

void prntAll(Bureau *a,const int SIZE){
    cout<<endl;
    cout<<"Speaker Amount = "<<SIZE<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"---Speaker #"<<i<<"---"<<endl;
        cout<<"Name: "<<a[i].name<<endl;
        cout<<"Phone Number: "<<a[i].phonNum<<endl;
        cout<<"Topic: "<<a[i].topic<<endl;
        cout<<"Fee Required: "<<"$"<<a[i].fee<<endl;
        cout<<endl;
    }
    cout<<endl;
}

void prntSpk(Bureau *a,const int SIZE){
    //Declare Variables
    unsigned int indx;         //User picks the speaker slot

    //Select the speaker
    cout<<"Which Speaker # would you like to view? (1-10)"<<endl;
    do{
        cin>>indx;
    }while(indx<1||indx>10);
    
    //Clear cin
    cin.ignore();
    
    //Print the Speaker's Info
    cout<<endl;
    cout<<"---Speaker #"<<indx<<"---"<<endl;
    cout<<"Name: "<<a[indx-1].name<<endl;
    cout<<"Phone Number: "<<a[indx-1].phonNum<<endl;
    cout<<"Topic: "<<a[indx-1].topic<<endl;
    cout<<"Fee Required: "<<"$"<<a[indx-1].fee<<endl;
    cout<<endl;
}
    
void srchSpk(Bureau *a,const int SIZE){
    //Declare Variables
    string find;         //User searches for the topic / name
    
    //Input
    cin.ignore(); //Clear cin
    cout<<"Enter the speaker's topic or name you would like to find"<<endl;
    getline(cin, find);
    
    //Search
    for(int i=0;i<SIZE;i++){
        if(find==a[i].name){
            cout<<"Found a matching name!"<<endl;
            cout<<"Name: "<<a[i].name<<endl;
            cout<<"Topic: "<<a[i].topic<<endl;
            return;
        }    
        if(find==a[i].topic){
            cout<<"Found a matching topic!"<<endl;   
            cout<<"Name: "<<a[i].name<<endl;
            cout<<"Topic: "<<a[i].topic<<endl;
            return;
        }
    }
    cout<<"No matches found."<<endl;
}    


//------------------------------Used in 11.11-----------------------------------
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
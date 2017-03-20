/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 22, 2017, 11:45 AM
 * Purpose:  Gaddis 11.8 - Search Function for Customer Accounts Program
 */

//System Libraries Here
#include <iostream> //Input/Output
using namespace std;

//User Libraries Here
#include "account.h"

//Global Constants

//Function Prototypes Here
void edtCust(Account *,const int);  //Add or Modify Information
void shwCust(Account *,const int);  //Prints out the information of the customer
void prntAll(Account *,const int);  //Prints everyone
void fndCust(Account *,const int);  //Searches the structure / array


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int N_ACNTS=10;          //Amount of people in the Account
    Account accInfo[N_ACNTS]={ };   //Structure array of the speaker
    int menuItm;                  //Menu item
    
    //Initialize
    cout<<"This program takes program 11.7 and adds a search by name."<<endl;
    
    //Loop until users exits
    do{ 
        //Prompt for problem for user input
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
    
    //Exit Program
    return 0;
} 
    

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
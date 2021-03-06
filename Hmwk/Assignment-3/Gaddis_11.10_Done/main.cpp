/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 22, 2017, 11:45 AM
 * Purpose:  Gaddis 11.10 - Search Function for the Speakers’ Bureau Program
 */

//System Libraries Here
#include <iostream> //Input/Output
using namespace std;

//User Libraries Here
#include "bureau.h"

//Global Constants

//Function Prototypes Here
void edtSpkr(Bureau *,const int);  //Add or Modify Information
void prntSpk(Bureau *,const int);  //Prints out the information of the speaker
void prntAll(Bureau *,const int);   //Prints everyone
void srchSpk(Bureau *,const int);   //Searches the structure / array

//Program Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit Program
    return 0;
} 
    

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
/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on February 22, 2017, 1:30 PM
 * Purpose:  Gaddis Chapter 4 Programming Challenge 10: Days in a Month
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
    unsigned short year,month;   //Range 0 to 65,535
    
    //Input or initialize values Here
    cout<<"This program will find the amount of days in a month,"
            " given the year."<<endl;  
    do{ //Input validation
        cout<<"Type in the year (1600-2100):"<<endl;
        cin>>year;    //User types in the year
    }while(year<1600||year>2100); //Input validation 
    do{ //Input validation  
        cout<<"Type in the month (1-12)"<<endl;
        cin>>month;   //User types in the month
    }while(month<1||month>12); //Input validation

    //Process/Calculations Here -> Map inputs to outputs and display
    switch(month){
        case 1: cout<<"There are 31 days in January, "<<endl;break;
        case 2: {
            if(year%4==0&&(year%400==0||year%100!=0)){ //Calculate for leap year
                cout<<"There are 29 days in February, "<<year<<endl; //leap year
            }else{
                cout<<"There are 28 days in February, "<<year<<endl; //normal
            } 
            break;
        }
        case 3: cout<<"There are 31 days in March, "<<year<<endl;break;
        case 4: cout<<"There are 30 days in April, "<<year<<endl;break;
        case 5: cout<<"There are 31 days in May, "<<year<<endl;break;
        case 6: cout<<"There are 30 days in June, "<<year<<endl;break;
        case 7: cout<<"There are 31 days in July, "<<year<<endl;break;
        case 8: cout<<"There are 31 days in August, "<<year<<endl;break;
        case 9: cout<<"There are 30 days in September, "<<year<<endl;break;
        case 10: cout<<"There are 31 days in October, "<<year<<endl;break;
        case 11: cout<<"There are 30 days in November, "<<year<<endl;break;
        case 12: cout<<"There are 31 days in December, "<<year<<endl;break;        
    }
    //Exit
    return 0;
}

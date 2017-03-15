/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 5, 2017, 7:25 PM
 * Purpose:  A menu for Assignment 1
 */

//System Libraries Here
#include <iostream>  //Imput and Output
#include <vector>    //String vector
#include <algorithm> //Sort function for vectors
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
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
//6.7
float celsius(int);
//8.7
int binSrch(vector<string>,int,string);
void prntVec(vector<string>, int);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int menuItm; //Choice for menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for: Gaddis_8thEd_Chap2_Prob10_Miles per Gallon"<<endl;
        cout<<"2.  Type 2  for: Gaddis_8thEd_Chap3_Prob12_Celsius to Fahrenheit"<<endl;
        cout<<"3.  Type 3  for: Gaddis_8thEd_Chap3_Prob13_Currency"<<endl;
        cout<<"4.  Type 4  for: Gaddis_8thEd_Chap4_Prob4_Areas of Rectangles"<<endl;
        cout<<"5.  Type 5  for: Gaddis_8thEd_Chap4_Prob10_Days in a Month"<<endl;
        cout<<"6.  Type 6  for: Gaddis_8thEd_Chap5_Prob3_Ocean Levels"<<endl;
        cout<<"7.  Type 7  for: Gaddis_8thEd_Chap5_Prob11_Population"<<endl;
        cout<<"8.  Type 8  for: Gaddis_8thEd_Chap6_Prob7_Celsius Temperature Table"<<endl;
        cout<<"9.  Type 9  for: Gaddis_8thEd_Chap7_Prob6_Rain or Shine (unfinished)"<<endl;
        cout<<"10. Type 10 for: Gaddis_8thEd_Chap8_Prob7_Binary String Search"<<endl;
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
            case 8:problem8();break;
            case 9:problem9();break;
            case 10:problem10();
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

//*************************   Problem 1 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem1(){
    cout<<endl;
    cout<<"Inside Problem 2.10 - Miles per Gallon"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    int gas=15;    //Max tank in gallons
    int miles=375; //Distance traveled on max tank
    float mpg;     //Miles per gallon
    
    //Initialize
    cout<<"This program will calculate the MPG of a car."<<endl;
    
    //Process
    mpg=miles/gas;  //MPG conversion
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); 
    
    //Output
    cout<<"A car with a "<<gas<<" gallon tank can travel "<<miles<<" on a "
            "full tank."<<endl;
    cout<<"Therfore the car will get "<<mpg<<" miles per gallon."<<endl;
    cout<<endl;
}

//*************************   Problem 2 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem2(){
    cout<<endl;
    cout<<"Inside Problem 3.12 - Celsius to Fahrenheit"<<endl;
    cout<<"*********************************************"<<endl;
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
    cout<<endl;
}

//*************************   Problem 3 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem3(){
    cout<<endl;
    cout<<"Inside Problem 3.13 - Currency"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    float dollar,yen,euro;   //USD Amount,Yen Amount,Euro Amount
    
    //Input or initialize values Here
    cout<<"This Program will convert USD Currency to Euros and Yen."<<endl;
    cout<<"Please enter the amount of USD."<<endl;
    cin>>dollar;  //User enters dollar amount
    
    //Process/Calculations Here
    euro=dollar*0.95f; //1 Dollar to 0.95 Exchange rate for Euro of 2/22/17
    yen=dollar*113.03f; //1 Dollar to 113.03 Exchange rate for Yen of 2/22/17
    
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    
    //Output Located Here
    cout<<"USD:   $"<<dollar<<endl;
    cout<<"Euros: €"<<euro<<" (at 1 Dollar to 0.95 Euro exchange rate.)"<<endl;
    cout<<"Yen:   ¥"<<yen<<" (at 1 Dollar to 113.03 Yen exchange rate.)"<<endl;
    cout<<endl;
}

//*************************   Problem 4 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem4(){
    cout<<endl;
    cout<<"Inside Problem 4.4 - Areas of Rectangles"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    int width1, length1, width2, length2; //Length and Width for 2 rectangles
    int area1, area2;     //The area for each of the rectangles

    //Input or initialize values Here
    cout<<"This program will calculate which of two rectangles has a greater "
            "area."<<endl;
    cout<<"Please enter the length of the first rectangle: ";
    cin>>length1;
    cout<<"Please enter the width of the first rectangle: ";
    cin>>width1;
    cout<<"Please enter the length of the second rectangle: ";
    cin>>length2;
    cout<<"Please enter the width of the second rectangle: ";
    cin>>width2;
    
    //Process
    area1=length1*width1;
    area2=length2*width2;
    
    //Output
    if(area1>area2){
        cout<<"The first rectangle has a larger area of "<<area1<<" while the "
                "second rectangle has a shorter area of "<<area2<<"."<<endl;
    }
    else{
        cout<<"The second rectangle has a larger area of "<<area2<<" while the "
                "first rectangle has a shorter area of "<<area1<<"."<<endl;
    }
    cout<<endl;
}

//*************************   Problem 5 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    cout<<endl;
    cout<<"Inside Problem 4.10 - Days in a Month"<<endl;
    cout<<"*********************************************"<<endl;
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
    cout<<endl;
}

//*************************   Problem 6 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem6(){
    cout<<endl;
    cout<<"Inside Problem 5.3 - Ocean Levels"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    float ocnRse=1.5f; //Millimeters per year the ocean level rises
    float ocnLvl=0.0f;   //Tracks the total rising levels yearly
    int years=25;     //The number of years the ocean level will rise
    
    //Input or initialize values Here
    cout<<"This program will calculate the rising ocean level per year."<<endl;
    
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
    cout<<endl;
}

//*************************   Problem 7 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem7(){
    cout<<endl;
    cout<<"Inside Problem 5.11 - Population"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    float popltn; //Base population needs to be 2 or more
    float growth;  //Growth Percentage, has to be positive
    int numDays; //Number of days to multiply,  needs to be 1 or more
    
    //Input or initialize values Here
    cout<<"This program will calculate population growth."<<endl;
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
    
    //Displays no decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(0);    
    
    //Calculate and output the population for each day
    for(int count=1;count<numDays;count++){
        cout<<"Day: "<<count<<" Population: "<<popltn<<endl;
        popltn=(popltn*growth)+popltn;
    }
    
    //Output
    //The final population
    cout<<"The final population: "<<popltn<<endl;
    cout<<endl;
}

//*************************   Problem 8 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem8(){
    cout<<endl;
    cout<<"Inside Problem 6.7 - Celsius Temperature Table"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    int fahren=0; //Fahrenheit (Begin on 0F and end on 20F)
    float celsi;  //Celsius

    //Input or initialize values Here
    cout<<"This program outputs a conversion table for Celsius Fahrenheit."<<endl;
    //Process/Output
    //Displays only two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);    
    
    //Draw the table
    cout<<"F   "<<"   C"<<endl;
    do{
        cout<<fahren<<"F  =  "<<celsius(fahren)<<"C"<<endl;
        fahren++;
    }while(fahren<21);
    cout<<endl;
}

//*************************   Problem 9 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem9(){
    cout<<"Inside Problem 7.6 - Rain or Shine (unfinished)"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare all Variables Here
    //Process
    //Output
}

//*************************   Problem 10 ***************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem10(){
    cout<<"Inside Problem 8.7 - Binary String Search"<<endl;
    cout<<"*********************************************"<<endl;
    //Declare Variables
    string person;  //The target name
    vector<string> name={"Collins, Bill", "Smith, Bart", "Allen, Jim",
                         "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                         "Taylor, Terri", "Johnson, Jill",
                         "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                         "James, Jean", "Weaver, Jim", "Pore, Bob",
                         "Rutherford, Greg", "Javens, Renee",
                         "Harrison, Rose", "Setzer, Cathy",
                         "Pike, Gordon", "Holland, Beth" };  //20 in size [0-19]

    //Initialize
    cout<<"This program will search a string array for a name."<<endl;

    //Print the unsorted array
    cout<<"The names in the array:"<<endl;
    prntVec(name,20);

    //Input
    cout<<"Please enter the name of the person you are trying to search for:"<<endl;
    getline(cin,person);  //User types the desired name

    //Search the array
    binSrch(name,20,person);
}



//Used for problem 6.7
float celsius(int fahr){
    float cels;
    cels=5.0f/9.0f*(fahr-32);  //Conversion from F -> C
    return cels;
}

//Used for problem 8.7
int binSrch(vector<string> ary,int n,string data){
    //Declare variables
    bool found=false;   //Flag
    int index=0;        //Index location of array
    char input;         //User input
    
    //Sort the array
    cout<<"sorting..."<<endl;
    sort(ary.begin(), ary.end());  //Sort function for vectors
    cout<<"Would you like to view the sorted array? (y/n)"<<endl;
    cin>>input;
    if(input=='y') prntVec(ary,20);           
    
    //Search the array     
    cout<<"searching..."<<endl;
    for(int i=0;i<=n;i++){
        if(ary[i]==data){     //Test if name is found at index
            found=true;
            index=i;
            break;
        }
    }
    if(found){
        cout<<"Found in position "<<index+1<<" of the sorted array!"<<endl;  
        cout<<ary[index]<<endl;
    }    
    else cout<<"Not found."<<endl;  
}

//Used for problem 8.7
void prntVec(vector<string> ary, int n){
    //i = index, n = size utilized
    for(int i=1;i<=n;i++){
        cout<<ary[i-1]<<endl;
    }
    cout<<endl;
}
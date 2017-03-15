/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 14, 2017, 11:25 PM
 * Purpose:  A menu for Assignment 2
 */

//System Libraries Here
#include <iostream>  //Imput and Output
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
#include <string>     //getline
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
//9.1
int *makeAry(int);         //Create and fills a dynamic array
void prntArr(int,int *);   //Prints the arrays
//9.2-3
void getScr(int,int *);    //Reads in scores from a file and creates an array
int &srtScr(int,int *);    //Makes a copy and sorts
int drpScr(int,int *);     //Lowest score will be dropped
int avgScr(int,int *);     //Finds the average score
void prntAry(int ,int *);  //Prints the array
//9.4
void getScr(int,int *,string *);            //Reads in scores from a file and creates an array
int &srtScr(int,int *,string *,string *);   //Makes a copy and sorts
int drpScr(int,int *,string *);             //Lowest score will be dropped
void prntAry(int ,int *,string *);          //Prints the array
//9.5
int swpCalc(int *,int *); //Swap Calculation, ten fold then addition
//9.6-7
void arySort(int **, int);
void arySrt(int **, int);
void shwAry(int *, int);
void ptrAry(int **,int);
void filAry(int *, int);
//MeanMedianMode
int fillAry(int *,int);
int copyAry(int *,int *,int);
void pntAry(int *,int);          //Print Array  
void frqPrnt(int *,int *,int);   //For frequency
int modeSrt(int *,int *,int);  //For narrowing results
void srtAry(int *,int);      //Mark Sort style
void avgAry(int *,int );   //Finds the average of the int array
void medAry(int *,int );   //Finds the median of the int array
void modeAry(int *,int );  //Finds the mode of the int array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int menuItm; //Choice for menu
    
    //Loop until users exits
    do{
        //Prompt for problem for user input
        cout<<"1.  Type 1  for: Gaddis_8thEd_Chap9_Prob1_Array Allocator"<<endl;
        cout<<"2.  Type 2  for: Gaddis_8thEd_Chap3_Prob2_Test Scores #1"<<endl;
        cout<<"3.  Type 3  for: Gaddis_8thEd_Chap3_Prob3_Drop Lowest Score"<<endl;
        cout<<"4.  Type 4  for: Gaddis_8thEd_Chap4_Prob4_Test Scores #2"<<endl;
        cout<<"5.  Type 5  for: Gaddis_8thEd_Chap4_Prob5_Pointer Rewrite"<<endl;
        cout<<"6.  Type 6  for: Gaddis_8thEd_Chap5_Prob6_Case Study Mod #1"<<endl;
        cout<<"7.  Type 7  for: Gaddis_8thEd_Chap5_Prob7_Case Study Mod #2"<<endl;
        cout<<"8.  Type 8  for: Mean, Median, Mode"<<endl;
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
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=8);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

//*************************   Problem 1 ****************************************
//Purpose:  To create an array from a function dynamically
//Inputs:   Size of the array (int)
//Output:   The integer array
//******************************************************************************
void problem1(){
    cout<<endl;
    cout<<"Inside Problem 9.1 - Array Allocator"<<endl;
    cout<<"*********************************************"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int use;     //Size used of the dynamic array
    int *aryPtr;  //Array pointer     

    //Initialize
    cout<<"This program will dynamically create an array from a function."<<endl;
    
    //Set the array size
    cout<<"Please input how big the array will be (1-100):"<<endl;
    do{
        cin>>use;
    }while(use<1||use>100); //Input validation
    
    //Fill array and set a pointer
    aryPtr=makeAry(use);
    
    //Print array
    cout<<"The Dynamic Array: "<<endl;
    prntArr(use,aryPtr);
      
    //Clean-up Memory
    delete []aryPtr;
    cout<<endl;
}

//*************************   Problem 2 ****************************************
//Purpose:  Find the average of random test scores
//Inputs:   The amount of test scores (int)
//Output:   Sorted and unsorted test scores with the average score
//******************************************************************************
void problem2(){
    cout<<endl;
    cout<<"Inside Problem 9.2 - Test Scores #1"<<endl;
    cout<<"*********************************************"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=40;                 //Maximum capacity for the array
    int *scores = new int[MAX];       //Declares and Places array in the heap
    int use;                          //How many scores to use
    int *scrCpy;                      //Pointer for the index array (score copy)
    
    //Initialize
    cout<<"This program takes random test scores and calculates the"
            " average."<<endl;
    cout<<endl;
    
    //Set the array size
    cout<<"Please input how many test scores there will be (1-40):"<<endl;
    do{
        cin>>use;
    }while(use<1||use>40); //Input validation

    //Store scores and names to arrays   
    getScr(use,scores);
    
    //Print the unsorted test scores
    cout<<"Here are the unsorted test scores:"<<endl;
    prntAry(use,scores);
    
    //Sort the scores
    scrCpy=&srtScr(use,scores);
    
    //Print the sorted test scores
    cout<<"Here are the sorted test scores:"<<endl;
    prntAry(use,scrCpy);

    //Find the average score
    cout<<"The average score was: "
            <<avgScr(use,scrCpy)<<"%"<<endl;
    
    //Clean-up Memory
    delete []scores;
    delete []scrCpy;
    cout<<endl;
}

//*************************   Problem 3 ****************************************
//Purpose:  Adds to problem 2 by dropping the lowest test score
//Inputs:   Number of test scores (int)
//Output:   The new averages without the lowest score
//******************************************************************************
void problem3(){
    cout<<endl;
    cout<<"Inside Problem 9.3 - Drop Lowest Score"<<endl;
    cout<<"*********************************************"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=40;                 //Maximum capacity for the array
    int *scores = new int[MAX];       //Declares and Places array in the heap
    int use;                          //How many scores to use
    int *scrCpy;                      //Pointer for the index array (score copy)
    
    //Initialize
    cout<<"This program expands on the test scores problem dropping the lowest"
            " test score from the calculations."<<endl;
    cout<<endl;
    
    //Set the array size
    cout<<"Please input how many test scores there will be (1-40):"<<endl;
    do{
        cin>>use;
    }while(use<1||use>40); //Input validation

    //Store scores and names to arrays   
    getScr(use,scores);
    
    //Print the unsorted test scores
    cout<<"Here are the unsorted test scores:"<<endl;
    prntAry(use,scores);
    
    //Sort the scores
    scrCpy=&srtScr(use,scores);
    
    //Print the sorted test scores
    cout<<"Here are the sorted test scores:"<<endl;
    prntAry(use,scrCpy);
    
    //Drop the lowest score
    use=drpScr(use,scrCpy);
    
    //Print the sorted test scores with the dropped one
    cout<<"Here are the test scores with lowest one dropped:"<<endl;
    prntAry(use,scrCpy);
    
    //Find the average score
    cout<<"The average score (after the drop) was: "
            <<avgScr(use,scrCpy)<<"%"<<endl;
     
    //Clean-up Memory
    delete []scores;
    cout<<endl;
}

//*************************   Problem 4 ****************************************
//Purpose:  Further expanding on the test scores by adding names
//Inputs:   Number of test scores (int), Names array (string)
//Output:   The sorted and unsorted arrays without the lowest test score
//******************************************************************************
void problem4(){
    cout<<endl;
    cout<<"Inside Problem 9.4 - Test Scores #2"<<endl;
    cout<<"*********************************************"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=20;                 //Maximum capacity for the array
    int *scores = new int[MAX];       //Declares and Places array in the heap
    string *names = new string[MAX];  //Declares and Places array in the heap
    string *nmeCpy = new string[MAX];  //Index copy for names
    int use;                          //How many scores to use
    int *scrCpy;                      //Pointer for the index array (score copy)
    
    //Initialize
    cout<<"This program expands on the test scores problem by adding names tied"
            " to the test scores."<<endl;
    cout<<endl;
    
    //Set the array size
    cout<<"Please input how many test scores there will be (1-20):"<<endl;
    cout<<"Also note you will be typing that many names."
            " However the test scores will be randomized."<<endl;
    do{
        cin>>use;
    }while(use<1||use>20); //Input validation

    //Store scores and names to arrays   
    getScr(use,scores,names);
    
    //Print the unsorted test scores
    cout<<"Here are the unsorted test scores:"<<endl;
    prntAry(use,scores,names);
    
    //Sort the scores
    scrCpy=&srtScr(use,scores,names,nmeCpy);
    
    //Print the sorted test scores
    cout<<"Here are the sorted test scores:"<<endl;
    prntAry(use,scrCpy,nmeCpy);
    
    //Drop the lowest score
    use=drpScr(use,scrCpy,nmeCpy);
    
    //Print the sorted test scores with the dropped one
    cout<<"Here are the test scores with lowest one dropped:"<<endl;
    prntAry(use,scrCpy,nmeCpy);
    
    //Find the average score
    cout<<"The average score (after the drop) was: "
            <<avgScr(use,scrCpy)<<"%"<<endl;
    
    
    //Clean-up Memory
    delete []scores;
    delete []names;
    delete []scrCpy;
    delete []nmeCpy;
    cout<<endl;
}

//*************************   Problem 5 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    cout<<endl;
    cout<<"Inside Problem 9.5 - Pointer Rewrite"<<endl;
    cout<<"*********************************************"<<endl;
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
    cout<<swpCalc(x,y)<<endl;
    cout<<endl;
}

//*************************   Problem 6 ****************************************
//Purpose:  To edit a book program about donations to use pointers
//Inputs:   Size of donation array (int)
//Output:   The donation array and the sorted array (low->high)
//******************************************************************************
void problem6(){
    cout<<endl;
    cout<<"Inside Problem 9.6 - Case Study Mod #1"<<endl;
    cout<<"*********************************************"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX = 25; //Max number of donations
    int *donate = new int[MAX]; //Donation Array (dynamic)
    int **aryPtr = new int*[MAX]; // An array of pointers to int.
    int amount; //Sets how much of the donation array will be used
    
    //Initialize
    cout<<"This program alters the book's donation program to use any number of"
            " donations dynamically."<<endl;
    cout<<endl;    
    
    //Set the array size
    cout<<"Please input how many donations there will be (1-25):"<<endl;
    do{
        cin>>amount;
    }while(amount<1||amount>25); //Input validation
    
    
    //Fill the donations array
    filAry(donate,amount);
    
    //Copy the Donations Array
    for (int i=0;i<MAX;i++){
        aryPtr[i] = &donate[i];
    }
    
    //Sort the copy.
    arySort(aryPtr,amount);
    
    // Display the donations using the array of pointers. This will display them in sorted order.
    cout << "The donations, sorted in ascending order are: "<<endl;
    ptrAry(aryPtr,amount);
    
    // Display the donations in their original order.
    cout << "The donations, in their original order are: "<<endl;
    shwAry(donate,amount);
    
    //Clean-up Memory
    delete []donate;
    delete []aryPtr;
    cout<<endl;
}

//*************************   Problem 7 ****************************************
//Purpose:  Alternate sorting method (high to low) for the sorted array
//Inputs:   Size of donation array (int)
//Output:   The donation array and the sorted array (high->low)
//******************************************************************************
void problem7(){
    cout<<endl;
    cout<<"Inside Problem 9.7 - Case Study Mod #2"<<endl;
    cout<<"*********************************************"<<endl;
//Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX = 25; //Max number of donations
    int *donate = new int[MAX]; //Donation Array (dynamic)
    int **aryPtr = new int*[MAX]; // An array of pointers to int.
    int amount; //Sets how much of the donation array will be used
    
    //Initialize
    cout<<"This program alters the original program to sort in "
            "descending order."<<endl;
    cout<<endl;    
    
    //Set the array size
    cout<<"Please input how many donations there will be (1-25):"<<endl;
    do{
        cin>>amount;
    }while(amount<1||amount>25); //Input validation
    
    
    //Fill the donations array
    filAry(donate,amount);
    
    //Copy the Donations Array
    for (int i=0;i<MAX;i++){
        aryPtr[i] = &donate[i];
    }
    
    //Sort the copy.
    arySrt(aryPtr,amount);
    
    // Display the donations using the array of pointers. This will display them in sorted order.
    cout << "The donations, sorted in descending order are: "<<endl;
    ptrAry(aryPtr,amount);
    
    // Display the donations in their original order.
    cout << "The donations, in their original order are: "<<endl;
    shwAry(donate,amount);
    
    //Clean-up Memory
    delete []donate;
    delete []aryPtr;       
    cout<<endl;
}

//*************************   Problem 8 ****************************************
//Purpose:  Find the Mean, Median, and Mode of an array
//Inputs:   Array Size (int)
//Output:   The Mean, Median, and Mode
//******************************************************************************
void problem8(){
    cout<<endl;
    cout<<"Inside Problem - Mean, Median, Mode"<<endl;
    cout<<"*********************************************"<<endl;
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=100;            //Maximum capacity for the array
    int *numAry = new int[MAX];  //Declares and Places array in the heap
    int *numCpy = new int[MAX];  //Copy of the original array
    int use;                  //How many scores to use
    
    //Initialize
    cout<<"This program takes an integer array and finds the mean, median, and"
            " mode of it."<<endl;
    cout<<endl;    
    
    //Set the array size
    cout<<"Please input how big array will be (1-100):"<<endl;
    do{
        cin>>use;
    }while(use<1||use>100); //Input validation
    
    //Fill Array
    fillAry(numAry,use);
    
    //Print the unsorted array
    cout<<"The unsorted array"<<endl;
    pntAry(numAry,use);
    
    //Copy the Array
    copyAry(numAry,numCpy,use);
            
    //Sort the Copy
    srtAry(numCpy,use);
            
    //Print the sorted array
    cout<<"The sorted array:"<<endl;
    pntAry(numCpy,use);
    
    //Average (Mean)
    avgAry(numCpy,use);
            
    //Median
    medAry(numCpy,use);
    
    //Mode
    modeAry(numCpy,use);
    
    //Clean-up Memory
    delete []numAry;
    delete []numCpy;
    cout<<endl;
}

//****************************USED FOR 9.1**************************************
//Fill the array function
int *makeAry(int n){
    //Declares Variables
    const int MAX=100;        //Maximum capacity for the array
    int *ary = new int[MAX];  //Declares and Places array in the heap
    //Fill Array
    for(int i=0;i<n;i++){    
        ary[i]=rand()%10;   //Sets index to a random number 0-9
    }    
    
    //Return the pointer of the array
    return ary;
}   
//Print Array
void prntArr(int n,int *a){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==9)cout<<endl;  //10 Numbers per line
    }
    cout<<endl; 
}    

//****************************USED FOR 9.2-3************************************

void getScr(int n,int *a){  
    //Create the score array
    for(int i=0;i<n;i++){
            a[i]=rand()%100;  //0-100
    }                 
}

int &srtScr(int n,int *a){   
    //Create index array
     int *indx = new int[n];  //Deleted in main
    
    //Copy scores to index
    for(int i=0;i<n;i++){
        indx[i]=a[i];
    }
     
    //Sort the index (Mark Sort)
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(indx[pos]>indx[i]){
                indx[pos]=indx[pos]^indx[i]; //Score index                          
                indx[i]=indx[pos]^indx[i];
                indx[pos]=indx[pos]^indx[i];
            }
        }
    }
     return *indx;
}

int avgScr(int n,int *a){
    //Declare Variables
    int avg; //Average of the array
    
    //Find the average
    for(int i=0;i<n;i++){
        avg=avg+a[i];
    }
    avg=avg/n;
   
    return avg;
}

void prntAry(int n,int *a){
    for(int i=0;i<n;i++){
        cout<<a[i]<<"%"<<endl;  //Prints score then name
    }
    cout<<endl; 
}   

int drpScr(int n,int *a){
    for(int i=0;i<=n;i++){  //Breaks early to account for dropped score
        a[i]=a[i+1];
    }  
    
    return n-1;
}

//*****************************USED FOR 9.4*************************************
void getScr(int n,int *a,string *b){
    //Declare Variables
    string name;  //name holder
    
    //Create the score array
    for(int i=0;i<n;i++){
            a[i]=rand()%100;  //0-100
    }                 
    
    //Clear cin (/n)
    getline(cin,name);
    
    //Fill the name array
    for(int i=0;i<n;i++){
        cout<<"Enter test taker name #"<<(i+1)<<endl;
        getline(cin,name);
        b[i]=name;
    }    
}

int &srtScr(int n,int *a,string *b,string *nIndx){
    //Declare Variables
    string temp; //For swapping names
    
    //Create name copy array
    for(int i=0;i<n;i++){
            nIndx[i]=b[i];
    }           
    
    //Create index array
     int *indx = new int[n];  //Deleted in main
    
    //Copy scores to index
    for(int i=0;i<n;i++){
        indx[i]=a[i];
    }
     
    //Sort the index (Mark Sort)
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(indx[pos]>indx[i]){
                indx[pos]=indx[pos]^indx[i]; //Score index                          
                indx[i]=indx[pos]^indx[i];
                indx[pos]=indx[pos]^indx[i];
                temp=nIndx[pos]; //Name index
                nIndx[pos]=nIndx[i];
                nIndx[i]=temp;   
            }
        }
    }
     return *indx;
}
void prntAry(int n,int *a,string *b){
    for(int i=0;i<n;i++){
        cout<<a[i]<<"% -> "<<b[i]<<endl;  //Prints score then name
    }
    cout<<endl; 
}   

int drpScr(int n,int *a,string *b){
    for(int i=0;i<=n;i++){  //Breaks early to account for dropped score
        a[i]=a[i+1];
        b[i]=b[i+1];
    }  
    
    return n-1;
}

//*****************************USED FOR 9.5*************************************
int swpCalc(int *x, int *y){
    int temp = *x;  //temp=2
    *x = *y * 10;   //3x10=30
    *y = temp * 10; //2x10=20
    return *x + *y; //30+20=50
}

//*****************************USED FOR 9.6-7***********************************
void filAry(int *a, int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%99+1; //Random number $100-$1
    }    
}


void arySort(int **a, int n){
    //Declare Variables
    int strtScn, minIndx;  //Start Scan, Minimum Index
    int *minElem;         //Minimum Element Pointer
    
    //Sort
    for(strtScn=0;strtScn<(n-1);strtScn++){
        minIndx = strtScn;
        minElem = a[strtScn];
        
        for(int i=strtScn+1;i<n;i++){
            if(*(a[i])<*minElem){  //Compare the array and pointer 
                minElem=a[i];
                minIndx=i;
            }
        }
        a[minIndx]=a[strtScn];
        a[strtScn]=minElem;
    }
}


void arySrt(int **a, int n){
    //Declare Variables
    int strtScn, minIndx;  //Start Scan, Minimum Index
    int *minElem;         //Minimum Element Pointer
    
    //Sort
    for(strtScn=0;strtScn<(n-1);strtScn++){
        minIndx = strtScn;
        minElem = a[strtScn];
        
        for(int i=strtScn+1;i<n;i++){
            if(*(a[i])>*minElem){  //Compare the array and pointer 
                minElem=a[i];
                minIndx=i;
            }
        }
        a[minIndx]=a[strtScn];
        a[strtScn]=minElem;
    }
}


void shwAry(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<"$"<<a[i]<<" ";
    }
    cout<<endl;
}


void ptrAry(int **a, int n){
    for(int i=0;i<n;i++){
        cout<<"$"<<*a[i]<<" ";
    }
    cout<<endl;
}


//********************USED FOR - Mean, Median, Mode*****************************
int fillAry(int *a,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%8+1;      //Random number 1-9
    }        
}


int copyAry(int *a,int *b,int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}


void srtAry(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(a[pos]>a[i]){
                a[pos]=a[pos]^a[i];
                a[i]=a[pos]^a[i];
                a[pos]=a[pos]^a[i];
            }
        }
    }     
}


void avgAry(int *a,int n){
    //Declare Variables
    float avg;
    //Calculate Average
    for(int i=0;i<n;i++){
        avg=avg+a[i];
    }
    avg=avg/n;
    cout<<"The average of the array: "<<avg<<endl;
}


void medAry(int *a,int n){
    //Assuming the array was already sorted through srtAry
    if(n%2==1){ //Test for 1 or two medians
        cout<<"The median of the array: "<<a[n/2]<<endl;
    }
    else{  //Else 2 medians
        cout<<"The medians of the array: "<<a[n/2]<<", "<<a[n/2-1]<<endl;
    }
}


void pntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==9)cout<<endl;  //10 Numbers per line
    }
    cout<<endl; 
}


void frqPrnt(int *a,int *b,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" appeared "<<b[i]<<" times."<<endl;
    }
    cout<<endl; 
}


int modeSrt(int *a,int *b,int n){
    //Declare Variables
    int nModes=1; //For the number of actual modes
    
    //Sort
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(a[pos]<a[i]){      //Highest to Lowest
                //Swap the Freq Array
                a[pos]=a[pos]^a[i];
                a[i]=a[pos]^a[i];
                a[pos]=a[pos]^a[i];
                //Swap the Mode Array with it
                b[pos]=b[pos]^b[i];
                b[i]=b[pos]^b[i];
                b[pos]=b[pos]^b[i];
            }
        }
    }     
    
    //Mode Check
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]) nModes++; //If the freq matches the next element
        else break; //To prevent later elements adding to the nModes
    } 
    
    return nModes; 
}


void modeAry(int *a,int n){ //Brings in numCpy array
    //Declare Variables
    int *mode = new int[n]{ };  //Declares and Places array in the heap
    int *freq = new int[n]{ };  //Declares and Places array in the heap
    int indx=0;   //mode/freq index
    
    //Create the Mode / Frequency array
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){      //If two elements are alike
            if(mode[indx-1]==a[i]){ //Checks if existing number
                freq[indx-1]++;  //Increase the count
            }    
            else{   //New number  
                mode[indx]=a[i];  //Stores the number matched
                freq[indx]=2;  //Account for the matching elements
                indx++;  //Position increase 
            }
        }
    }         
    
    //Sort out the Modes
    indx=modeSrt(freq,mode,indx);
            
    //Print Mode Array
    cout<<"The modes: "<<endl;
    pntAry(mode,indx);
    //Print Freq Array
    cout<<"The frequency: "<<endl;
    frqPrnt(mode,freq,indx);
    
    
    //Clean Memory
    delete []mode;
    delete []freq;
}

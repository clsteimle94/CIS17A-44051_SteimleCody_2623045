/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 9 Programming Challenge 7: Case Study Mod #2
 */

//System Libraries Here
#include <iostream>   //Input/output
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes
void arySrt(int **, int);
void shwAry(int *, int);
void ptrAry(int **,int);
void filAry(int *, int);

//Program Execution Begins
int main(int argc, char** argv) {  
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX = 25; //Max number of donations
    int *donate = new int[MAX]; //Donation Array (dynamic)
    int **aryPtr = new int*[MAX]; // An array of pointers to int.
    int amount; //Sets how much of the donation array will be used
    
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
    
    //Exit
    return 0;
}

void filAry(int *a, int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%99+1; //Random number $100-$1
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
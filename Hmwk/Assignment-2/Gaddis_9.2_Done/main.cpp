/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 9 Programming Challenge 2: Test Scores #1 
 */

//System Libraries Here
#include <iostream>   //Input/output
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes
void getScr(int,int *);    //Reads in scores from a file and creates an array
int &srtScr(int,int *);    //Makes a copy and sorts
int avgScr(int,int *);    //Finds the average score
void prntAry(int ,int *); //Prints the array

//Program Execution Begins
int main(int argc, char** argv) {      
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=40;                 //Maximum capacity for the array
    int *scores = new int[MAX];       //Declares and Places array in the heap
    int use;                          //How many scores to use
    int *scrCpy;                      //Pointer for the index array (score copy)
    
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
    
    //Exit
    return 0;
}

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
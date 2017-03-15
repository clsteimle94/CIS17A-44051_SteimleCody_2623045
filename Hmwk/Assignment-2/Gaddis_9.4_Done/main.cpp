/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 9 Programming Challenge 4: Test Scores #2
 */

//System Libraries Here
#include <iostream>   //Input/output
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
#include <string>     //getline
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes
void getScr(int,int *,string *);    //Reads in scores from a file and creates an array
int &srtScr(int,int *,string *,string *);    //Makes a copy and sorts
int drpScr(int,int *,string *);   //Lowest score will be dropped
int avgScr(int,int *);    //Finds the average score
void prntAry(int ,int *,string *); //Prints the array

//Program Execution Begins
int main(int argc, char** argv) {      
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=20;                 //Maximum capacity for the array
    int *scores = new int[MAX];       //Declares and Places array in the heap
    string *names = new string[MAX];  //Declares and Places array in the heap
    string *nmeCpy = new string[MAX];  //Index copy for names
    int use;                          //How many scores to use
    int *scrCpy;                      //Pointer for the index array (score copy)
    
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
    
    //Exit
    return 0;
}

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
/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Find the Mean, Median, and Mode of an array
 */

//System Libraries Here
#include <iostream>   //Input/output
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes
int fillAry(int *,int);
int copyAry(int *,int *,int);
void pntAry(int *,int);
void frqPrnt(int *,int *,int);   //For frequency
int modeSrt(int *,int *,int);  //For narrowing results
void srtAry(int *,int);      //Mark Sort style
void avgAry(int *,int );   //Finds the average of the int array
void medAry(int *,int );   //Finds the median of the int array
void modeAry(int *,int );  //Finds the mode of the int array

//Program Execution Begins
int main(int argc, char** argv) {      
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int MAX=100;            //Maximum capacity for the array
    int *numAry = new int[MAX];  //Declares and Places array in the heap
    int *numCpy = new int[MAX];  //Copy of the original array
    int use;                  //How many scores to use
    
    
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
    
    //Exit
    return 0;
}


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

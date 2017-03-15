/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 9 Programming Challenge 1: Array Allocator
 */

//System Libraries Here
#include <iostream>   //Input/output
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
using namespace std;

//User Libraries Here

//Global Constants

//Function Prototypes
int *makeAry(int);          //Create and fills a dynamic array
void prntArr(int,int *);  //Prints the arrays

//Program Execution Begins
int main(int argc, char** argv) {      
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
    
    //Exit
    return 0;
}


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
/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 8 Programming Challenge 7: Binary String Search
 */

//System Libraries Here
#include <iostream>
#include <vector>     //String vector
#include <algorithm>  //Sort function
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int binSrch(vector<string>,int,string);
void prntVec(vector<string>, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string person;
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
    getline(cin,person);

    //Search the array
    binSrch(name,20,person);

    //Exit 
    return 0;    
}

int binSrch(vector<string> ary,int n,string data){
    //Declare variables
    bool found=false;   //Flag
    int index=0;        //Index location of array
    char input;         //User input
    
    //Sort the array
    cout<<"sorting..."<<endl;
    sort(ary.begin(), ary.end());
    cout<<"Would you like to view the sorted array? (y/n)"<<endl;
    cin>>input;
    if(input=='y') prntVec(ary,20);           
    
    //Search the array     
    cout<<"searching..."<<endl;
    for(int i=0;i<=n;i++){
        if(ary[i]==data){     //If value is found at index
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

void prntVec(vector<string> ary, int n){
    //i = index, n = size utilized
    for(int i=1;i<=n;i++){
        cout<<ary[i-1]<<endl;
    }
    cout<<endl;
}
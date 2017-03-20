/* 
  File:   main.cpp
  Author: Cody Steimle
  Created on March 28, 2017, 12:15 PM
  Purpose:  Gaddis 11.2 - Movie Profit
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "movie.h"

//Global Constants

//Function Prototypes
Movie getMvie(Movie);    //Fills the information for the movies
void prntMv(Movie);      //Prints out the movie information
Movie getRev(Movie);     //Calculates the revenue made

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    Movie info;   //Structure for movie information
    
    //Initialize
    cout<<"This program takes program 11.1 and adds in "
            "profit calculations."<<endl;
    
    //Fill in the movie information 
    info=getMvie(info);
    
    //Calculate the revenue
    info=getRev(info);
            
    //Print
    prntMv(info);        

    //Exit
    return 0;
}

Movie getMvie(Movie mv){
    mv.title="Titanic";
    mv.directr="James Cameron";
    mv.year=1997;
    mv.length=195;  //In minutes   
    mv.cost=0.2f; //in Billions 
    mv.rev=1.84f; //in Billions 
    return mv;
}

Movie getRev(Movie mv){
    mv.profit = mv.rev - mv.cost;    
    return mv;
}

void prntMv(Movie mv){
    cout<<"Title: "<<mv.title<<endl;
    cout<<"Directed by: "<<mv.directr<<endl;
    cout<<"Year Released: "<<mv.year<<endl;
    cout<<"Length: "<<mv.length<<" Minutes"<<endl;
    cout<<"The movie netted: $"<<mv.profit<<" Profit"<<endl;
}
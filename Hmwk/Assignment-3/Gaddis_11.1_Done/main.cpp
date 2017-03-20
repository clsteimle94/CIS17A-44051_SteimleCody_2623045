/* 
  File:   main.cpp
  Author: Cody Steimle
  Created on March 28, 2017, 12:15 PM
  Purpose:  Gaddis 11.1 - Movie Data
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "movie.h"

//Global Constants

//Function Prototypes
Movie getMvie(Movie);  //Fills the information for the movie
void pntMv(Movie);     //Prints out the movie information

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    Movie info;   //Structure of the movie
    
    //Initialize
    cout<<"This program takes a structure for a movie "
            "and passes it in functions."<<endl;
    
    //Get movie information
    info=getMvie(info);
    
    //Print out the movie
    pntMv(info);

    //Exit
    return 0;
}

Movie getMvie(Movie mv){
    mv.title="Titanic";
    mv.directr="James Cameron";
    mv.year=1997;
    mv.length=195;  //In minutes   
    
    return mv;
}

void pntMv(Movie mv){
    cout<<"Title: "<<mv.title<<endl;
    cout<<"Directed by: "<<mv.directr<<endl;
    cout<<"Year Released: "<<mv.year<<endl;
    cout<<"Length: "<<mv.length<<" Minutes"<<endl;
}
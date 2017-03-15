/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 4 Programming Challenge 4: Areas of Rectangles
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int width1, length1, width2, length2; //Length and Width for 2 rectangles
    int area1, area2;     //The area for each of the rectangles

    //Input or initialize values Here
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
    
    //Exit
    return 0;
}

// 4. Areas of Rectangles
//The area of a rectangle is the rectangle’s length times its width. Write a program that
//asks for the length and width of two rectangles. The program should tell the user which
//rectangle has the greater area, or if the areas are the same. 
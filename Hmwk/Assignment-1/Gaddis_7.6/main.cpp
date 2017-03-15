/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on March 1, 2017, 12:20 PM
 * Purpose:  Gaddis Chapter 7 Programming Challenge 6: Rain or Shine
 */

//System Libraries Here
#include <iostream>   //Input and ouput
#include <fstream>    //File input and output
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
const int ROWS=2;   //Number of Rows
const int COLS=30;  //Number of Columns

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char monDay[ROWS][COLS]; //The 2D Array for months(rows) and days of(columns)
                                //[0=June, 1=July, 2=August][0-30 Days (no 31st)]
    ifstream in;             //Input file
    ofstream out;            //Output file
	
	//Outputing to a file
	//out.open("score.dat");
	//out<<" Winner: "<<line<<" | Number of turns: "<<turn;
	
	//Reading in from a file
	//in.open("score.dat");
    //getline(in,results);
	//cout<<results<<endl;
	
	//Close the file
    //in.close();        
    //out.close();    
	
	
    //Input or initialize values Here
    cout<<"This program will display last year's summer weather report (3 months)"<<endl;
    //Process/Output
	
	//for-loop
		//for-loop
			//if(c,r,s)
				//track count in a counter each
	//Compare which month had more rainy days
	//Shows the counts(s,c,r) for each month
    
    
    //Exit
    return 0;
}

//Character arrays (3 of them, 30 in size)
//row = month
//colonm = day (not doing the 31st?)
//read-in data from file



//7.6 Rain or Shine
//An amateur meteorologist wants to keep track of weather conditions during the
//past year’s three-month summer season and has designated each day as either rainy
//(‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this information in a
//3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July,
//2 = August) and the column indicates the day of the month. Note that data are not
//being collected for the 31st of any month. The program should begin by reading the
//weather data in from a file. Then it should create a report that displays, for each
//month and for the whole three-month period, how many days were rainy, how many
//were cloudy, and how many were sunny. It should also report which of the three
//months had the largest number of rainy days. Data for the program can be found in
//the RainOrShine.txt file. 

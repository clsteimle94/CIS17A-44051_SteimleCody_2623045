/* 
 * File:   main.cpp
 * Author: Cody Steimle
 * Created on April 7, 2017, 8:40 AM
 * Purpose:  A game of War Chess!
 */

//System Libraries Here
#include <iostream> //Input/Output objects
#include <fstream>  //File input and output
#include <string>   //String
#include <cstdlib>  //C Standard Library
#include <ctime>    //Time
using namespace std;

//User Libraries Here
#include "Army.h"

//Global Constants
const int ROWS=8;  //Number of Rows for 2D array
const int COLS=10;  //Number of columns for 2D array

//Function Prototypes
void ttlScrn();           //Main menu
void prntfil(ifstream &); //Print an entire file
void binPrnt(fstream &);  //Print an entire file from binary
void getName(string &);   //Get the player's name
void disRule();           //Display rules
bool coinFlp(string &);   //Coin flip  
void fillMap(char [ROWS][COLS]);  //Fill in the game board
void plcUnit(Army *);     //Gives the units starting positions
void updtMap(Army *,char [ROWS][COLS]);     //Update character positions
void shwMap(char [ROWS][COLS]);   //Print the board
bool strtGam(string &,Army *,int &,char [ROWS][COLS]); //Begins the game and loops
void mkeArmy(Army *);      //Create each player's army stats
void nmeArmy(Army *);      //Names the individual units
void lstUnts(Army *);   //Prints out all player's units
void copyAry(Army *,Army **,int);  //Copies the structure array
bool pTurn(string &,Army *,int &,char [ROWS][COLS]); //Player's turn
bool cTurn(Army *,int &,char [ROWS][COLS]);        //Computer's turn
bool plyrAtk(Army *,char [ROWS][COLS]);  //Checks and delivers attacks
bool compAtk(Army *,char [ROWS][COLS]);  //Checks and delivers attacks
bool plyrMov(Army *,char [ROWS][COLS]);  //Checks and determines movement
int srchLoc(Army *,int ,int);  //Searches for a unit given the location
bool compMov(Army *,char [ROWS][COLS]);  //Checks and determines movement
bool testMov(int,char,int,Army *,char [ROWS][COLS]);  //Tests movement
bool tstMovC(int,char,int,Army *,char [ROWS][COLS]);  //Tests movement computer
void chkUnit(Army *);  //Prints the units information
void deadChk(Army *);  //Moves dead things off the grid
void savGame(bool,int &, string);   //Prompts to output game to file
void endGame();     //Concludes the game

//Program Execution Begins
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    string name;  //Player's Name
    bool isWinnr;               //0=player lost, 1=player won 
    char board[ROWS][COLS]={ }; //The board 
    int turn=1;         //Counter for turns
    Army unit[12]={ };  //Structure array of the player's and comp's units
    
    //Main Menu
    ttlScrn();
      
    //Input name
    getName(name);
    
    //Game Setup
    fillMap(board);
    
    //Create the teams
    mkeArmy(unit);      
    nmeArmy(unit);
    plcUnit(unit);
    
    //Begin the game
    isWinnr=strtGam(name,unit,turn,board);
    
    //Post game
    savGame(isWinnr,turn,name);
    endGame();
    
    //Exit
    return 0;
}


//*****************************   ttlScrn  *************************************
//Purpose:  Displays the rules
//Inputs:   None
//Output:   None
//******************************************************************************
void ttlScrn(){
    //Declare Variables
    int menuItm; //Choice for menu
    ifstream in; //Input file for title screen
    
    //Open file
    in.open("title.txt");
    
    //Print the title
    prntfil(in);
      
    //Loop until users exits
    do{
        //Prompt for problem for user input
        cout<<"~MAIN MENU~"<<endl;
        cout<<"1.  Type 1  for: New Game"<<endl;
        cout<<"2.  Type 2  for: Rules"<<endl;
        cin>>menuItm;
        
        //Display rules
        if(menuItm==2) disRule();
        
    }while(menuItm==2); //Ends the Do-While Loop    
}


//****************************   disRule  **************************************
//Purpose:  Displays the rules
//Inputs:   None
//Output:   None
//******************************************************************************
void disRule(){
    //Initialize
    cout<<endl;
    cout<<"----------------------------Rules----------------------------"<<endl;
    cout<<"1) Each turn consists of one attack and one turn, however, both are"
            " not required."<<endl;
    cout<<endl;
    cout<<"2) You will be given a total of 6 game pieces: 3 Infantry, "
            "2 Commanders, and 1 General. You make check their stats during "
            "your turn."<<endl;
    cout<<endl;
    cout<<"3) The game will conclude when any of the Generals are killed."<<endl;
    cout<<endl;
    cout<<"4) There are no diagonal moves or attacks in the game."<<endl;
    cout<<endl;
    cout<<"5) The # are health packs, which add 2 more health points to the"
            " unit who landed on it (no health cap)"<<endl;
    cout<<endl;
    cout<<"6) Units may not land on top of other units or leave the map, the"
            " game will not allow it."<<endl;
    cout<<endl;
    cout<<"7) Attacking is only for adjacent units, there are no ranged attacks"
            "."<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<endl;
}


//****************************   getName  **************************************
//Purpose:  Gets the name of the player
//Inputs:   None
//Output:   None
//******************************************************************************
void getName(string &name){
    //Input name
    cout<<"Please enter your name:"<<endl;
    getline(cin,name); //Clears cin
    getline(cin,name);
}


//****************************   fillMap  **************************************
//Purpose:  Create the map
//Inputs:   None
//Output:   None
//******************************************************************************
void fillMap(char board[ROWS][COLS]){
    //Declare Variables
    int NumHP=2; //Number of health packs
    int randRow; //Random row
    int randCol; //Random col
    
    //Empty Map
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            board[row][col]='-';
        }
    }
    //Place Random Health Packs
    for(int i=0;i<NumHP;i++){
        randRow=rand()%2+3;  //Rows[4-5]
        randCol=rand()%4+2;  //Cols[2-8]
        //Check if spot is taken already
        if(board[randRow][randCol]=='#'){
            i--; //Run through the loop one more time
        }
        //Check for surrounding health packs
        else if(board[randRow-1][randCol]=='#'||
                board[randRow+1][randCol]=='#'||
                board[randRow][randCol-1]=='#'||
                board[randRow][randCol+1]=='#'){
            i--; //Run through the loop one more time
        }   
        //Place the health pack
        else board[randRow][randCol]='#';
    }    
}


//*****************************   shwMap  **************************************
//Purpose:  Print the game board.
//Inputs:   None
//Output:   board[][] array
//******************************************************************************
void shwMap(char board[ROWS][COLS]){
    //Declare Variables 
    int rowNum=1;
    int colNum=1;
  
    cout<<endl;
    
    //Print the board
    cout<<"  ";
    for(int col=0;col<COLS;col++){
        cout<<colNum++<<" ";
    }
    cout<<endl;
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            if(col%COLS==0)cout<<rowNum++<<" "; //The side of the board
            cout<<board[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


//****************************   lstUnts  **************************************
//Purpose:  Prints out every unit of the players
//Inputs:   None
//Output:   None
//******************************************************************************
void lstUnts(Army *unit){
    //Declare Variables
    Army **armyCpy=new Army*[6];  //Array of pointers
    
    //Copy the structure
    //copyAry(unit,armyCpy,6);
    
    //Display the units
    for(int i=0;i<6;i++){;
        cout<<"Number (icon): "<<unit[i].symbol<<endl;
        cout<<"Name: "<<unit[i].name<<endl;
        cout<<"Class: "<<unit[i].type<<endl;
        cout<<"Health left: "<<unit[i].health<<endl;
        cout<<"Location: R:"<<unit[i].rLocate+1
                     <<" C:"<<unit[i].cLocate+1<<endl;  
        cout<<endl;
    }
    
    //Clean-up memory
    delete []armyCpy;
}


//****************************   copyAry  **************************************
//Purpose:  Copies an array
//Inputs:   None
//Output:   None
//******************************************************************************
void copyAry(Army *unit,Army **armyCpy,int size){
    for(int i=0;i<size;i++){
        (*armyCpy)[i].symbol=unit[i].symbol;
        (*armyCpy)[i].name=unit[i].name;
        (*armyCpy)[i].type=unit[i].type;
        (*armyCpy)[i].health=unit[i].health;
        (*armyCpy)[i].rLocate=unit[i].rLocate;
        (*armyCpy)[i].cLocate=unit[i].cLocate;
    }
}


//****************************   prntfil  **************************************
//Purpose:  Prints a file's contents
//Inputs:   None
//Output:   None
//******************************************************************************
void prntfil(ifstream &file){
    //Declare Variables
    string filLine; //A line of the file
    
    if(file.is_open()){
        while(getline(file,filLine)){
            cout<<filLine<<'\n';
        }
        file.close();
    }
    else cout<<"Unable to open file"<<endl;     
    cout<<endl;
}


//****************************   binPrnt  **************************************
//Purpose:  Prints a file's contents from binary
//Inputs:   None
//Output:   None
//******************************************************************************
void binPrnt(fstream &file){
    //Declare Variables
    string filLine; //A line of the file
    
    if(file.is_open()){
        while(getline(file,filLine)){
            cout<<filLine<<'\n';
        }
        file.close();
    }
    else cout<<"Unable to open file"<<endl;     
    cout<<endl;
}


//****************************   mkeArmy  **************************************
//Purpose:  Make each player's army
//Inputs:   None
//Output:   None
//******************************************************************************
void mkeArmy(Army *unit){
    //Declare variables
    char mapIcn='1';  //Used for setting the icons for the player
    
    //Player's Armys [0-5] Comp's Armys [6-11]
    //Player Infantry
    for(int i=0;i<3;i++){
        unit[i].type="Infantry";
        unit[i].attack=1;
        unit[i].health=1;
        unit[i].move=3;
    }        
    //Comp Infantry
    for(int i=6;i<9;i++){
        unit[i].type="Infantry";
        unit[i].symbol='I';
        unit[i].attack=1;
        unit[i].health=1;
        unit[i].move=3;
    }   
    //Player Lieutenants
    for(int i=3;i<5;i++){
        unit[i].type="Commander";
        unit[i].attack=2;
        unit[i].health=2;
        unit[i].move=2;
    }
    //Comp Lieutenants
    for(int i=9;i<11;i++){
        unit[i].type="Commander";
        unit[i].symbol='C';
        unit[i].attack=2;
        unit[i].health=2;
        unit[i].move=2;
    }   
    //Generals 
    unit[5].type="General";;
    unit[5].attack=3;
    unit[5].health=3;
    unit[5].move=1;
    unit[11].type="General";
    unit[11].symbol='G';
    unit[11].attack=3;
    unit[11].health=3;
    unit[11].move=1;    
    //Appoint map icons
    for(int i=0;i<6;i++){
        unit[i].symbol=mapIcn++;    
    }   
}


//****************************   nmeArmy  **************************************
//Purpose:  Name each player's army
//Inputs:   None
//Output:   None
//******************************************************************************
void nmeArmy(Army *unit){
    //Declare Variables
    string line;
    
    //Infantry
    for(int i=0;i<3;i++){
        cout<<"Please enter the name of your Infantry #"<<i+1<<":"<<endl;
        getline(cin,line);
        unit[i].name=line;
    }
    //Commanders
    for(int i=3;i<5;i++){
        cout<<"Please enter the name of your Commander #"<<i+1<<":"<<endl;
        getline(cin,line);
        unit[i].name=line;
    }
    //General
    cout<<"Please enter the name of your General: "<<endl;
    getline(cin,line);
    unit[5].name=line; 
}


//****************************   plcUnit  **************************************
//Purpose:  Places all the units to start the game
//Inputs:   None
//Output:   None
//******************************************************************************
void plcUnit(Army *unit){
    //Infantry [0-2]=Player's [6-8]=Comp's
    unit[0].rLocate=5;
    unit[0].cLocate=0;
    unit[1].rLocate=6;
    unit[1].cLocate=1;
    unit[2].rLocate=7;
    unit[2].cLocate=2;
    unit[6].rLocate=0;
    unit[6].cLocate=7;
    unit[7].rLocate=1;
    unit[7].cLocate=8;
    unit[8].rLocate=2;
    unit[8].cLocate=9;
    
    //Commanders [3-4]=Player's [9-10]=Comp's
    unit[3].rLocate=6;
    unit[3].cLocate=0;
    unit[4].rLocate=7;
    unit[4].cLocate=1;
    unit[9].rLocate=0;
    unit[9].cLocate=8;
    unit[10].rLocate=1;
    unit[10].cLocate=9;  
       
    //Generals [5]=Player's [11]=Comp's
    unit[5].rLocate=7;
    unit[5].cLocate=0;
    unit[11].rLocate=0;
    unit[11].cLocate=9;
}

//****************************   updtMap  **************************************
//Purpose:  Places all the units to start the game
//Inputs:   None
//Output:   None
//******************************************************************************
void updtMap(Army *unit,char board[ROWS][COLS]){
    //Delete the units
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            if(board[row][col]!='-'&&board[row][col]!='#') board[row][col]='-';
        }
    }
    
    //Redraw the units
    for(int i=0;i<12;i++){
        board[unit[i].rLocate][unit[i].cLocate]=unit[i].symbol;
    }
}

//****************************   coinFlp  **************************************
//Purpose:  Flips a coin to determine turn order
//Inputs:   human, choice of heads or tails
//Output:   Winner of coin flip
//******************************************************************************
bool coinFlp(string &name){
    //Declare Variables
    char human;    //Human input
    int coin;      //Coin flip for heads or tails
    bool isWon;    //Did the player win coin flip   
    //Initialize
    cout<<"Coin Flip to find out who goes first."<<endl;
    //Pick either Heads or Tails
    do{  //Validate Input
        cout<<"Pick Heads(H) or Tails(T):"<<endl;
        cin>>human;            
    }while(human!='h'&&human!='H'&&human!='t'&&human!='T');     
    if(human=='h'||human=='H'){
        cout<<"You picked Heads, the Computer picks Tails."<<endl;
        human='H';
    }        
    else{
        cout<<"You picked Tails, the Computer picks Heads."<<endl;
        human='T';  
    }  
    //The coin flip (1-2)
    coin=rand()%2+1;
    //Check the winner
    if(coin==1){         //Coin landed on heads
        cout<<"The coin landed on Heads"<<endl;
        if(human=='H'){  //If player chose heads
            cout<<name<<" will go first."<<endl;
            return isWon=1; //Player won the coin toss
        }
        else{  //Player chose tails
            cout<<"Computer will go first."<<endl; 
            return isWon=0; //Player lost the coin toss
        }      
    }
    else{ //Coin landed on tails
        cout<<"The coin landed on Tails"<<endl;
        if(human=='H'){  //If player chose heads
            cout<<"Computer will go first."<<endl; 
            return isWon=0; //Player lost the coin toss
        }
        else{  //Player chose tails
            cout<<name<<" will go first."<<endl;
            return isWon=1; //Player won the coin toss
        }
    }
}    


//****************************   strtGam  **************************************
//Purpose:  Player's Turn.
//Inputs:   None
//Output:   None
//******************************************************************************
bool strtGam(string &name,Army *unit,int &turn,char board[ROWS][COLS]){
    //Declare Varible
    bool isOver=0;  //Checks if the game is over
    bool isWinnr=0; //Checks if the player won
    
    //Get turn order and start the game
    if(coinFlp(name)){
        do{
            isOver = pTurn(name,unit,turn,board);
            if(isOver) isWinnr=1; //Player won
            if(!isOver) isOver=cTurn(unit,turn,board);   
        }while(!isOver);            
    }
    else{
        do{
            isOver = cTurn(unit,turn,board);
            if(!isOver){
                isOver=pTurn(name,unit,turn,board);   
                if(isOver) isWinnr=1; //Player won
            }    
        }while(!isOver);   
    }
    
    //Declare Winner
    if(isWinnr) cout<<"*****"<<name<<" Won!*****"<<endl;    
    else cout<<"*****You Lose.*****"<<endl;   
    
    return isWinnr;
}


//****************************   deadChk  **************************************
//Purpose:  Player's Turn.
//Inputs:   None
//Output:   None
//******************************************************************************
void deadChk(Army *unit){
    for(int i=0;i<12;i++){
        if(unit[i].health<=0){
            unit[i].rLocate=-1;
            unit[i].cLocate=-1;
        }    
    }
}


//*****************************   pTurn  ***************************************
//Purpose:  Player's Turn.
//Inputs:   None
//Output:   None
//******************************************************************************
bool pTurn(string &name,Army *unit,int &turn,char board[ROWS][COLS]){
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Turn #"<<turn++<<": "<<name<<"'s Turn"<<endl; 
    cout<<"---------------------------------------------------"<<endl;
   
    //Declare Variables
    bool isMoved=0;
    bool isAtked=0;
    bool isOver=0;
    char input;

    //Menu
    do{
        //Print Board
        updtMap(unit,board);
        shwMap(board);
        
        cout<<"       Menu:"<<endl;
        cout<<"Type 1 for: Attack"<<endl;
        cout<<"Type 2 for: Move"<<endl; 
        cout<<"Type 3 for: Check a unit"<<endl; 
        cout<<"Type 4 for: View all units"<<endl;
        cout<<"Type 5 for: End turn"<<endl;
        
        cout<<"Type 6 for: End game"<<endl;
        cin>>input;
        
        if(input=='6') unit[11].health=0;
        
        if(input=='5') break; //Ends turn
        
        switch(input){
            case'1':if(!isAtked) isAtked=plyrAtk(unit,board);break;                     
            case'2':if(!isMoved) isMoved=plyrMov(unit,board);break;
            case'3':chkUnit(unit);break;
            case'4':lstUnts(unit);
        } 
        if(isAtked) cout<<"You have already attacked."<<endl;
        if(isMoved) cout<<"You have already moved."<<endl;
        
        cout<<input<<endl;
        
    }while(!isMoved||!isAtked);
    
    //Game Over Check
    if(unit[11].health==0) isOver=1;  //Comp General's Health
    
    //End Turn
    return isOver;
}


//*****************************   cTurn  ***************************************
//Purpose:  Computer's Turn
//Inputs:   None
//Output:   None
//******************************************************************************
bool cTurn(Army *unit,int &turn,char board[ROWS][COLS]){
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Turn #"<<turn++<<": Computer's Turn"<<endl;
    cout<<"---------------------------------------------------"<<endl;
   
    //Declare Variables
    bool isMoved=0;
    bool isAtked=0;
    bool isOver=0;
    char input;

    //Menu
    do{
        //Update the board
        updtMap(unit,board);
        
        input=rand()%2+49;  //Calls random function, then modifies to 1-2
            
        switch(input){
            case'1':if(!isAtked) isAtked=compAtk(unit,board);break;                     
            case'2':if(!isMoved) isMoved=compMov(unit,board);
        } 
    }while(!isMoved||!isAtked);
    
    //Print Board
    updtMap(unit,board);
    shwMap(board);
    
    //Game Over Check
    if(unit[5].health==0) isOver=1;  //Comp General's Health
    
    //End Turn
    return isOver;
}


//****************************   plyrAtk  **************************************
//Purpose:  Attack
//Inputs:   None
//Output:   None
//******************************************************************************
bool plyrAtk(Army *unit,char board[ROWS][COLS]){
    //Declare Variables
    bool isAtked=1;
    char directn;  //Direction
    int pikArmy;   //Choice of unit
    int unitR;  //Stores unit's Row
    int unitC;   //Stores unit's Column
    int target;  //The unit number of the defender
    int targetR; //Targets Row
    int targetC; //Targets Column
    
    //Choose unit
    do{
        cout<<"Choose which unit you want (1-6)"<<endl;
        cin>>pikArmy;
        //Alive check
        if(unit[pikArmy-1].health<=0){
            cout<<"This unit is dead."<<endl;
            pikArmy=-1;
        }       
    }while(pikArmy<1||pikArmy>6);
    
    //Store unit locations
    unitR=unit[pikArmy-1].rLocate;
    unitC=unit[pikArmy-1].cLocate;
    
    //Check for any attack options
    if((board[unitR-1][unitC]=='-'||board[unitR-1][unitC]=='#')&&
       (board[unitR+1][unitC]=='-'||board[unitR-1][unitC]=='#')&&
       (board[unitR][unitC-1]=='-'||board[unitR-1][unitC]=='#')&&
       (board[unitR][unitC+1]=='-'||board[unitR-1][unitC]=='#')){
        cout<<"There is nothing for this unit to attack within range."<<endl;
        return isAtked=0; //Reset the value since unable to attack
    }
    
    //Pick attack direction
    do{
        cout<<"Choose the direction (U,D,L,R)"<<endl;
        cin>>directn;
    }while(directn!='u'&&directn!='U'&&directn!='d'&&directn!='D'&&
           directn!='l'&&directn!='L'&&directn!='r'&&directn!='R'); 

    //Get the opponents location
    if(directn=='u'||directn=='U'){ 
        targetR=unitR-1;
        targetC=unitC;
    }
    else if(directn=='d'||directn=='D'){
        targetR=unitR+1;
        targetC=unitC;
    }
    else if(directn=='l'||directn=='L'){
        targetR=unitR;
        targetC=unitC-1;
    }
    else{
        targetR=unitR;
        targetC=unitC+1;
    }   
    
    //Search for the unit
    target=srchLoc(unit,targetR,targetC);   
    
    //The Attack
    if(target>=0) unit[target].health-=unit[pikArmy-1].attack;
    
    //Check if anyone died
    deadChk(unit);
    
    //Return
    return isAtked;
}


//****************************   compAtk  **************************************
//Purpose:  Attack
//Inputs:   None
//Output:   None
//******************************************************************************
bool compAtk(Army *unit,char board[ROWS][COLS]){
    //Declare Variables
    bool isAtked=1;
    char directn;  //Direction
    int pikArmy;   //Choice of unit
    int unitR;  //Stores unit's Row
    int unitC;   //Stores unit's Column
    int target;  //The unit number of the defender
    int targetR; //Targets Row
    int targetC; //Targets Column
    
    //Choose unit
    do{
        pikArmy=rand()%6+6;  //6-11
        
        //Alive check
        if(unit[pikArmy-1].health<=0){
            pikArmy=-1;
        }       
    }while(pikArmy<0);
    
    //Store unit locations
    unitR=unit[pikArmy].rLocate;
    unitC=unit[pikArmy].cLocate;
    
    //Check for any attack options
    if((board[unitR-1][unitC]=='-'||board[unitR-1][unitC]=='#')&&
       (board[unitR+1][unitC]=='-'||board[unitR-1][unitC]=='#')&&
       (board[unitR][unitC-1]=='-'||board[unitR-1][unitC]=='#')&&
       (board[unitR][unitC+1]=='-'||board[unitR-1][unitC]=='#')){
        return isAtked=0; //Reset the value since unable to attack
    }

    //Get the opponents location and check for attacks
    //Test Up
    targetR=unitR-1;
    targetC=unitC;
    if(board[targetR][targetC]!='-'){
        //Search for the unit
        target=srchLoc(unit,targetR,targetC);   
        //The Attack
        if(target>=0) unit[target].health-=unit[pikArmy].attack;
        //Check if anyone died
        deadChk(unit);
        //Return
        return isAtked;
    }
    //Test Down
    targetR=unitR+1;
    if(board[targetR][targetC]!='-'){
        //Search for the unit
        target=srchLoc(unit,targetR,targetC);   
        //The Attack
        if(target>=0) unit[target].health-=unit[pikArmy].attack;
        //Check if anyone died
        deadChk(unit);
        //Return
        return isAtked;
    }
    //Test Left
    targetR=unitR;
    targetC=unitC-1;
    if(board[targetR][targetC]!='-'){
        //Search for the unit
        target=srchLoc(unit,targetR,targetC);   
        //The Attack
        if(target>=0) unit[target].health-=unit[pikArmy].attack;
        //Check if anyone died
        deadChk(unit);
        //Return
        return isAtked;
    }
    //Test Right
    targetC=unitC+1;
    if(board[targetR][targetC]!='-'){
        //Search for the unit
        target=srchLoc(unit,targetR,targetC);   
        //The Attack
        if(target>=0) unit[target].health-=unit[pikArmy].attack;
        //Check if anyone died
        deadChk(unit);
        //Return
        return isAtked;
    }
    
    //Return
    return isAtked;
}


//****************************   plyrMov  **************************************
//Purpose:  Move
//Inputs:   None
//Output:   None
//******************************************************************************
bool plyrMov(Army *unit,char board[ROWS][COLS]){
    //Declare Variables
    bool isMoved=1;
    bool isAllow=0; //Checks if movement is allowed
    int pikArmy;    //Choice of unit
    int distanc;    //How far the unit will travel
    char directn;   //Direction
    int unitR; //Stores unit's Row
    int unitC; //Stores unit's Column
    
    //Choose unit
    do{
        cout<<"Choose which unit you want (1-6)"<<endl;
        cin>>pikArmy;
        //Alive check
        if(unit[pikArmy-1].health<=0){
            cout<<"This unit is dead."<<endl;
            pikArmy=-1;
        }
        
    }while(pikArmy<1||pikArmy>6);
    
    //Get unit's position
    unitR=unit[pikArmy-1].rLocate;
    unitC=unit[pikArmy-1].cLocate;
    
    //Check selected unit's movement options
    if((board[unitR+1][unitC]!='-'&&board[unitR+1][unitC]!='#')&&
       (board[unitR-1][unitC]!='-'&&board[unitR-1][unitC]!='#')&&
       (board[unitR][unitC+1]!='-'&&board[unitR][unitC+1]!='#')&&
       (board[unitR][unitC-1]!='-'&&board[unitR][unitC-1]!='#')){
        cout<<"There is no place for that unit to move to."<<endl;
        return isMoved=0; //Reset the value since unable to attack
    }
    
    //Perform the movement 
    do{
        cout<<"Your move may not overlap other units."<<endl;
        do{
            cout<<"Choose the direction (U,D,L,R)"<<endl;
            cin>>directn;
        }while(directn!='u'&&directn!='U'&&directn!='d'&&directn!='D'&&
               directn!='l'&&directn!='L'&&directn!='r'&&directn!='R'); 
        do{
            cout<<"Choose a valid amount of spaces to move"<<endl;
            cin>>distanc;
        }while(distanc<1||distanc>unit[pikArmy-1].move);  
        //Test movement
        isAllow=testMov(pikArmy,directn,distanc,unit,board);
    }while(!isAllow);    //Repeat until valid move
    
    //Set the new locations
    if(directn=='u'||directn=='U') unit[pikArmy-1].rLocate-=distanc; 
    else if(directn=='d'||directn=='D') unit[pikArmy-1].rLocate+=distanc;
    else if(directn=='l'||directn=='L') unit[pikArmy-1].cLocate-=distanc;
    else unit[pikArmy-1].cLocate+=distanc;
    
    //Bounds check for map edges
    if(unit[pikArmy-1].rLocate<0) unit[pikArmy-1].rLocate=0;
    else if(unit[pikArmy-1].rLocate>7) unit[pikArmy-1].rLocate=7; 
    if(unit[pikArmy-1].cLocate<0) unit[pikArmy-1].cLocate=0;
    else if(unit[pikArmy-1].cLocate>9) unit[pikArmy-1].cLocate=9;
    
    //Return
    return isMoved;
}


//****************************   compMov  **************************************
//Purpose:  Move
//Inputs:   None
//Output:   None
//******************************************************************************
bool compMov(Army *unit,char board[ROWS][COLS]){
    //Declare Variables
    bool isMoved=1;
    bool isAllow=0; //Checks if movement is allowed
    int pikArmy;    //Choice of unit
    int distanc;    //How far the unit will travel
    char directn;   //Direction
    int unitR; //Stores unit's Row
    int unitC; //Stores unit's Column
    
    //Choose unit
    do{
        pikArmy=rand()%6+6;  //6-11
        
        //Alive check
        if(unit[pikArmy-1].health<=0){
            pikArmy=-1;
        }
        
    }while(pikArmy<0);
    
    //Get unit's position
    unitR=unit[pikArmy].rLocate;
    unitC=unit[pikArmy].cLocate;
    
    //Check selected unit's movement options
    if((board[unitR+1][unitC]!='-'&&board[unitR+1][unitC]!='#')&&
       (board[unitR-1][unitC]!='-'&&board[unitR-1][unitC]!='#')&&
       (board[unitR][unitC+1]!='-'&&board[unitR][unitC+1]!='#')&&
       (board[unitR][unitC-1]!='-'&&board[unitR][unitC-1]!='#')){
        return isMoved=0; //Reset the value since unable to attack
    }
    
    //Perform the movement 
    do{     
        //Pick attack direction
        directn=rand()%4+49;  //Calls random function, then modifies to 1-4; 
        do{
            distanc=rand()%3+1;  //Calls random function, then modifies to 1-3; ;
        }while(distanc<1||distanc>unit[pikArmy].move);  
        //Test movement
        isAllow=tstMovC(pikArmy,directn,distanc,unit,board);
    }while(!isAllow);    //Repeat until valid move
    
    //Set the new locations
    if(directn=='1') unit[pikArmy].rLocate-=distanc; 
    else if(directn=='2') unit[pikArmy].rLocate+=distanc;
    else if(directn=='3') unit[pikArmy].cLocate-=distanc;
    else unit[pikArmy].cLocate+=distanc;
    
    //Bounds check for map edges
    if(unit[pikArmy].rLocate<0) unit[pikArmy].rLocate=0;
    else if(unit[pikArmy].rLocate>7) unit[pikArmy].rLocate=7; 
    if(unit[pikArmy].cLocate<0) unit[pikArmy].cLocate=0;
    else if(unit[pikArmy].cLocate>9) unit[pikArmy].cLocate=9;
    
    //Return
    return isMoved;
}

//****************************   tstMovC  **************************************
//Purpose:  Computer Move Test
//Inputs:   None
//Output:   None
//******************************************************************************
bool tstMovC(int pikArmy,char directn,int distanc,Army *unit,char board[ROWS][COLS]){      
    //Declare Variables
    int testR;
    int testC;
    bool isAllow=0;
    
    //Test the movement    
    if(directn=='1'){
        testR=unit[pikArmy-1].rLocate-distanc; 
        testC=unit[pikArmy-1].cLocate;
    }    
    else if(directn=='2'){
        testR=unit[pikArmy-1].rLocate+distanc; 
        testC=unit[pikArmy-1].cLocate;
    }
    else if(directn=='3'){
        testC=unit[pikArmy-1].cLocate-distanc; 
        testR=unit[pikArmy-1].rLocate;
    }
    else{
        testC=unit[pikArmy-1].cLocate+distanc; 
        testR=unit[pikArmy-1].rLocate;
    }
    //Return
    if(board[testR][testC]=='-') return isAllow=1;   
    else if(board[testR][testC]=='#'){
        cout<<"Computer landed on a health pack! +2 HP"<<endl;
        unit[pikArmy-1].health+=2;  //Adds 2 HP to the unit
        return isAllow=1;
    }    
    else return isAllow=0; 
    
}

//****************************   testMov  **************************************
//Purpose:  Move
//Inputs:   None
//Output:   None
//******************************************************************************
bool testMov(int pikArmy,char directn,int distanc,Army *unit,char board[ROWS][COLS]){      
    //Declare Variables
    int testR;
    int testC;
    bool isAllow=0;
    
    //Test the movement    
    if(directn=='u'||directn=='U'){
        testR=unit[pikArmy-1].rLocate-distanc; 
        testC=unit[pikArmy-1].cLocate;
    }    
    else if(directn=='d'||directn=='D'){
        testR=unit[pikArmy-1].rLocate+distanc; 
        testC=unit[pikArmy-1].cLocate;
    }
    else if(directn=='l'||directn=='L'){
        testC=unit[pikArmy-1].cLocate-distanc; 
        testR=unit[pikArmy-1].rLocate;
    }
    else{
        testC=unit[pikArmy-1].cLocate+distanc; 
        testR=unit[pikArmy-1].rLocate;
    }
    //Return
    if(board[testR][testC]=='-') return isAllow=1;   
    else if(board[testR][testC]=='#'){
        cout<<"Landed on a health pack! +2 HP"<<endl;
        unit[pikArmy-1].health+=2;  //Adds 2 HP to the unit
        return isAllow=1;
    }    
    else return isAllow=0; 
    
}


//****************************   srchLoc  **************************************
//Purpose:  Search the structure array for matching position
//Inputs:   None
//Output:   None
//******************************************************************************
int srchLoc(Army *unit,int row,int col){
    for(int i=0;i<12;i++){
        if(unit[i].rLocate==row&&unit[i].cLocate==col) return i;
    }
    cout<<"No unit at that location."<<endl;
    return -1;
}

//****************************   chkUnit  **************************************
//Purpose:  Move
//Inputs:   None
//Output:   None
//******************************************************************************
void chkUnit(Army *unit){
    //Declare Variables
    int pikArmy;   //Choice of unit
    
    //Choose unit
    do{
        cout<<"Choose which unit you want (1-6)"<<endl;
        cin>>pikArmy;
    }while(pikArmy<1||pikArmy>6);
    //Display
    cout<<"Number (icon): "<<unit[pikArmy-1].symbol<<endl;
    cout<<"Name: "<<unit[pikArmy-1].name<<endl;
    cout<<"Class: " <<unit[pikArmy-1].type<<endl;
    cout<<"Health left: "<<unit[pikArmy-1].health<<endl;
    cout<<"Attack: "<<unit[pikArmy-1].attack<<endl;
    cout<<"Move: "<<unit[pikArmy-1].move<<endl;
    cout<<"Location: R:"<<unit[pikArmy-1].rLocate+1
                 <<" C:"<<unit[pikArmy-1].cLocate+1<<endl;  
    cout<<endl;
}


//****************************   savGame  **************************************
//Purpose:  Prompts the user to save the game results to a file.
//Inputs:   human, choice of yes or no
//Output:   Save game file
//******************************************************************************
void savGame(bool isWinnr,int &turn,string name){
    //Declare Variables
    char mnuInpt;   //Input for the menu
    ifstream in;    //Input file
    ofstream out;   //Output file    
    fstream bin;   //Input/Output file in binary
    
    //Decrement last turn
    turn--;
    
    //Initialize
    cout<<"Would you like to save the results to a file? (Y/N):";
    cin>>mnuInpt;
    switch(mnuInpt){
        case 'y':
        case 'Y': {
            //Open files
            out.open("results.txt");
            bin.open("results_bin.txt", ios::out | ios::binary);
            //Write to files
            if(isWinnr){  //Player Won 
               out<<"Winner: "<<name<<endl; 
               bin.write(reinterpret_cast<char *>(&name), sizeof(name));
            }
            else{  //Comp Won
                out<<"Winner: Computer"<<endl;
                //bin.write(reinterpret_cast<char *>(&name), sizeof(name));
            }
            out<<"Number of turns: "<<turn<<endl;        
            cout<<"Saved!"<<endl;
            //Close files
            out.close(); 
            bin.close();
            
            cout<<"Would you like to see the results? (Y/N):";
            cin>>mnuInpt;
            switch(mnuInpt){
                case 'y':
                case 'Y': {
                    //Open files
                    in.open("results.txt");
                    bin.open("results_bin.txt", ios::in | ios::binary);
                    
                    cout<<"The Results:"<<endl;
                    prntfil(in);
                    
                    cout<<"The Results (from binary):"<<endl;
                    binPrnt(bin);                  
                }   
            }    
        }    
    }
}


//****************************   endGame  **************************************
//Purpose:  Computer's Turn
//Inputs:   None
//Output:   None
//******************************************************************************
void endGame(){
    cout<<"*************************************************************"<<endl;
    cout<<"*                    Thanks for playing!                    *"<<endl; 
    cout<<"*************************************************************"<<endl;
}
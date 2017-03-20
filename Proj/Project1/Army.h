/* 
 * Author: Cody Steimle
 * Created on April 7, 2017, 8:40 AM
 * Purpose:  Specification for the Array structure
 */

#ifndef ARMY_H
#define ARMY_H

struct Army{  
    string name; //The name of the unit
    string type; //The type of the unit
    char symbol; //Symbol for the map
    int health;  //The remaining health
    int attack;  //The attack stat
    int move;    //How far the unit can move
    short int rLocate; //Where the unit is located in rows
    short int cLocate; //Where the unit is located in cols
};

#endif /* ARMY_H */

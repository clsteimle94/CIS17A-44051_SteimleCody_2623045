/* 
 * File:   movie.h
 * Author: Cody Steimle
 * Purpose: To store information about movies along with profit.
 * Created on March 27, 2017, 10:33 AM
 */

#ifndef MOVIE_H
#define MOVIE_H

struct Movie{
    string title;          //Title of the movie
    string directr;        //Director
    unsigned int year;     //Year released
    unsigned int length;  //Running Time (in minutes)
    float cost;    //Production costs
    float rev;     //First-year revenues
    float profit;  //Profit Margin
};

#endif /* MOVIE_H */
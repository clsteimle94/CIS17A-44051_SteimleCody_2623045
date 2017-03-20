/* 
 * File:   account.h
 * Author: Cody Steimle
 * Purpose: To store information about the speakers.
 * Created on March 27, 2017, 10:33 AM
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account{
    string name;     //Name of account holder
    string address;  //Street Address, City, State, Zip code
    string phonNum;  //Phone number
    float acntBal;   //Account Balance
    string lastPay;  //Last payment
};

#endif /* ACCOUNT_H */


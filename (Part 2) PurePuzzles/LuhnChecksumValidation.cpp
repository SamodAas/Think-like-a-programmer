#include <iostream>
#include <typeinfo>
using std::cin;
using std::cout;

/* coding Luhn Checksum Validation algorithm according
to steps of problem solving written in the book.*/

/*
STEP 1. Restating the problem:
    perform mathematical operations on a number
STEP 2.
    • Performing operations on every second digit starting from the penultimate
    • Splitting double digit results to separate digits
    • Adding all the number to evalute its mod 10
*/


int main(void){

    char digit;
    int sum;
    int sumEven = 0;
    int sumOdd = 0;
    int i = 1;
    int doubleDigit;
    
    cout << "Enter card number: ";
    digit = cin.get();
    
    while (digit != 10){
        if (digit == 10) break;
        // Checking sum for both cases of card number being odd or even 
        if (i % 2 != 0){
            //splitting and doubling the digit            
            doubleDigit = (digit-'0') * 2;
            sumEven = (doubleDigit >= 10) ? sumEven + 1 + doubleDigit % 10 : sumEven + doubleDigit;
            sumOdd += (digit - '0');
        }
        else {
            doubleDigit = (digit-'0') * 2;
            sumOdd = (doubleDigit >= 10) ? sumOdd + 1 + doubleDigit % 10 : sumOdd + doubleDigit;
            sumEven += (digit - '0');
        }
        digit = cin.get();
        i++;
    }  

    if (i % 2 != 0) sum = sumEven;  
    else sum = sumOdd;

    if (sum % 10 == 0) cout << "valid"; 
    else cout << "invalid";

    return 0;
}
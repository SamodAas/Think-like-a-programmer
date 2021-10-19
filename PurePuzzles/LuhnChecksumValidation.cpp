#include <iostream>
#include <typeinfo>
using std::cin;
using std::cout;

/* coding Luhn Checksum Validation algorithm according
to steps of problem solving written in the book.*/

/*
STEP 1: Restating the problem:
    perform mathematical operations on a number
STEP 2:
    • Performing operations on every second digit starting from the penultimate
    • Splitting double digit results to separate digits
    • Adding all the number to evalute its mod 10
*/


int main(void){

    char digit;
    int sum= 0;
    
    cout << "Enter card number: ";
      
    // reading individual digits to sum without doubleing anything and checking if its % 10 = 0;
    for (int i = 0; i < 6; i++){
        cin >> digit;

        sum += digit - '0';
    }    

    if (sum % 10 == 0){
        cout << "valid"; 
    }
    else {
        cout << sum;
    }
    // Splitting double digit 
    int doubleDigit = digit * 2;
    sum = (doubleDigit >= 10) ? 1 + doubleDigit % 10 : doubleDigit;


    return 0;
}
#include <iostream>
using std::cout;
using std::cin;


// This program provides two options for user: 
// calculate ISBN check digit or 
// verify ISBN number.

void checkDigit();
void verifyNumber();
int main(void){
    cout << "-------------Hello----------------" << std::endl;
    cout << "Press [c] to calculate check digit" << std::endl;
    cout << "Press [v] to verify ISBN number" << std::endl;
    
    char o = cin.get();

    if (o == 'c') {
        cout << "Please enter 12 digit ISBN number without check digit: ";
        checkDigit();
        return 0;
    }
    if (o == 'v') {
        cout << "Please enter 13 digit ISBN number for verification: " ;
        verifyNumber();
        return 0;
    }
    cout << "No such option. The program will now exit...";
    return 1;
}

void checkDigit() {

    // This function checks 12 digit number according to ISBN algorithm to find 
    // what would be the correct check digit for that number.

    char number;
    int sum = 0;
    int len = 0;
    int checkDigit;
    bool oneThree = true;
    
    cin.sync();                 // Clearing the stream
    number = cin.get();
    while (number != 10) {          // Checking if it's the end of the stream (inputed number)
        if (isdigit(number) == false) {         // Checking if input is numeric
            cout << "Enter a number. Program will now exit.";
            return;
        }

        // Every second number is multiplied by three before adding to total.
        if (oneThree == true) {     
            sum += number - '0';
            oneThree = false;
        }
        else {
            sum += (number - '0') * 3;
            oneThree = true;
        }

        len++;
        number = cin.get();  
    }
    if (len != 12) {
        cout << "Wrong number of digits. Program will now exit.";
        return;
    }
    cout << sum;
    checkDigit = 10 - sum % 10;
    cout << "Check digit is " << checkDigit << ".";
    
}

void verifyNumber() {

    // This function works almost exactly like the previous one except
    // for the last operation
    char number;
    int sum = 0;
    int len = 0;
    int lastDigit;
    bool oneThree = true;
    
    cin.sync();
    number = cin.get();
    while (number != 10) {
        if (isdigit(number) == false) {
            cout << "Enter a number. Program will now exit.";
            return;
        }

        if (oneThree == true) {
            sum += number - '0';
            oneThree = false;
        }
        else {
            sum += (number - '0') * 3;
            oneThree = true;
        }
        
        len++;
        number = cin.get();  
    }
    if (len != 13) {
        cout << "Wrong number of digits. Program will now exit.";
        return;
    } 

    if (sum % 10 == 0) {
        cout << "Valid";
        return;
    }
    else {
        cout << "Invalid";
        return;
    }
}
#include <iostream>
#include <cmath>
#include <string>
using std::string;
using std::pow;
using std::cout;
using std::cin;



// This program provides two options for user: 
// convert binary to decimal or vice versa.

// *Due to constraints of int numbers are no longer than 10 digits long.

void binaryToDecimal();
void decimalToBinary();
int main(void){
    cout << "-------------Hello----------------" << std::endl;
    cout << "Press [b] to convert binary number to decimal" << std::endl;
    cout << "Press [d] to voncert decimal number to binary" << std::endl;
    
    char o = cin.get();

    if (o == 'b') {
        cout << "Please enter a binary number: ";
        binaryToDecimal();
        return 0;
    }
    if (o == 'd') {
        cout << "Please enter a decimal number: " ;
        decimalToBinary();
        return 0;
    }
    cout << "No such option. The program will now exit...";
    return 1;
}

void binaryToDecimal() {

    // this function reads input char by char while validating that it's either
    // 1 or 0 and appending it to string binNumber. After it's read, all 1's
    // are multiplied by power according to that digits place in the number.

    char digit;
    int number = 0;
    int len = 0;
    string binNumber;

    cin.sync();
    digit = cin.get();
    while (digit != 10){
        if (isdigit(digit) == false || digit - '0' > 1) {
            cout << "The number should only include digits 1 or 0. The program will now exit.";
            return;
        }
        if (len > 11) {
            cout << "The number should be no longer than 10 digits long. The program will now exit.";
            return;
        }
        binNumber+=digit;
        len++;
        digit = cin.get();
    }
    int strLen = binNumber.length();
    float powCounter = 0;
    
    for (int i = strLen - 1; i >= 0; i--){
        int binDigit = (int)binNumber[i] - '0';
        if (binDigit == 1){
            number += pow(2, powCounter);
        }
        powCounter++;
    }
    cout << "Decimal number: " << number;
    return;
}

void decimalToBinary(){

    // This function validates the input and by looking at the remainder of 
    // the division by 2 of the number inserts 1 or 0 to a binNumber string.
    int number;
    int numLen = 0;

    cin.sync();
    
    if (!(cin >> number)){
        cout << "Invalid input. The program will now exit.";
        return;
    }

    string binNumber;
    string tmpStr;
    
    while (number != 0) {
        if (number % 2 == 1){
            tmpStr = '1';
            binNumber.insert(0, tmpStr);
            number = (number - 1) / 2;
        }
        else {
            tmpStr = '0';
            binNumber.insert(0, tmpStr);
            number /= 2;
        }
    }
    cout << "Binary number: " << binNumber << std::endl;
    return;
}


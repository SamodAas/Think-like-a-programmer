#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using std::string;
using std::pow;
using std::cout;
using std::cin;



// In this program user can choose to input binary, decimal, 
// or hexadecimal number and the program will print all three values.

// *Due to constraints of int numbers are no longer than 10 digits long.

/* Structure: binToDec -> \
                           |
                           | / <- hexToDec
                           ||
                           dec
                           ||
              decToBin <- / |
                            |
                             \ -> decToHex
                    
    In order to avoid writing functions for all possible conversions
    this program will convert any number to decimal first and then
    from decimal to hex or bin. 
*/
int binaryToDecimal();
int hexadecimalToDecimal();
string decimalToBinary(int number);
void decimalToHexadecimal(int number);
int main(void){
    cout << "-------------Hello----------------" << std::endl;
    cout << "Press [b] to insert binary number" << std::endl;
    cout << "Press [d] to insert decimal number" << std::endl;
    cout << "Press [h] to insert hexadecimal number" << std::endl;
    
    char o = cin.get();
    int dec;
    if (o == 'b') {
        cout << "Please enter a binary number: ";

        dec = binaryToDecimal();
        cout << "Decimal: " << dec << std::endl;
        decimalToHexadecimal(dec);
        return 0;
    }
    if (o == 'd') {
        cout << "Please enter a decimal number: " ;
        int number;
        
        cin.sync();        
        if (!(cin >> number)){
            cout << "Invalid input. The program will now exit.";
            return 1;
        }

        cout << "Decimal: " << number << std::endl;
        cout << "Binary: " << decimalToBinary(number) << std::endl;
        decimalToHexadecimal(number);
        return 0;
    }
    if (o == 'h') {
        cout << "Please enter a hexadecimal number (up to 7 digits): " ;

        dec = hexadecimalToDecimal();
        cout << "Binary: " << decimalToBinary(dec) << std::endl;
        decimalToBinary(dec);
        return 0;
    }
    cout << "No such option. The program will now exit...";
    return 1;
}


int binaryToDecimal() {

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
            return 1;
        }
        if (len > 11) {
            cout << "The number should be no longer than 10 digits long. The program will now exit.";
            return 1;
        }
        binNumber+=digit;
        len++;
        digit = cin.get();
    }
    int strLen = binNumber.length();
    float powCounter = 0;
    
    cout << "Binary: " << binNumber << std::endl;

    for (int i = strLen - 1; i >= 0; i--){
        int binDigit = (int)binNumber[i] - '0';
        if (binDigit == 1){
            number += pow(2, powCounter);
        }
        powCounter++;
    }
    
    return number;
}

int hexadecimalToDecimal(){
    string number;
    char *end;

    cin >> number;
    int hexLen = number.length();

    // Validating length
    if (hexLen > 7){
        cout << "The number is too long. The program will now exit...";
        return 1;
    }
    
    // Validating that input is indeed hexadecimal number
    for (int i = 0; i < hexLen; i++){
        if (std::isxdigit(number[i]) == 0) {
        cout << "The input is not hexadecimal number. The program will now exit...";
        return 2;
        }
    }
    
    char validatedNumber[hexLen+1];
    strcpy(validatedNumber,number.c_str());

    // Converting input to decimal number.
    long int decNumber = strtol(validatedNumber, &end, 16);
    cout << "Decimal: " << decNumber << std::endl;
    
    return (int)decNumber;
}

string decimalToBinary(int number) {
    
    // This function validates the input and by looking at the remainder of 
    // the division by 2 of the number inserts 1 or 0 to a binNumber string.
    
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

    return binNumber;
}

void decimalToHexadecimal(int number){
    
    cout << "Hexadecimal: " << std::hex << number <<std::endl;
}
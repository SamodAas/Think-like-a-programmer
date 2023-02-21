#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::pow;


// In order to really work without a hitch, input validation should be implemented at each step.

int main() {
    int base_from;
    int base_to;
    int dec = 0;
    string number;
    string converted_number = "";
    char remainder_translated;
    int remainder;

    cout << "enter the base from which to convert to: ";
    cin >> base_from;
    cout << "enter the base to which to convert to: ";
    cin >> base_to;
    cout << "enter number to convert: ";
    cin >> number;

    int num_len = number.size();
    
    // to decimal
    for (int i = 0; i < num_len; i++){
        if(number[i]-48>9){
            dec += (number[i]-55)*pow(base_from, num_len-i-1);
        } else {
        dec += (number[i]-48)*pow(base_from, num_len-i-1);
        }
    }
    cout << dec<<"\n";
    // to the base wanted
    while (dec!=0){
        remainder = dec%base_to;
        dec = (dec - remainder)/base_to;

        if (remainder > 9){
            remainder_translated = '@' + (remainder-9);
            converted_number = remainder_translated + converted_number;
        } else {
        converted_number=(std::to_string(remainder))+converted_number;
        }
    }
    cout << converted_number;
}
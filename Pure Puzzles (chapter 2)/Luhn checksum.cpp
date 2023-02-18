#include <iostream>
#include <string>
using std::cout;
using std::cin;

// Luhn checksum formula is used to check identification numbers. 
// Accodring to this formula, when we take every second number, double it,
// and add all the digits of the new number, valid identification number 
// should be divisible by 10.

// The task requires that we dont know the length of the number and process each digit separately

int main(){
    cout << "Please enter your identification number: ";
    char number;
    int odd_sum = 0;
    int even_sum = 0;
    int pos = 1;
    number = cin.get();

    while (number != 10){
        // Here we have two different paths, calculating sum in case the whole number is even or odd
        if (pos%2 == 0){
            even_sum += number -'0'; 
            if (number -'0'> 4){
                odd_sum += ((number- '0')*2)%10 + 1;
            } else {
                odd_sum += (number - '0') *2;
            }
            pos += 1;
        } else {
            odd_sum += number - '0';
            if (number - '0'> 4){
                even_sum += ((number- '0')*2)%10 + 1;;
            } else {
                even_sum += (number - '0') *2;
            }
            pos +=1;
        }
        number = cin.get();
    }

    int sum;
    // cheksum
    if ((pos-1)%2==0){
        sum = even_sum;
    } else {
        sum = odd_sum;
    }

    if (sum%10 == 0){
        cout << "checksum valid";
    } else {
        cout << "checksum invalid";
    }
    
}

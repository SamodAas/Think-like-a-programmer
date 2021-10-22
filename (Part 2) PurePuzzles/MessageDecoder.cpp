#include <iostream>
using std::cout;
using std::cin;

// Problem solving 

/*
STEP 1. Restating the problem:
    perform operations on numbers depending on state
STEP 2. Dividing the problem:
    • Tracking the state
    • Reading integers separated by coma
    • performing operations depending on state
    • Printing result
*/
int main (void){


    cout << "Enter a number: ";
    char digit;
    char letter;
    char state = 'U';

    while (digit != 10){
        digit = cin.get();
        int number = digit - '0';
        digit = cin.get();
        while (digit != 10 && digit != 44){                
            number = number * 10 + (digit - '0');
            digit = cin.get();
        }
        if (state == 'U'){
            number = number % 27;
            letter = number + 'A' - 1;
            if (number == 0) {
                state = 'L';
                continue;
            }
        }
        if (state == 'L'){
            number = number % 27;
            letter = number + 'a' - 1;
            if (number == 0) {
                state = 'P';
                continue;
            }
        }
        if (state == 'P'){
            number = number % 9;
            switch (number){
                case 1: letter = '!'; break;
                case 2: letter = '?'; break;
                case 3: letter = ','; break;
                case 4: letter = '-'; break;
                case 5: letter = ' '; break;
                case 6: letter = ';'; break;
                case 7: letter = '"'; break;
                case 8: letter = '\''; break;
            }
            if (number == 0) {
                state = 'U';
                continue;
            }
        }           
        cout << letter;
    }    
}
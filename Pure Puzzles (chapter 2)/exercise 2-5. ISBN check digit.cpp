#include <iostream>
#include <string.h>
using std::cout;
using std::cin;

// Checking if number length is valid
bool num_len(std::string number, int length){
    int len = number.size();
    
    if (len == length) return true;
    else {
        return false;
    }
}
int main(){
    cout << "To check if ISBN is valid press (1) \nTo see generate check digit press (2):\n";
    std::string option;
    std::cin >> option;
    int validator_number = 0;
    
    if (option == "1"){
        std::string isbn;
        
        cout << "please enter ISBN number: ";
        cin >> isbn;
        
        if (!num_len(isbn,13)) {
            cout << "The number should have 13 digits! program exiting...";
            return 1;
        }
        // Tripling every second number
        for (int i = 1; i < 13; i+=2){
            validator_number+= 3*((int) isbn[i] - '0');
        }
        // Adding rest of digits
        for (int i = 0; i <=12; i+=2){
            validator_number+= (int) isbn[i] - '0';
        }
        if (validator_number%10==0){
            cout << "Number is valid";
        } else cout << "Number invalid";

    } else if (option == "2"){
        std::string isbn_without_check_digit;
        cout << "please enter 12 digits to get 13th: ";
        cin >> isbn_without_check_digit;
        if (!num_len(isbn_without_check_digit,12)){
            cout << "The number should have 12 digits! program exiting...";
            return 1;
        }
        // Tripling every second number
        for (int i = 1; i < 12; i+=2){
            validator_number+= 3*((int) isbn_without_check_digit[i] - '0');
        }
        // Adding rest of digits
        for (int i = 0; i <12; i+=2){
            validator_number+= (int) isbn_without_check_digit[i] - '0';
        }
        cout << 10 - validator_number%10;
    } else {
        cout << "Wrong option, program exiting....";
    }


}
#include <iostream>
#include <string>
using std::cout;
using std::cin;


int main(){
    int decoding_mode[3] = {true, false, false};
    cout << "enter numbers separated by comas: ";
    char coded_text;
    coded_text = cin.get();
    int digit= 0;
    std::string final_text = "";
    char punctuation_marks[9] = {"!?,. ;\'\""};

    while ( coded_text != 10)
    {   
        // Getting whole number into int
        while (coded_text != ',' && coded_text != 10)
        {   
            if (digit != 0) digit*=10;
            digit+=(int) coded_text - '0';  
            coded_text = cin.get();      
        }
        // checking the decoding mode and taking next steps
        if (decoding_mode[0]== true){
            if (digit%27==0){
                decoding_mode[0] = false;
                decoding_mode[1] = true;
            } else {
                final_text += digit%27 + '@';
            }
        } else if (decoding_mode[1] == true){
            if (digit%27==0){
                decoding_mode[1] = false;
                decoding_mode[2] = true;
            } else {
                final_text += digit% 27 + '`';
            }
        } else if (decoding_mode[2] == true){
            if (digit%9==0){
                decoding_mode[2] = false;
                decoding_mode[0] = true;
            } else {
                final_text += punctuation_marks[digit%9 -1];
            }
        }

        if (coded_text != 10) coded_text = cin .get();
        digit = 0;
       
    }
    cout << final_text;    

}


// Steps to solve the task:
// read and separate numbers by come
// turn numbers to int and process them
// converting ints to chars
// figure out the system of tracking the decoding mode
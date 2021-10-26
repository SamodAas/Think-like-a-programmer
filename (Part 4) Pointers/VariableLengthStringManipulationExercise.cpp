#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::string;

// creating substring from a char pointer.
typedef char * arrayString;

arrayString subString(arrayString originalString, int startPosition, int length){

    arrayString subString = new char[length]; 

    for (int i = 0; i <= length; i++){
        subString[i] = originalString[startPosition + i];
    }
    return subString;
}



int main(void){


    arrayString test = new char[20];
    strcpy(test, "Laba diena su vistiena.");

    arrayString subStringTest = new char[50];
    subStringTest = subString(test, 5, 6);
    cout << subStringTest;
    
    
    return 0;
}
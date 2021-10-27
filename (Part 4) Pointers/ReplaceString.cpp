#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::string;

// replacing parts of string with another.

typedef char * arrayString;

void replaceString(arrayString source, arrayString target, arrayString replaceText) {
    int i = 0;
    bool found = true;
    int ReplaceTextLen = strlen(replaceText);
    int targetLen = strlen(target);
    

    while (source[i] != 0){
        found = true;
        
        if (source[i] == target[0]){ // First char of target is found in source
           for (int j = 1; j < targetLen; j++){     // Checking if following chars are the same
               if (source[i+j] != target[j]) {
                   found = false;
                   break;
               }
           }
           if (found == true){
               for (int j = 0; j < ReplaceTextLen; j++){
                   source[i+j] = replaceText[j];
                }       
            }
        }
        i++; 
    }
    return;    
}



int main(void){


    arrayString test = new char[20];
    strcpy(test, "Laba diena su vistiena.");

    arrayString target = new char [20];
    strcpy(target, "ie");

    arrayString replacementString = new char [20];
    strcpy(replacementString, "uo");

    replaceString(test, target, replacementString);   
    
    cout << test;
    
    return 0;
}
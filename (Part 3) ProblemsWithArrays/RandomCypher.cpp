#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

int main(void){
    char letterArray[26] = {'S','A','D','F','G','H','J','K','L','O','I','U','Y','P','T','R','E','W','Q','Z','X','C','V','B','N','M'};
    char cypherArray[26];
    memset(cypherArray, '0', 26);   // Changing all values to 0
    
    std::srand(time(NULL));     // setting seed value for rand()

    for (int i = 0; i < 26; i++){

        int r = std::rand() % 26;
        char empty = '0';
        
        // Upon finding empty index (char '0') in cypherArray we fill it with letterArray[i]
        if (cypherArray[r] == empty) {
            cypherArray[r] = letterArray[i];
        }
        else {
            while (cypherArray[r] != empty) {
                r = std::rand() % 26;
            }
            cypherArray[r] = letterArray[i];
        }
        
    }

    char alphabetArray[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char c;
    string plainText = "abSomething something I really do like something something.";
    string decodedText = "";

    int len = plainText.length();
    string cypherText = "";

    for (int i = 0; i < len; i++){          // Loop through plain text
        if (isalpha(plainText[i])!=0){      // checking if its a letter
            c = toupper(plainText[i]);      // if it is, making it uppercase
            for (int j = 0; j < 26; j++) {  // loop through alphabet to find index of cypher letter
                if (c == alphabetArray[j]) {
                    cypherText += cypherArray[j];   // Strangely it didn't allow to assign cypherArray char to cypherText[i];
                    break;
                }
            }
        }
        else {
            cypherText += plainText[i];
        }
    }

    cout << cypherText << std::endl;

    // decoding cyphered text, The only difference is that it decodes
    // back to uppercase letters
    
    int j = 0;
    for (int i = 0; i < len; i++){
        if (isalpha(cypherText[i]) != 0) {
            for (j = 0; j < 26; j++) {
                if (cypherText[i] == cypherArray[j]) {
                    decodedText += alphabetArray[j];
                    break;
                }
            }
        }
        else {
            decodedText += cypherText[i];
        }
    }
    cout << decodedText;
    return 0;
}
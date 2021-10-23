#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

int main(void){

    char cypherArray[26] = {'S','A','D','F','G','H','J','K','L','O','I','U','Y','P','T','R','E','W','Q','Z','X','C','V','B','N','M'};
    char alphabetArray[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char c;
    string plainText = "abSomething something I really do like something something.";

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
            cypherText[i] = plainText[i];
        }
    }

    cout << cypherText << std::endl;
    return 0;
}
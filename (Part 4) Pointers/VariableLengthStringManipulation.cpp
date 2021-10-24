#include <iostream>
using std::cin;
using std::cout;
using std::string;

// This task is an example to be done along with the book.
typedef char * arrayString;

int countLength(arrayString text){
    int length = 0;
    while (text[length] != 0){
        length++;
    }
    return length;
}
void append(arrayString& text, char c){
    int length = countLength(text);

    arrayString newText = new char[length+1]; // for some reason length+1 is enough, but it shouldn't be.
    for (int i = 0; i < length; i++){
        newText[i] = text[i];
    }
    newText[length] = c;
    newText[length + 1] = 0;

    delete[] text;
    text = newText;   

    return;
}

void concatenate(arrayString& string1, arrayString string2){
    int length1 = countLength(string1); //if the word is test then length1 = 4 (in this case, after calling append in main(), length would be 5)
    int length2 = countLength(string2); //if the word is bed then length2 = 3
    arrayString newText = new char[length1 + length2 +1 ]; // we need 8 chars to have testbed0

    for (int i = 0; i < length1; i++){
        newText[i] = string1[i];
    }
    for (int i = length1; i < length1 + length2; i++){
        newText[i] = string2[i - length1];
    }
    newText[length1 + length2] = 0;
    delete[] string1;
    string1 = newText;

    return;
}

char characterAt(arrayString text, char c){
    return text[c];
}

int main(void){


    arrayString test = new char[5];
    test[0] = 't';
    test[1] = 'e';
    test[2] = 's';
    test[3] = 't';
    test[4] = 0;
    append(test, '!');
    cout << "append result: " << test << std::endl;
    
    arrayString test2 = new char[4];
    test2[0] = 'b';
    test2[1] = 'e';
    test2[2] = 'd';
    test2[3] = 0;
    concatenate(test, test2);
    cout << "concatenate result: " << test;
    return 0;
}
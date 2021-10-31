#include <iostream>
using std::cin;
using std::cout;
using std::string;

class variableLengthString{
public:
    variableLengthString(char c);                                                             // Constructors
    variableLengthString();
    int getStringLength();                                                                    // Methods
    int getStringLength(string string);                                               
    void append(char c);
    void concatenate(string string);
    char characterAt(int index);
    char operator[](int index);
private:
    int _length;
    char *_vlString;
};

// Constructors
variableLengthString::variableLengthString(char c){
    _vlString = new char[2];
    _vlString[0] = c;
    _vlString[1] = 0;
    _length = 2;
}
variableLengthString::variableLengthString(){
    _vlString = new char[1];
    _vlString[0] = 0;
    _length = 1;
}
// Functions
void variableLengthString::append(char c){

    char *newString = new char[_length+1];
    int i = 0;

    while (_vlString[i] != 0){
        newString[i] = _vlString[i];
        i++;
    }

    newString[i] = c;
    newString[i+1] = 0;
    delete[] _vlString;
    _vlString = newString;
    _length++;
}
int variableLengthString::getStringLength(){
    int length = 0;
    while(_vlString[length] != 0){
        length++;
    }
    return length;
}
int variableLengthString::getStringLength(string string){
    int length = 0;
    while(string[length] != 0){
        length++;
    }
    return length;
}
char variableLengthString::characterAt(int index){
    return _vlString[index];
}
void variableLengthString::concatenate(string string){

    int stringLength2 = getStringLength(string);
    char *newChar = new char[_length + stringLength2 - 1];
    int i = 0;                                     // _vlString (or original) string index which will continue to be incremented throught function
    int j = 0;                                     // second string index

    while (_vlString[i] != 0) {
        newChar[i] = _vlString[i];
        i++;
    }
    while (string[j] != 0) {
        newChar[i] = string[j];
        i++;
        j++;
    }
    newChar[i] = 0;
    delete[] _vlString;
    _vlString = newChar;
    cout << newChar;
    _length = _length + stringLength2 -1;
}
char variableLengthString::operator[](int index){
    return characterAt(index);
}

int main(void){
   variableLengthString string1;
   
   string1.append('c');
   string1.append('e');
   string1.append('s');
   string1.append('k');
   string1.append('i');
   cout << string1.getStringLength();
   string test = " Test String";
   string1.concatenate(test);
   cout << "\n" << string1[2];
   return 0;
}
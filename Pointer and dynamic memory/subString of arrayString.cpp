#include <iostream>
using std::cout;
using std::cin;
using std::string;


// Task is to write a function for getting a substring and function to replace target text with smth else.


typedef char* arrayString;

arrayString subString(arrayString og, int index, int length){
    arrayString newString = new char[length+1];
    for(int i = index;i<index+length;i++){
        newString[i-index] = og[i];
    }
    newString[length] = 0;
    return newString;
    
}



int length(arrayString str){
    int count = 0;
    while (str[count]!= 0) {
        count++;
    }
    return count;
}


void addChar(arrayString& sc, char c){
    int oldLenght = length(sc);
    arrayString newString = new char[oldLenght+2];

    for (int i = 0; i < oldLenght;i++){
        newString[i] = sc[i];
    }
    newString[oldLenght] = c;
    newString[oldLenght+1]= 0;
    delete[] sc;
    sc = newString;
}


void concatenate(arrayString& sc, arrayString addedString){
    int ogLength = length(sc);
    int addedLength = ogLength+length(addedString);

    arrayString newString = new char [addedLength+ogLength];
    for (int i = 0; i < ogLength; i++){
        newString[i] = sc[i];
    }

    for (int i = 0; i <addedLength; i++){
        newString[i+ogLength] = addedString[i];
    }
    newString[addedLength+ogLength] = 0;

    delete[] sc;
    sc = newString;
}

void replaceString(arrayString& sc, arrayString target, arrayString replaceText){
    int strLength = length(sc);
    int targetLength = length(target);
    int replaceLength = length(replaceText);
    bool targetFound = true;

    arrayString final = new char[1];
    final[0]=0;
    
    

    for (int i = 0; i < strLength; i++){
        if (sc[i]==target[0]){
            for (int j = 1; j <targetLength; j++){
                if (sc[i+j]!=target[j]){
                    targetFound = false;
                    continue;
                }
            }
            if (targetFound){
                concatenate(final, replaceText);
                i+=targetLength;
            }
        targetFound = true;
        }
        else{
            addChar(final, sc[i]);
        }
     
}
    cout << final;
}

int main(){
    arrayString word = new char[9];
    arrayString test = new char[3];
    test[0]= 'j',test[1] = 'o',test[2] = 0;
    string smth = "abcdabgh";
    for (int i = 0; i <9; i++){
        word[i] = smth[i];
    }
    word[9]=0;
    concatenate(word, test);
    replaceString(word, "ab", "qwr");
    
    

}
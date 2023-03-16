#include <iostream>
using std::cout;
using std::cin;
using std::string;

typedef char* arrayString;

arrayString subString(arrayString og, int index, int length){
    arrayString newString = new char[length+1];
    for(int i = index;i<index+length;i++){
        newString[i-index] = og[i];
    }
    newString[length] = 0;
    return newString;
    
}



int main(){
    arrayString word = new char[9];
    string smth = "abcdefgh";
    for (int i = 0; i <9; i++){
        word[i] = smth[i];
    }
    word[9]=0;
    cout << subString(word, 3, 4);
    
    

}
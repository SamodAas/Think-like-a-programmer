#include <iostream>
#include <typeinfo>
using std::cout;

//implementation or arrayString and its function where 
//the first element in the array is its length and the second 
//element is the first character of the word'''

typedef char* arrayString;

void append(arrayString& sc, char c){
    arrayString newString = new char[int(sc[0])+2];
    for (int i = 1; i <= sc[0];i++){
        newString[i] = sc[i];
    }
    
    newString[0] = (int)sc[0]+1;
    newString[newString[0]] = c;
    delete[] sc;
    sc = newString;
}

void concatenate(arrayString& sc, arrayString addedString){
    arrayString newString = new char[(int)sc[0]+(int)addedString[0]-1];
    
    newString[0] = (int)sc[0]+(int)addedString[0];

    for (int i = 1; i <= (int)sc[0]; i++){
        newString[i] = sc[i];
    }

    for (int i = 1; i <= (int)addedString[0]; i ++){
        newString[(int)sc[0]+i] = addedString[i];
    }

    delete[] sc;
    sc = newString;   
}

char charAt(arrayString sc, int index){
    return sc[index];
}
int main(){
    arrayString str = new char[5];
    str[0] = 4, str[1] = 't', str[2] = 'e', str[3] = 's', str[4] = 't';
    
    // Append function

    cout <<"before:\nLength: " <<(int)str[0]<<"\nstring: " << str;    
    append(str, '!');
    cout <<"\n\nafter:\nLength: " <<(int)str[0]<<"\nstring: " << str;
    
    // Concatenate function

    arrayString addedString = new char[9];
    addedString[0] = 8;
    addedString[1] = ' ', addedString[2] = 's', addedString[3] = 'u', addedString[4] = 'c', addedString[5] = 'c', addedString[6] = 'e', addedString[7] = 's', addedString[8] = 's';

    concatenate(str, addedString); 

    cout <<"\n\nafter concatenation:\nLength: " <<(int)str[0]<<"\nstring: " << str;

    //charAt function

    cout << "\n" << charAt(str, 5);
}
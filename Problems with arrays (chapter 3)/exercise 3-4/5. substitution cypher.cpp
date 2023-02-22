// funtion 1 takes plaintext and uses substitute cypher to encode 
// plaintext. function 2 takes encoded text and outputs plaintext back.

#include <iostream>
using std::cout;
using std::cin;
using std::string;

const string cALPHABET = "AQZSWXDECFRVGTBHYNJUMKIOLP";
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string encode(string plt){
    string encoded_txt;
    int string_len = plt.size();
    for (int i = 0; i < string_len; i++){
        if (ispunct(plt[i])|| plt[i] == ' '){
            encoded_txt+=plt[i];
        } else {
            encoded_txt+=cALPHABET[plt[i]-'A'];
        }
    }
    return encoded_txt;
}
string decode(string plt){
    int str_len = plt.size();
    string decoded_txt="";


    for (int i = 0; i <str_len;i++){
        if (ispunct(plt[i])|| plt[i] == ' '){
            decoded_txt+=plt[i];
            continue;}
        for (int j = 0; j < 26; j++){
            if (cALPHABET[j] == plt[i]){
                decoded_txt+=ALPHABET[j];
                continue;
            }
        }
    }
    return decoded_txt;
}

int main(){
    string pltxt = "LABAS KAIP SEKAS? KA VEIKI, KODEL VEIKI IR PAN";
    string encoded_txt = encode(pltxt);
    cout << encoded_txt<<"\n";
    cout << decode(encoded_txt);



}
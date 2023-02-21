#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::pow;

int bin_to_dec(string bin){
    int len = bin.size();
    int decim;

    if (bin[len-1] == '1'){
        decim = 1;
    } else decim = 0;

    for (int i = len-2; i >= 0; i--){
        if (bin[i] == '1') {
            decim += pow(2,len-i-1);
        }
    }
    return decim;
}

string bin_to_hex(string bin){
    int length = bin.size();
    string bin_to_convert;
    string hex = "";

    // Adding zeros to have a number which divides from 4
    while (length%4!=0){
        bin="0"+bin;
        length++;
    }
    // Taking each four binary numbers to convert a to hex
    // number and adding them together into a string
    while(bin.size()!=0){
        bin_to_convert = bin.substr(0,4);
        bin.erase(0,4);
        int dec = bin_to_dec(bin_to_convert);

        if (dec > 9){
            hex+= '@' + (dec-9);
        } else {
            hex+= dec + '0';
        }
    }
    return hex;
}

string dec_to_bin(string dec){
    int decim = stoi(dec);
    string bin = "";
    while (decim!=0){
            if (decim%2==1) bin="1"+bin;
            else {bin="0"+bin;}
            decim/=2;
        }
    return bin;
}

string dec_to_hex(string dec) {
    string hex = "";
    int decim = stoi(dec);
    int remainder;
    
    // we use remainder as first hex digit symbol and then divide the number (with remainder substracted)
    // from 16 just to do the same thing again
    while (decim!=0){
        remainder = decim%16;
        if (remainder > 9){
            char remainder_translated = '@' + (remainder-9);
            hex = remainder_translated+ hex;
        } else {
            char remainder_transltaed = remainder + '0';
            hex = remainder_transltaed + hex;
        }
        decim=(decim - (decim%16))/16;
    }
    return hex;
}

int hex_to_dec(string hex){
    int dec = 0;
    int hex_len = hex.size();

    for (int i = 0; i < hex_len; i++){

        if (isdigit(hex[i])){
            dec+=(hex[i]-48)*pow(16,hex_len-1-i); 
        } else {
            dec+= (hex[i]-55)*pow(16, hex_len-i-1);
        }
        
    }
    return dec;
}

string hex_to_bin(string hex){
    // cheating a little
    string bin = std::to_string(hex_to_dec(hex));
    bin = dec_to_bin(bin);
    return bin;
}



int main(){
    string base_to_convert_from;
    string base_to_convert_to;
    string number;

    cout << "choose the base of your number: (b) - bin, (d) - dec, (h) - hex:\n";
    cin >> base_to_convert_from;
    
    if (base_to_convert_from!="b" && base_to_convert_from!="d" && base_to_convert_from!="h"){
        cout << "no such option.";
        return 1;
    }

    cout << "convert to:  (b) - bin, (d) - dec, (h) - hex:\n";
    cin >> base_to_convert_to;
    if (base_to_convert_to!="b" && base_to_convert_to!="d" && base_to_convert_to!="h"){
        cout << "no such option.";
        return 1;
    }
    cout << "please type in a number: ";
    cin >> number;

    
    if (base_to_convert_from == "b"){
        if (base_to_convert_to == "d"){
            cout << bin_to_dec(number);
        } else if (base_to_convert_to == "h"){
            cout << bin_to_hex(number);
        }
    } else if (base_to_convert_from == "d"){    
        if (base_to_convert_to == "b"){
            cout << dec_to_bin(number);
        } else if (base_to_convert_to == "h"){
            cout << dec_to_hex(number);
        }
    } else if (base_to_convert_from == "h"){
        if (base_to_convert_to == "b"){
            cout << hex_to_bin(number);
        } else if (base_to_convert_to == "d"){
            cout << hex_to_dec(number);
        }
    }
    



}
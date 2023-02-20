#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::string;
using std::pow;


int main(){
    string bin;
    string option;
    int decim;

    cout << " (b) for binary to dec and (d) for dec to binary: ";
    cin >> option;

    if (option == "b"){
        cout << "enter binary number: ";
        cin >> bin;
        int len = bin.size();

        if (bin[len-1] == '1'){
            decim = 1;
        } else decim = 0;

        for (int i = len-2; i >= 0; i--){
            if (bin[i] == '1') {
                decim += pow(2,len-i-1);
            }
        }
        cout << decim;
    }
    if (option == "d"){
        cout << "enter decimal number: ";
        cin >> decim;
        // Finding binary number by dividing number by 2 and checking if there's a reminder
        while (decim!=0){
            if (decim%2==1) bin="1"+bin;
            else {bin="0"+bin;}
            decim/=2;
        }
        cout << bin;
    }
}
#include <iostream>
using std::cout;


int main(){

    for (int i = 1; i < 5; i++){
        for (int k = 0+i; k < 4; k++){
            cout << " ";
        }
        for (int j = 0; j < i*2; j++){
            cout << "#";
        }
        cout <<"\n";
    }
    for (int i = 4; i > 0; i--){
        for (int k = i; k < 4; k++){
            cout << " ";
        }
        for (int j = 0; j < i*2; j++){
            cout << "#";
        }
        cout <<"\n";
    }        
    }

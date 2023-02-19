#include <iostream>
using std::cout;

int main(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j <i; j++){             // Pirmi tarpai
            cout << " ";
        }
        for (int j = 0; j <= i; j++){           // Pirmi hash'ai
            cout << "#";
        }
        for (int j = 0; j < 12 - 4*i; j++){      // Viduriniai tarpai
            cout << " ";
        }
        for (int j = 0; j <= i; j++){           // Antri hash'ai
            cout << "#";
        }        
        cout <<"\n";
    }
    // Toliau tas pats tik is kitos puses

    for (int i = 0; i < 4; i++){
        for (int j = 0+i; j < 3; j++) {
            cout << " ";
        }
        for (int j = 0; j <4-i;j++){
            cout <<"#";
        }
        for (int j = 0; j < i*4; j++){
            cout << " ";
        }
        for (int j = 0; j <4-i;j++){
            cout <<"#";
        }
        cout << "\n";
    }
}

// Kiti variantai, parasyt funkcija su simbolio ir ilgio parametru, ir panaudot for loop iskviest tas funkcijas?
// Dar kitas variantas matrica 1-0



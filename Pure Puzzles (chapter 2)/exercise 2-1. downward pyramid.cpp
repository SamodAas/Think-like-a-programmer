#include <iostream>
using std::cout;
using std::cin;

int main(){
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < i; k++){
                cout << " ";
            }
        for (int j = 8-i*2; j > 0; j--){            
            cout << "#";
        }
    cout << "\n";
    }
}

//The goal is: 
//########
// ######
//  ####
//   ##
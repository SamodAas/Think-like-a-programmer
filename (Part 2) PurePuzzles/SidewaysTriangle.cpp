#include <iostream>
using std::cin;
using std::cout;

int main(void){
    for (int i = 0; i < 7; i++) {
        for (int j = 4; j > abs(3-i); j--){
            cout << "#";
        }   
        cout <<"\n";
    }
    return 0;
}

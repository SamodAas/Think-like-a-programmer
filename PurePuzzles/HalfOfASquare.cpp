#include <iostream>
using std::cin;
using std::cout;

int main(void){
    for (int i = 5; i > 0; i--) {
        for (int j = i; j > 0; j--){
            cout << "#";
        }   
        cout <<"\n";
    }
    return 0;
}

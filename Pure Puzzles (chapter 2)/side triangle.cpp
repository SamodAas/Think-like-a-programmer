#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int size_of_pyramid = 4;
    
    for (int i = 0; i <= size_of_pyramid*2-1; i++){
        for (int j = abs (size_of_pyramid-i); j < size_of_pyramid; j++){
            cout << "#";
        }
    cout << "\n";
    }
}
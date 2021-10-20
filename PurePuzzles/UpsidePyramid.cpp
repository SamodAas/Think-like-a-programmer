#include <iostream>
using std::cout;
using std::cin;

/* printing a picture of upside pyramid:
########
 ######
  ####
   ##
*/

int main(void){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < i; j++){
            cout << " ";
        }
        for (int k = 0; k < 8 - i * 2; k++){
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
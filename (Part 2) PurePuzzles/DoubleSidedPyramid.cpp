#include <iostream>
using std::cin;
using std::cout;

/* printing a picture of double sided pyramid:
   ##
  ####
 ######
########
########
 ######
  ####
   ##
*/

int main(void){

    for (int i = 0; i <= 8; i++){
        if (i == 4) continue;
        for (int j = 0; j < abs(4-i); j++){
            cout << " ";
        }
        for (int k = 10; k > 2 * abs(4-i);k--){
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
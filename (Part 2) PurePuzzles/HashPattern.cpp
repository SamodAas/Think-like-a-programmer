#include <iostream>
using std::cin;
using std::cout;



/* printing a picture of double sided pyramid:

#            #          |   
 ##        ##           |   
  ###    ###            |   
   ########             |   
   ########             |   
  ###    ###            |   
 ##        ##           |   
#            #          |   

*/

int main(void){

    for (int i = 0; i <= 8; i++){
        if (i == 4) continue;

        // We need from 0 to 4 and back again spaces (when i = 0, then it's zero 
        //spaces and later when i = , it's 4 spaces, but it gets ignored as needed)
        for (int f = 4; f > abs(4 - i); f--){
            cout << " ";
        }

        // we need from one to four hashes
        for (int h = 5; h > abs(4 - i); h--){
            cout << "#";
        }

        //we need from 12 to 0 spaces with decrement of four
        for(int t = 12; t > (4 - abs(4 - i))*4; t--){
            cout << " ";
        }
        for (int h = 5; h > abs(4 - i); h--){
            cout << "#";
        }        
        cout << std::endl;
    }

    return 0;
}
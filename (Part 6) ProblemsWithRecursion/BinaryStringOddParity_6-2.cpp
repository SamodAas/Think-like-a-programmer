#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// These (iterative and recursive) functions finds whether binary string has odd parity or not (odd amount of 1's)
bool iterativeSolution(int arr[], int len);
bool recursiveSolution(int arr[], int len);

int main(void){

    int oddBinaryString[10] = {1,0,0,1,1,1,0,1,0,0};  
    int evenBinaryString[10] = {1,0,0,1,1,1,0,1,1,0};
    int len = 10;
    
    //iterative calls
    if (iterativeSolution(oddBinaryString, len)) cout << "odd\n";
    else cout << "even\n";
    if (iterativeSolution(evenBinaryString, len)) cout << "odd\n";
    else cout << "even\n";
    //recursive calls
    if (recursiveSolution(oddBinaryString, len)) cout << "odd\n";
    else cout << "even\n";
    if (recursiveSolution(evenBinaryString, len)) cout << "odd\n";
    else cout << "even\n";
    return 0;
}

bool iterativeSolution(int arr[], int len){
    int count = 0;
    for (int i = 0; i < len; i++){
        if (arr[i] == 1) count++;
    }
    if (count % 2 == 1) return true;
    else return false;
}

bool recursiveSolution(int arr[], int len){

    if (len == -1) return false;    // end of recursive function

    if (arr[len-1] == 1){           
        if (recursiveSolution(arr,len-1)) return false;
        else return true;
    }
    else return recursiveSolution(arr, len-1);
}

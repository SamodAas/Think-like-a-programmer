#include <iostream>
using std::cout;
using std::cin;


// This program will find mode of an array by incrementing 
// the index which is equal to the value in original array.
// For example, if original array index 2 value is 4, then 
// modeCountArray[4] will be increased. Finally the biggest 
// number in modeCountArray will be the mode of the original array.

const int ARRAY_SIZE = 12;

int main(void){
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    int modeCountArray[11] = {0};
    int mode=0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        modeCountArray[surveyData[i]]++;
    }
    
    for (int i = 0; i < 12; i++){
        if (modeCountArray[i]>mode) mode = i;
    }
    cout << mode;
    return 0;
}
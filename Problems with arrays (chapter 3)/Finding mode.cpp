#include <iostream>
using std::cout;

int main() {
    const int ARRAY_SIZE = 10;
    int surveyData[ARRAY_SIZE] = {1,2,4,6,6,6,7,8,8,8};
    int value_counter_array[ARRAY_SIZE]={0};
    int mode = 0;
    
    // Two simple options here:
    // either sort and then check which value repeats 
    // the most times before different value, OR
    // creating a new array which indexes store how many time particular value has repeated.
    // However the second option seems to be less resource consuming as well as involving
    // less complexity. The first option is also explored in the book.

    for (int i = 0; i < ARRAY_SIZE; i++){
        value_counter_array[surveyData[i]]++;
    }

    for (int i = 0; i < ARRAY_SIZE; i++){
        if (value_counter_array[i] > mode){
            mode = i;
        }
    }   
    cout << mode;
}
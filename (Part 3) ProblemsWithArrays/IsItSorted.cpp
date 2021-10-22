#include <iostream>


// bool function which checks if array is sorted.
bool isArray(int a[], int len){
    bool increasing = true;
    bool decreasing = true;
    for (int i = 1; i < len ; i++){
        if (a[i] < a[i-1]) {
            increasing = false;
            break;
        }
    }
    
    for (int i = 1; i < len ; i++){
        if (a[i] < a[i-1]) {
            decreasing = false;
            break;
        }
    } 

    if (!increasing && !decreasing) return false;

    return true;
}

int main(void){

    int array2[6] = {1,2,5,8,12,19};
    int array1[6] = {1,5,79,64,1,3};
    if (!isArray(array1, 6)) std::cout << "array 1 is not sorted\n";
    else {
        std::cout << "array 1 is sorted\n";
    }
    
    if (!isArray(array2, 6)) std::cout << "array 2 is not sorted\n";
    else {
        std::cout << "array 2 is sorted\n";
    }


    return 0;
}
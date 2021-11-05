#include <iostream>
using std::cout;

int iterativeArrSum(int array[], int len);
int recursiveArrSum(int array[], int len);

int main(void){

    int arr[15] = {1,-7,4,8,-1,0,4,-6,6,10,2,4,-8,3,0};
    int arrLen = 15;
    
    cout << iterativeArrSum(arr, arrLen) << std::endl;   
    cout << recursiveArrSum(arr, arrLen); 
    return 0;
}

int iterativeArrSum(int array[], int len){
    int sum = 0;
    for (int i = 0; i < len; i++){
        if (array[i] > 0) sum += array[i];
    }
    return sum;
}

int recursiveArrSum(int array[], int len){
    int tmpSum;
    if (len > -1 ) tmpSum = recursiveArrSum(array, len - 1);
    else return 0;

    if (array[len-1] > 0) return tmpSum + array[len-1];
    else return tmpSum;
}
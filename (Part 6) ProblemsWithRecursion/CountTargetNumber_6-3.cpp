#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// This program counts the number of target number in a given array iteratively and recursively

int iterativeSolution(int arr[], int len, int targetNum);
int recursiveSolution(int arr[], int len, int targetNum);

int main(void){

    int testArr1[10] = {145,4,4,33,33,33,0,145,1,0};  
    int testArr2[10] = {1,0,0,1,1,5,6,6,1,0};
    int len = 10;

    cout << iterativeSolution(testArr1, len, 145) << endl;
    cout << iterativeSolution(testArr1, len, 3) << endl;
    cout << iterativeSolution(testArr1, len, 0) << endl;
    cout << iterativeSolution(testArr1, len, 4) << endl;
    cout << iterativeSolution(testArr2, len, 145) << endl;
    cout << iterativeSolution(testArr2, len, 0) << endl;
    cout << iterativeSolution(testArr2, len, 1) << endl;
    cout << iterativeSolution(testArr2, len, 6) << endl;

    cout << "recursive functions:\n";
    cout << recursiveSolution(testArr1, len, 145) << endl;
    cout << recursiveSolution(testArr1, len, 3) << endl;
    cout << recursiveSolution(testArr1, len, 0) << endl;
    cout << recursiveSolution(testArr1, len, 4) << endl;
cout << recursiveSolution(testArr2, len, 145) << endl;
    cout << recursiveSolution(testArr2, len, 0) << endl;
    cout << recursiveSolution(testArr2, len, 1) << endl;
    cout << recursiveSolution(testArr2, len, 6) << endl;
    return 0;
}

int iterativeSolution(int arr[], int len, int targetNum){
    int count = 0;
    for (int i = 0; i < len; i++){
        if (arr[i] == targetNum) count++;
    }
    return count;
}
int recursiveSolution(int arr[], int len, int targetNum){
    if (len == -1) return 0;
    if (len == 10) return recursiveSolution(arr, len - 1, targetNum);
    
    if (arr[len] == targetNum){
        return recursiveSolution(arr, len - 1, targetNum) + 1;
    }
    else return recursiveSolution(arr, len - 1, targetNum);
}
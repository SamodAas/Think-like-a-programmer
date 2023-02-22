// The function checks whether the array passed to it is sorted in ascending order

#include <iostream>
using std::cout;

bool isSorted(int arr[], int length){
    for (int i = 0; i < length-1;i++){
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int arrn[6] = {2,4,1,6,4,3};

    if (isSorted(arr,5)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout <<"second arr";

    if (isSorted(arrn,6)){
        cout << "yes";
    } else {
        cout << "no";
    }
}
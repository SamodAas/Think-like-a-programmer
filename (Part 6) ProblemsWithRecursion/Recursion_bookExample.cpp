#include <iostream>
using std::cout;

int sum(int array[], int len){
    if (len == 0) return 0;                     // checks for 0 value as well as ends recurcion
    return array[len-1] + sum(array, len - 1);
}
int main(void){
    
    int arr[10] = {1,1,3,1,1,1,1,1,1,1};
    int arr_length = 10;
    cout << "sum: " << sum(arr, arr_length);

    return 0;
}
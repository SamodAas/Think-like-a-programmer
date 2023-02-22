// the program processes an array of students 
// and determines the grade quartiles
#include <iostream>
using std::cout;
using std::string;

struct student{
    string name;
    int grade;
};

int compr(const void * a, const void * b){
    int * aa = (int *)(a);
    int * bb = (int *)(b);
    return *(int *)(aa) - *(int *)(bb);
}

int main() {
    student students[10] = {
        {"Tom",9},
        {"Dom",76},
        {"Aom",45},
        {"Wom",1},
        {"Eom",37},
        {"Rom",15},
        {"Tom",14},
        {"Yom",2},
        {"Ton",35},
        {"Tor",24},
    };
    int arr[10];

// considering that we only need to find the quartiles, we can just 
// use an array for all grade values to get the quartiles, without
// engaging in more complex struct processing
    for (int i = 0; i< 10; i++){
        arr[i] = students[i].grade;
    }
    qsort(arr,10,sizeof(int), compr);

    cout << "To be better than 25'%' your grade should be " << arr[3]+1;
    cout << "\nTo be better than 50'%' your grade should be " << arr[5]+1;
    cout << "\nTo be better than 75'%' your grade should be " << arr[7]+1;


}
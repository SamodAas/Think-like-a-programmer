#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


struct studentRecord {
    int studentNum;
    int grade;
};

void interpolationSort(studentRecord array[], int arLen, int target){
    
    int min = 0;
    int counter = 0;
    int max = arLen;
    int med; //middle object

    while (counter < arLen){
        med = min + (max - min) * (target - array[min].studentNum) / (array[max].studentNum - array[min].studentNum);
        if (array[med].studentNum == target) {
            cout << "Found! grade: " << array[med].grade;
            return;
        }
        if (array[med].studentNum < target) {
            min = med;
            counter++;
            continue;
        }
        if (array[med].studentNum > target) {
            max = med -1;
        }
        counter++;
    }
    cout << "Student was not found";
    return;
}
int main(void){

    studentRecord studentArray[6];
    int arLen = 5;
    studentArray[0].grade = 10;
    studentArray[0].studentNum = 100;

    studentArray[1].grade = 70;
    studentArray[1].studentNum = 101;
    
    studentArray[2].grade = 60;
    studentArray[2].studentNum = 102;
    
    studentArray[3].grade = 56;
    studentArray[3].studentNum = 103;
    
    studentArray[4].grade = 75;
    studentArray[4].studentNum = 105;

    studentArray[5].grade = 49;
    studentArray[5].studentNum = 106;

    interpolationSort(studentArray, arLen, 105);


    return 0;
}
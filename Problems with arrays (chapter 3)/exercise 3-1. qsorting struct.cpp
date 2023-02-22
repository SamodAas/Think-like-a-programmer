// sort student structure by grade. 
// *this solution creates a fragmentation error because of the string type use(why?),
// however the sorting still happens. 
#include <iostream>
#include <stdlib.h>
#include <string>
using std::cout;
using std::string;

struct studentStruct{
    string name;
    int id;
    int grade;    
};

int compare_by_grade(const void* gradeA, const void* gradeB){
    studentStruct * ga = (studentStruct *)(gradeA);
    studentStruct * gb = (studentStruct *)(gradeB);
    return (ga->grade - gb->grade);   
}
int main(){
    studentStruct students[4];
    students[1].name = "Tom";
    students[1].grade = 9;
    students[1].id = 5;
    
    students[2].name = "Adam";
    students[2].grade = 4;
    students[2].id = 4;
    
    students[3].name = "Gel";
    students[3].grade =10;
    students[3].id = 8;
    
    students[0].name = "Del";
    students[0].grade = 8;
    students[0].id = 2;
    
    qsort(students, 4,sizeof(studentStruct), compare_by_grade);

    for (int i = 0; i < 4;i++){
        cout << students[i].grade<<"\n";
    }
}
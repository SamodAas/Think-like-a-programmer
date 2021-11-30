#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;


struct studentRecord {
    int studentNum;
    int grade;
    
};


void addRecord(std::list<studentRecord> &studRec, int grade, int studNum){
    
    studentRecord stud;
    stud.grade = grade;
    stud.studentNum = studNum;
    studRec.push_front(stud);
    
    return;
}
float averageRecord(std::list<studentRecord> studRec){
     
    int sum = 0;
    int numberOfStudents = 0;
    for(std::list<studentRecord>::iterator it = studRec.begin(); it != studRec.end();it++){
        sum += it->grade;
        numberOfStudents++;}
    return (float)sum/numberOfStudents;
};


int main(void){

    studentRecord stud1;
    stud1.grade = 50;
    stud1.studentNum = 1001;
    std::list<studentRecord> studentList;
    addRecord(studentList, 44, 1001);
    addRecord(studentList, 40, 1002);
    addRecord(studentList, 74, 1003);
    addRecord(studentList, 54, 1004);

    cout << averageRecord(studentList);
    
    return 0;
}


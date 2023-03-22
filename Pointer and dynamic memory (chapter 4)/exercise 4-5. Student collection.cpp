#include <iostream>
using std::cout;
using std::string;

//student collection and its functions

struct student{
    int grade;
    int studentNumber;
    student * next;
};

typedef student* studentCollection;

void printCollection(studentCollection sc){
    student *tmp = new student;
    tmp = sc;
    while (tmp!=NULL){
        cout << "student number: " << tmp->studentNumber << "//// Grade: " << tmp->grade << "\n";
        tmp = tmp->next;
    }
    delete tmp;
}

//remove student by their student number
void removeStudent(studentCollection& sc, int studnum){
    student *tmpNode = sc;
    student *tmpNode2 = sc->next;

    // In case it is the first student
    if (sc->studentNumber == studnum){
        tmpNode = sc->next;
        delete sc;
        sc = tmpNode;
        return;
    }
    
    //in case it is the middle student
    while (tmpNode2->next!=NULL){
        if (tmpNode2->studentNumber == studnum){
            tmpNode->next = tmpNode2->next;
            delete tmpNode2;
            return;
        }
        else{
            tmpNode=tmpNode2;
            tmpNode2 = tmpNode2->next;
        }
    }

    // in case it is the last student
    if (tmpNode2->studentNumber == studnum){
        tmpNode->next = NULL;
        delete tmpNode2;
        return;
    }
}


int main(){
    studentCollection sc;
    student *student1 = new student;
    student *student2 = new student;
    student *student3 = new student;
    student1->grade =  8, student1->studentNumber=100, student1->next = student2;
    student2->grade =  9, student2->studentNumber=101, student2->next = student3;
    student3->grade =  4, student3->studentNumber=102, student3->next = NULL;
    sc = student1;
    student1 = student2 = student3 = NULL;

    // print function
    printCollection(sc);

    // Remove function
    removeStudent(sc, 102);
    printCollection(sc);

    // This code does not cover instance where there are no students in the collection

}
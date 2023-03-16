#include <iostream>
using std::cout;
using std::cin;


struct listNode{
    int studNum;
    int grade;
    listNode *next;
};
typedef listNode * studentCollection;


void addRecord(studentCollection& sc, int number, int grade){
    listNode * newNode  = new listNode;
    newNode->studNum = number;
    newNode->grade = grade;
    newNode->next = sc;
    sc = newNode;
    return;
}

double recordAverage(studentCollection sc){
    if (sc == NULL) return 0;
    
    
    listNode * loopPtr = new listNode;
    loopPtr = sc;
    double sum=0;
    int count=0;
    while (loopPtr->next!=NULL){
        sum+=loopPtr->grade;
        count++;
        loopPtr=loopPtr->next;
    }
    double avg = sum/count;
    return avg;
}

int main(){

    
    studentCollection sc;
    listNode *node1 = new listNode;
    listNode *node2 = new listNode;
    listNode *node3 = new listNode;
    node1->studNum=101;
    node1->grade = 10;
    node2->studNum=102;
    node2->grade = 8;
    node3->studNum=103;
    node3->grade = 5;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    addRecord(sc, 104, 8);
    cout<< recordAverage(sc);
}
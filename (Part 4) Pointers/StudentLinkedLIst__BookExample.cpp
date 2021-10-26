#include <iostream>
using std::cout;
using std::cin;

struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};

typedef listNode *studentCollection;

void addRecord(studentCollection &sc, int grade, int studentNum){
    listNode *node = new listNode;
    
    node->next = sc;
    node->grade = grade;
    node->studentNum = studentNum;

    sc = node;
    return;
}
float averageRecord(studentCollection &sc){
    listNode *node = new listNode;
    int sum = 0;
    int count = 0;

    node = sc;
    if (sc == NULL) return 0;
    do {
        sum += node->grade;
        count++;
        node = node->next;
    } while (node != NULL );
    return (float)sum/count;
};


int main(void){
    studentCollection sc;

    listNode *node1 = new listNode;
    node1->grade = 78; node1->studentNum = 1001;
    
    listNode *node2 = new listNode;
    node1->next = node2;
    node2->grade = 93; node2->studentNum = 1002;

    listNode *node3 = new listNode;
    node2->next = node3;
    node3->grade = 85; node3->studentNum = 1003;
    node3->next = NULL;

    sc = node1;
    node1 = node2 = node3 = NULL;

    addRecord(sc, 91, 1274);
    cout << averageRecord(sc);
    return 0;
}


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

void removeRecord(studentCollection &sc, int studentNum){
    
    listNode *previousNode = new listNode;  // node to be connected with a node which 
                                            // is currently pointed to by to be removed node

    listNode *searchNode = new listNode;    // node with which we will iterate linked list

    searchNode = sc;                                        
    previousNode = sc;
    
    while (searchNode != NULL){
        if (searchNode->studentNum == studentNum){
            if (previousNode == searchNode) {       // If the student record is the first node in the linkedlist 
                sc = sc->next;
                delete searchNode;
                return;
            }
            else if (searchNode->next == NULL){    // If the student record is the last node in the linkedlist
                previousNode->next = NULL;
                delete searchNode;
                return;
            }
            else {                                 // If the student record is the middle of the linkedlist
                previousNode->next = searchNode->next;      
                delete searchNode;
                return;
            }
            
        }
        previousNode = searchNode;
        searchNode = searchNode->next;
        
    }
}

void printList(studentCollection sc){
    
    listNode *node = new listNode;
    node = sc;
    cout << "list" << std::endl;

    while (node != NULL){
        cout <<"number: " << node->studentNum << std::endl;
        node = node->next;
    }
}

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
    printList(sc);
    addRecord(sc, 91, 1274);
    printList(sc);
    removeRecord(sc, 1001);
    printList(sc);
    return 0;
}
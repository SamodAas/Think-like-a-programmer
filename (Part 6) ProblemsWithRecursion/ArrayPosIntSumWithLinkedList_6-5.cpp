#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct linkedList{
    int number;
    linkedList *next;
};

void newNumInLinkedList(linkedList *head, int num);
void displayLinkedList(linkedList *head);
int recursivePosIntSum(linkedList *head);

int main(void){
    linkedList *numList = new linkedList();
    numList->next = NULL;
    newNumInLinkedList(numList, 12);
    newNumInLinkedList(numList, -1);
    newNumInLinkedList(numList, 115);
    newNumInLinkedList(numList, -12);
    newNumInLinkedList(numList, 135);
    newNumInLinkedList(numList, 112);
    newNumInLinkedList(numList, 111);
    newNumInLinkedList(numList, -1461);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 1);


    displayLinkedList(numList);
    cout << recursivePosIntSum(numList);
    return 0;
}

void newNumInLinkedList(linkedList *head, int num) {
                       
    linkedList *newNode = new linkedList;
    newNode->next = head->next; 
    head->next = newNode;
    newNode->number = num;        
        
}
void displayLinkedList(linkedList *head) {
    linkedList *traverseNode = new linkedList;
    traverseNode = head->next;

    while (traverseNode != NULL){
        cout << traverseNode->number<< endl;
        traverseNode = traverseNode->next;
    }
};
int recursivePosIntSum(linkedList *head) {
    if (head == NULL) return 0;
    if (head->number > 0) return recursivePosIntSum(head->next) + head->number;
    else return recursivePosIntSum(head->next);
}

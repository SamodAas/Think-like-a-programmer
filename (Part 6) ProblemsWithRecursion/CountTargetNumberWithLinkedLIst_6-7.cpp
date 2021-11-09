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
int countTargetNum(linkedList *head, int target);

int main(void){
    linkedList *numList = new linkedList();
    numList->next = NULL;
    numList->number = 2147483646;                       // If it's not given an explicit value it holds 0 as its value which would be taken into 
                                                        // account in line 34, when counting zeros in linked list. 

    newNumInLinkedList(numList, 12);
    newNumInLinkedList(numList, -1);
    newNumInLinkedList(numList, 115);
    newNumInLinkedList(numList, -1);
    newNumInLinkedList(numList, 115);
    newNumInLinkedList(numList, 115);
    newNumInLinkedList(numList, 115);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 1);

    cout << countTargetNum(numList, 0) << endl;
    cout << countTargetNum(numList, 1) << endl;
    cout << countTargetNum(numList, 115) << endl;
    cout << countTargetNum(numList, 1564) << endl;
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
}
int countTargetNum(linkedList *head, int target) {
    if (head == NULL) return 0;
    if (head->number == target) return countTargetNum(head->next, target) + 1;
    else return countTargetNum(head->next, target);
}

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
bool hasOddParity(linkedList *head);

int main(void){
    linkedList *numList = new linkedList();
    numList->next = NULL;
    newNumInLinkedList(numList, 1);
    newNumInLinkedList(numList, 1);
    newNumInLinkedList(numList, 1);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 1);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 1);
    newNumInLinkedList(numList, 0);
    newNumInLinkedList(numList, 1);
    displayLinkedList(numList);
    if (hasOddParity(numList)) cout << "odd";
    else cout << "even";
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
bool hasOddParity(linkedList *head) {
    if (head == NULL) return false;
    if (head->number == 1){
        if (hasOddParity(head->next)) return false;
        else return true;
    }
    return hasOddParity(head->next);
}

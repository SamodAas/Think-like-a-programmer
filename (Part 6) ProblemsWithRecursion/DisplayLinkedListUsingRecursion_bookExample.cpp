#include <iostream>
using std::cout;

struct linkedListNode{
    int num;
    linkedListNode *next;
};

void displayListRecursively(linkedListNode *head){
    
    cout << head->num << std::endl;
    if (head->next == NULL) return;
    displayListRecursively(head->next);
    return;
}

void displayListRecursivelyFromTail(linkedListNode *head){
    if (head == NULL) return;
    displayListRecursively(head->next);
    cout << head->num;
    return;
}
int main(void){
    linkedListNode *head = new linkedListNode;
    linkedListNode *newNode = new linkedListNode;
    head->next = newNode;
    head->num = 1;
    newNode->num = 5;
    newNode->next = NULL;

    displayListRecursively(head);
    displayListRecursivelyFromTail(head);
    return 0;
}
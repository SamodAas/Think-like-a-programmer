#include <iostream>
using std::cout;
using std::cin;

// string implementation using linkedList

// While the task is to implement simple linkedlist, considering that we want to 
// add a char at the end of the linkedlist, it would be much more efficient 
// implementing doubly linkedlist so we could just insert the letter at the end
// without having to traverse the whole list every time.

struct lString {
    char stringChar;
    lString *next;
};

void append(lString *head, char stringChar){

    if (head->stringChar == 0){                      // If the linkedlist is empty, char is inserted in the beginning of the linkedlist
        head->stringChar = stringChar;
        return;
    }

    lString *node = new lString;
    node = head;

    lString *newNode = new lString;
    newNode->stringChar = stringChar;
    newNode->next = NULL;

    while (node->next != NULL){
        node = node->next;
    }
    node->next = newNode;
    return;
}

char characterAt(lString *head, int index){
    
    lString *node = new lString;
    node = head;
    char c = 0;
    int i = 0;
    
    while (node != NULL){
        if (i == index) {
            return node->stringChar;
        }
        i++;
        node = node->next;
    }
    
    return c;
}

void printList(lString *head){
    lString *node = new lString;
    node = head;
    cout << "------String:" << std::endl;
    while (node != NULL){
        cout << node->stringChar;
        node = node->next;
    }
    cout <<"\n";
}

int main(void){

    lString *head = new lString;
    head->stringChar = 0;
    head->next = NULL;
    
    append(head, 's');
    printList(head);
    append(head, 'a');
    printList(head);
    append(head, 'b');
    printList(head);
    cout << characterAt(head, 0);
    return 0;
}
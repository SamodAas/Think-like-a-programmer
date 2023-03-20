#include <iostream>
using std::cout;

// implementation of append and char at functions

struct linkedNode{
    char c;
    linkedNode *next;
};

typedef linkedNode* head;

// append funtion

void append(linkedNode *strHead, char addedChar){
    linkedNode *tmpNode;
    tmpNode = strHead;

    while (tmpNode->next!=NULL){
        tmpNode = tmpNode->next;
    }

    linkedNode *newNode = new linkedNode;
    newNode->c = addedChar, newNode->next = NULL;
    tmpNode->next = newNode;
    return;
}

// print function

void printString(linkedNode *strHead){
    linkedNode *tmpNode = strHead;

    while (tmpNode!= NULL){
        cout << tmpNode->c;
        tmpNode = tmpNode->next;
    }
    return;
}

char charAt(linkedNode *strhead, int index){

    int i = 1;
    linkedNode *tmpNode = strhead;

    while (i < index){

        // checking if we didn't reach the end of the linkedList
        if (tmpNode == NULL){
            cout << "index out of bounds";
            return '0';
        }
        tmpNode = tmpNode->next;
        i++;
    }

    // checking in case we weren't out of bounds by just one node
    if (tmpNode == NULL){
            cout << "index out of bounds";
            return '0';
        }
    return tmpNode->c;
}


int main(){
    linkedNode *tmpNode = new linkedNode;
    tmpNode->c = 'a', tmpNode->next=NULL;
    head head;
    head = tmpNode;
    tmpNode = NULL;


    // append funtion

    append(head, 'b');
    append(head, 'c');
    append(head, 'd');

    printString(head);

    // char at function

    cout << "Char at: \n";
    cout << charAt(head, 5);
}
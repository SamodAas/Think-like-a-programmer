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

void removeChars(lString *head, int pos, int length){
    
    lString *node = new lString;
    lString *tmp = new lString;
    node = head;
    int i = 0;
    
    if (pos == 0){  
        node = node->next;                
        while (i != length - 1) {
            tmp = node;                
            node = node->next;
            head->next = node;
            
            if (node == NULL) {                    // in case length goes beyond the list
                
                head->stringChar = 0;
                head->next == NULL;
                return;
            }
            
            delete tmp;
            i++;
        }
        head->next = node->next;
        head->stringChar = node->stringChar;
        return;
    }

    while (i != pos - 1) {
        node = node->next;
        i++;
        if (node->next == NULL) {
            cout << "position out of bounds\n";
            return;
        } // in case pos goes beyond the list;

    }
    
    i = 0;

    while (i != length){
        tmp = node->next;
        // cout << tmp->stringChar << " to be deleted when i = " << i << std::endl; -------------------------works instead of comment
        node->next = tmp->next;
        delete tmp;
        i++;
        if (node->next == NULL) break; // in case length goes beyond the list;
    }
    return;
}

int main(void){

    // First string
    lString *head = new lString;
    head->stringChar = 0;
    head->next = NULL;
    
    append(head, 's');
    append(head, 'a');
    append(head, 'b');
    append(head, 'e');
    append(head, 'r');  
    append(head, ' ');
    append(head, 'y');
    append(head, 'r');
    append(head, 'a');
    append(head, ' ');
    append(head, 'k');
    append(head, 'i');
    append(head, 'e');
    append(head, 't');
    append(head, 'a');
    append(head, 's');
    append(head, '.');

    printList(head);
    removeChars(head, 0, 3);
    printList(head);
    return 0;
}
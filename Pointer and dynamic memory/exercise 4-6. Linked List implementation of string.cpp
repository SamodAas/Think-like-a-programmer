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
            cout << "index out of bounds\n";
            return '0';
        }
    return tmpNode->c;
}

// Concatenate function where the last of s1 is not just pointing to the beginning of s2

void concatenate(linkedNode *str1, linkedNode *str2){
    linkedNode* tmpNode = str2;

    while (tmpNode!=NULL){
        append(str1, tmpNode->c);
        tmpNode=tmpNode->next;
    }
    tmpNode = NULL;
    return;
}

// remove length amount of chars starting at start

void removeChars(linkedNode *head, int start, int length){
    linkedNode *tmpNode = head;
    linkedNode *tmpNode2;
    linkedNode *tmpNode3;
    int counter = 1;

    // case of start being the first char

    if (start == 1){
        while (counter<=length)
        {
            tmpNode2 = tmpNode;
            tmpNode = tmpNode->next;
            delete tmpNode2;
            counter++;
        }
        return;
    }

    // other cases

    while (counter < start-1)
    {   
        if (tmpNode==NULL){
            cout << "starting index out of bounds";
            return;
        }
        
        tmpNode=tmpNode->next;
        
        counter++;   
    }

    tmpNode2 = tmpNode->next;

    for (int i = 0; i < length;i++){
        
        if (tmpNode2 == NULL){
            cout << "Length is out of bounds";
            return;
        }

        tmpNode3 = tmpNode2;
        tmpNode2 = tmpNode2->next;
        delete tmpNode3;
    }
    tmpNode->next = tmpNode2;
    
}

int main(){
    linkedNode *tmpNode = new linkedNode;
    tmpNode->c = 'a', tmpNode->next=NULL;
    head head1;
    head1 = tmpNode;
    tmpNode = NULL;
    delete tmpNode;


    // append funtion

    append(head1, 'b');
    append(head1, 'c');
    append(head1, 'd');

    cout << "Printing string: \n";
    printString(head1);


    // char at function

    cout << "\n\nChar at: \n";
    cout << charAt(head1, 3);


    // concatenate function

    head secondHead;
    linkedNode *tmpNode2 = new linkedNode;
    tmpNode2->c = 'z';
    tmpNode2->next=NULL;
    secondHead = tmpNode2;
    tmpNode2 = NULL;
    append(secondHead, 'y');
    append(secondHead, 'k');
    append(secondHead, 'e');

    concatenate(head1, secondHead);
    cout << "\nconcatenated string:\n";
    printString(head1);

    
    // remove chars function

    cout << "\nString before removal: ";
    printString(head1);
    removeChars(head1,3,3);
    cout << "\nString after removal: ";
    printString(head1);
}
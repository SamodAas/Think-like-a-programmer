#include <iostream>
using std::cout;


struct node{
    int dig;
    node *next;
};

typedef node* head;

node *intToList(int number){
    // as advised in the exercise's definition the digits from the
    // int number are added backwards - from the end to beginning
    node *newNode = new node;
    newNode->next = NULL;

    int tmpDigit;

    tmpDigit = number%10;
    number = (number-tmpDigit)/10;
    newNode->dig = tmpDigit;

    
    while (number>=1){
        //extracting digit
        tmpDigit = number%10;
        number = (number-tmpDigit)/10;
        
        // creating new node to store the extracted digit
        node *tmpNode = new node;
        tmpNode->next = newNode;
        tmpNode->dig = tmpDigit;
        newNode = tmpNode;

    }

    return newNode;
}

void printLinkedList(node *head){
    node *tmpNode = head;

    while (tmpNode!= NULL){
        cout << tmpNode->dig;
        tmpNode = tmpNode->next;
    }
    return;
}


int main(){
    int number = 12378;
    head hd;
    hd = intToList(number);

    printLinkedList(hd);
}
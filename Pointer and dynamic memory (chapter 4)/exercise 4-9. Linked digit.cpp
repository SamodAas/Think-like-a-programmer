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

    //extracting digit

    int tmpDigit;

    tmpDigit = number%10;
    number = (number-tmpDigit)/10;
    newNode->dig = tmpDigit;

    
    while (number>=1){
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

int listToInt(node *head){
    node *tmpNode;
    tmpNode = head;
    int number = 0;

    while (tmpNode!=NULL){
        number+=tmpNode->dig;
        number*=10;
        tmpNode = tmpNode->next;
    }

    // after joining the last digit to the number the loop multiplies 
    // the number by 10
    
    return number/10;
}

int digitListsSum(node *head, node *secondDigitList){
    int sum;
    return sum = listToInt(head) + listToInt(secondDigitList);
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


    // sum of two digit linked lists

    head hd2;
    hd2 = intToList(147);
    cout << std::endl;
    printLinkedList(hd2);
    
    cout << "\nsum of two above written numbers is " << digitListsSum(hd, hd2);

}
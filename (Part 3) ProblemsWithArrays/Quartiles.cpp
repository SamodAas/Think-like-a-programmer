#include <iostream>
using std::cout;
using std::cin;
using std::string;

// This program sorts students by grade and prints what grade should
// a student get to be better than 25%, 50%, and 75% quartiles.

struct student {
    int grade;
    int id;
    string name;
};

int compareFunc(const void *voidA, const void *voidB){
    return ((student*)voidA)->grade > ((student*)voidB)->grade? 1: -1;
}
int main(void){
    const int ARRAY_SIZE = 12;
    student studentArray[ARRAY_SIZE] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"},
    {59, 10011, "Adam"},
    {94, 10012, "Tom"}
    };
    std::qsort(studentArray, 12, sizeof(student), compareFunc);
    
    cout << "To be better than 25\% student must score " << studentArray[2].grade + 1 << " points.\n";
    cout << "To be better than 50\% student must score " << studentArray[5].grade + 1 << " points.\n";
    cout << "To be better than 75\% student must score " << studentArray[8].grade + 1 << " points.\n";
    return 0;
}
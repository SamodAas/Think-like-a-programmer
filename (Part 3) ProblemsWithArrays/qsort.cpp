#include <iostream>
using std::cin;
using std::cout;
using std::string;

// qsort implemented to sort student array by student grade.
const int ARRAY_SIZE = 10;

struct student{
    int grade;
    int id;
    string name;
};

int compareFunc(const void* voidA, const void* voidB){
    return ((student*)voidA)->grade >((student *)voidB)->grade? 1 : -1;
}
int main(void){
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
    {68, 10010, "Veronica"}
    };
    cout << "Unsorted:\n"; 
    for (int i = 0; i < ARRAY_SIZE; i++){
        cout << studentArray[i].grade << " id: " << studentArray[i].id << "; name: " << studentArray[i].name << std::endl;
    }
    std::qsort(studentArray, ARRAY_SIZE, sizeof(student), compareFunc);
    cout << "Sorted by id:\n"; 
    for (int i = 0; i < ARRAY_SIZE; i++){
        cout << studentArray[i].grade << " id: " << studentArray[i].id << "; name: " << studentArray[i].name << std::endl;
    }
    
    return 0;
}
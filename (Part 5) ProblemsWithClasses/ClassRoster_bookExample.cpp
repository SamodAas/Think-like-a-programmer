#include <iostream>
#include <regex>
using std::cout;
using std::cin;
using std::string;


class studentRecord{
public:
    studentRecord();
    studentRecord(string newName, int newId, int newGrade);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    string name();
    void setName(string newName);
    string letterGrade();

    
private:
    string _studName;
    int _studId;
    int _finalScore;
};
class studentCollection{
private:
    struct studentNode{
        studentRecord studentData;
        studentNode *next;
    };
public:
    studentCollection();
    ~studentCollection();
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int IDnum);
    void removeRecord(int Idnum);
private:
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &p);
};

studentRecord::studentRecord(string newName, int newGrade, int newId) {
    setGrade(newGrade);
    setName(newName);
    setStudentID(newId);
}
studentRecord::studentRecord(){
    setGrade(0);
    setName("");
    setStudentID(-1);
}
int studentRecord::grade() {
    return _finalScore;
}
void studentRecord::setGrade(int newGrade) {
    if (newGrade >= 0 && newGrade <= 100) _finalScore = newGrade;       // Grade validation
    else cout << "invalid grade" << std::endl;
}
string studentRecord::name() {
    return _studName;
}
void studentRecord::setName(string newName) {
    std::regex validation("[A-Za-z]");
    if (regex_match(newName, validation)) _studName = newName;          // Name validation
}
int studentRecord::studentID() {
    return _studId;
}
void studentRecord::setStudentID(int newId) {
    _studId = newId;
}
string studentRecord::letterGrade() {
    const int CATEGORYNUMBER = 11;
    const int GRADEARRAY[CATEGORYNUMBER] = {0,60,67,70,73,77,80,83,87,90,93};
    const string LETTERARRAY[CATEGORYNUMBER] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    for (int i = 0; i < CATEGORYNUMBER; i++){
        if (_finalScore >= GRADEARRAY[i] && _finalScore < GRADEARRAY[i+1]) return LETTERARRAY[i];
    }
    return "ERROR";
}

studentCollection::studentCollection(){
    _listHead = NULL;
}
studentCollection::~studentCollection(){
    deleteList(_listHead);
}
void studentCollection::addRecord(studentRecord newStudent){
    studentNode *newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}
studentRecord studentCollection::recordWithNumber(int idNum){
    studentNode *traverseNode = new studentNode;
    traverseNode = _listHead;
    if (_listHead == NULL){
        studentRecord dummy;
        return dummy;
    }
    while (traverseNode != NULL) {
        if (traverseNode->studentData.studentID() == idNum) {
            return traverseNode->studentData;
        }
        traverseNode = traverseNode->next;
    }
    studentRecord dummy;
    return dummy;
}
void studentCollection::removeRecord(int idNum){
    studentNode *traverseNode = new studentNode;
    traverseNode = _listHead;

    if (traverseNode->studentData.studentID() == idNum){                // handling the first record being the sought one.
        _listHead = _listHead->next;
        delete traverseNode;
        return;
    }

    studentNode *previousNode = new studentNode;
    previousNode = NULL;
        
    while (traverseNode != NULL){
        if (traverseNode->studentData.studentID() == idNum){
            previousNode->next = traverseNode->next;
            delete traverseNode;
            return;
        }
        previousNode = traverseNode;
        traverseNode = traverseNode->next;
    }
}
void studentCollection::deleteList(studentList &p){

    studentNode *tmp = new studentNode;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
}


int main(void){

    studentCollection s;
    studentRecord stu3("Sue", 84, 1152);
    studentRecord stu2("Ed", 75, 4875);
    studentRecord stu1( "Todd", 98, 2938);
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.removeRecord(4875);
   


    return 0;
}


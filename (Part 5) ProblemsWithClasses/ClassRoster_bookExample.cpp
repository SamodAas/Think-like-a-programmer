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


int studentRecord::grade() {
    return _finalScore;
}
void studentRecord::setGrade(int newGrade) {
    if (newGrade >= 0 && newGrade <= 100) _finalScore = newGrade;       // Grade validation
    else cout << "invalid number" << std::endl;
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

studentRecord::studentRecord(string newName, int newId, int newGrade) {
    setGrade(newGrade);
    setName(newName);
    setStudentID(newId);
}
studentRecord::studentRecord(){
    setGrade(0);
    setName("");
    setStudentID(-1);
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




int main(void){

    studentRecord student1("Tomas Kazelis", 1001, 78);
    cout << student1.grade() <<std::endl;
    cout << student1.letterGrade();


    return 0;
}


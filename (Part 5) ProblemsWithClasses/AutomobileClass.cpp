#include <ctime>
#include <iostream>
#include <string>
using std::cout;
using std::string;

class automobile{
public:
    automobile(string getManufacturer, string model, int year);                                   // Constructor
    
    void setManufacturer(string newManufacturer);                                                 // Get Set functions
    string getManufacturer();
    void setModel(string newModel);
    string getModel();
    void setYear(int newYear);
    int getYear();
                                        
    string getFullInfo();                                                                       // Support functions
    int getCarsAge();
private:
    string _manufacturer;
    string _model;
    int _year;
};

// Constructor
automobile::automobile(string manufacturer, string model, int year){
    setManufacturer(manufacturer);
    setModel(model);
    setYear(year);
}
// Get Set functions
void automobile::setManufacturer(string newManufacturer){
    _manufacturer = newManufacturer;
}
string automobile::getManufacturer(){
    return _manufacturer;
}
void automobile::setModel(string newModel){
    _model = newModel;
}
string automobile::getModel(){
    return _model;
}
void automobile::setYear(int newYear){
    _year = newYear;
}
int automobile::getYear(){
    return _year;
}
// Support functions
string automobile::getFullInfo(){                                           // Gets string composed of all data members of a class
    string year = std::to_string(_year);
    string carInfo = _manufacturer + " " + _model + " " + year + "\n";
    return carInfo;
}
int automobile::getCarsAge(){
    // std::time gets time passed since the epoch
    // localtime stores that time into time pointer
    std::time_t time = std::time(NULL);
    tm* timeP = localtime(&time);

    int age =  timeP->tm_year + 1900 - _year;
    return age;
}
int main(void){

    automobile car1("Toyota", "Yaris", 2006);
    cout << car1.getFullInfo();
    cout << "Cars age: " << car1.getCarsAge();

    return 0;
}
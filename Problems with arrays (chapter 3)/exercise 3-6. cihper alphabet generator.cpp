// this program randomly generates alphabet for substitution cipher
// the constraints are: no letters repeat and no letters in their real places

#include <iostream>
#include <random>
#include <functional>
using std::cout;
using std::string;

int main(){
    const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipher = "000000000000000000000000000";

    std::default_random_engine generator;
    std::uniform_int_distribution<int>distribution(0,25);
    auto index = std::bind(distribution, generator);
    
    for (int i = 0; i <26;i++){
        while (true){
            int place = index();
            if (place != i && cipher[place] == '0'){
                cipher[place] = ALPHABET[i];
                cout << "letter " << ALPHABET[i]<<" has been placed in " << place<<"th place";
                cout << ". Current cipher: " << cipher<<"\n";
                break;
            }
        }
    }
    cout << "final cipher: " << cipher;
    
}
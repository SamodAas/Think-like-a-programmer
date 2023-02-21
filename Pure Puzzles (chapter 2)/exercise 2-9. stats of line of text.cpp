#include <iostream>
using std::cout;
using std::string;

int main(){
    string text;
    string word;
    int text_len;
    int length_of__the_longest_word = 0;
    int number_of_words = 0;
    int num_of_vowels = 0;
    int most_vowels = 0;
    

    cout << "enter a line of text: ";
    std::getline(std::cin >> std::ws, text);
    text_len = text.size();

    for (int i = 0; i <= text_len; i++){
        if (text[i] == '!' || text[i] == '?' || text[i] == '.' || text[i] == ',' || text[i] == ' '|| text[i] == 0) {
            if (word.size() > length_of__the_longest_word) length_of__the_longest_word = word.size();
            
            if (text[i+1]!=' '){number_of_words++;}

            if (num_of_vowels > most_vowels) most_vowels = num_of_vowels;

            num_of_vowels = 0;
            word = "";
            continue;
        }
        word+=text[i];
        if  (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') num_of_vowels++;
        
    }
    cout << "stats: \nnumber of words: "<<number_of_words<<"\nlength of the longest word: "<<length_of__the_longest_word<<"\nmost vowels in a word: "<<most_vowels;
}
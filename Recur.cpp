#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
void WordChecker(vector<string> word,vector<char> letter,int num, int base);
bool letterChecker(string words, vector<char>letter);

int main(){

vector<string>word;
vector<char>letter;
ifstream afile;
string line;
afile.open("boggleBoard.txt");

int n = 0;
int m = 0;
int lineCount = 0;
int base = 0;

if(!afile){
    cout << "Failed to open\n";
}
getline(afile, line); //gets First number 
n = stoi(line);
cout << n << endl;

while (lineCount < n && getline(afile,line)){
    cout << line << endl;
    for(char c : line){
        if(c != ' '){
            letter.push_back(c);
        }
    }
    ++lineCount;
}

getline(afile, line); // gets second number
m = stoi(line);

while (getline(afile, line)){
    cout << line << endl;
    word.push_back(line);
}

cout << "start of wordChecker" << endl;
WordChecker(word, letter, m, base);

return 0;
}

bool letterChecker(string words, vector<char> letter){
    int v = 0;
    int w = words.length();
    string charToString;

    for (char s : letter) { 
        charToString.push_back(s); 
    } 
    
    for(int i = 0; i < words.length(); i++){
        for(int u =0; u < charToString.length(); u++){
            if(words.at(i) == charToString.at(u)){
                v++;
                break;
            }
         }       
    }
    if(v >= w){
        return v == w; 
    }
    else {
        return v == w;
    }   
}

void WordChecker(vector<string> word,vector<char> letter,int num, int base){
    string words;
    int n = base;
    if(base == num){
            return;
    }
    
    while(n != num){
        words = word[n];
        bool aWord;
     //   letterChecker(words, letter);
        if(letterChecker(words,letter)){
            cout << "Word " << base + 1 << ": " << "Yes" << endl;
            ++n;
            return WordChecker(word, letter, num, n);
        }
        else{
            cout << "Word " << base + 1 << ": " << "No" << endl;
            ++n;
            return WordChecker(word,letter, num, n);
        }

    }  
}
  


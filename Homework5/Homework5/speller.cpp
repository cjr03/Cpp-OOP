//
//  speller.cpp
//  Homework5
//
//  Created by Cole Roberts on 2/7/25.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cctype>

using namespace std;

void printWords(vector<string> newWords){
    cout << "The first 20 unique words are:\n";
    for(int i = 0; i < 30; ++i){
        cout << "-";
    }
    cout << "\n";
    for (auto const & word : newWords) {
        cout << "\t   " << word << "\n";
    }
    for(int i = 0; i < 30; ++i){
        cout << "-";
    }
    cout << endl;
}

string processWord(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int last = word.size() - 1;
    while (last >= 0 && !isalpha(word[last])) {
        last--;
    }
    if (last < 0) {
        return "";
    } else {
        return word.substr(0, last + 1);
    }
}

vector<string> validWords(ifstream & dictFile){
    vector<string> valid;
    string line;
    while (getline(dictFile, line)) {
        string processedLine = processWord(line);
        if (!processedLine.empty()) {
            valid.push_back(processedLine);
        }
    }
    dictFile.close();
    return valid;
}

vector<string> newWords(ifstream & inputFile, vector<string> valid){
    vector<string> misspelled;
    string word;
    while (inputFile >> word && misspelled.size() < 20) {
        string processed = processWord(word);
        if (processed.empty()) {
            continue;
        }
        for(auto const & v : valid){
            if(processed == v){
                bool found = false;
                for(auto const & mis : misspelled){
                    if(processed == mis){
                        found = true;
                    }
                }
                if(!found){
                    misspelled.push_back(processed);
                }
            }
        }
    }
    inputFile.close();
    return misspelled;
}

bool invalidFiles(int argc, char* argv[], ifstream & dictFile, ifstream & inputFile){
    if(argc != 3){
        cerr << "Enter a valid dictionary and input file name." << endl;
        return true;
    }

    dictFile.open(argv[1]);
    if (!dictFile) {
        cerr << "Error opening dictionary file." << endl;
        return true;
    }
    inputFile.open(argv[2]);
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    ifstream dictFile, inputFile;
    if(invalidFiles(argc, argv, dictFile, inputFile)){
        return 1;
    }
    printWords(newWords(inputFile, validWords(dictFile)));
    return 0;
}
